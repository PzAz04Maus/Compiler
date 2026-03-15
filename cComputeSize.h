#pragma once

#include "cVisitor.h"

#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "cArgsNode.h"
#include "cArrayDeclNode.h"
#include "cBlockNode.h"
#include "cDeclsNode.h"
#include "cFuncDeclNode.h"
#include "cFuncCallNode.h"
#include "cParamsNode.h"
#include "cStructDeclNode.h"
#include "cSymbol.h"
#include "cVarDeclNode.h"
#include "cVarRefNode.h"

// Lab 6: compute sizes and offsets for variables, blocks, functions, and struct
// layouts. Results are emitted as XML attributes via cAstNode's computed
// attribute support.

class cComputeSize : public cVisitor
{
public:
    cComputeSize() = default;

    void Visit(cBlockNode *node) override
    {
        if (node == nullptr) return;

        // Determine the base offset for this block:
        // - if we're inside another locals frame, allocate after its decls
        // - otherwise start at 0 (program/global)
        int parentCurrent = CurrentLocalsOffsetOrZero();

        PushLocalsFrame(parentCurrent);

        // Process decls first (allocates offsets).
        if (node->GetDecls() != nullptr) node->GetDecls()->Visit(this);

        // Visit statements; nested blocks will allocate after decls, but do not
        // permanently increase the parent's current offset.
        if (node->GetStmts() != nullptr) node->GetStmts()->Visit(this);

        int blockSize = PopLocalsFrameAndGetSize();
        if (blockSize > 0) node->SetComputedAttribute("size", blockSize);
    }

    void Visit(cDeclsNode *node) override
    {
        if (node == nullptr) return;

        int before = CurrentAllocOffset();
        cVisitor::Visit(node);
        int after = CurrentAllocOffset();

        int declsSize = after - before;
        if (declsSize > 0) node->SetComputedAttribute("size", declsSize);
    }

    void Visit(cVarDeclNode *node) override
    {
        if (node == nullptr) return;

        // Still visit children (type/name syms) so output remains unchanged.
        cVisitor::Visit(node);

        cSymbol *typeSym = node->GetTypeSym();
        if (typeSym == nullptr) return;

        TypeInfo t = GetTypeInfo(typeSym);
        if (t.size <= 0) return;

        switch (CurrentAllocKind())
        {
            case AllocKind::Args:
            {
                // Parameters live in word-sized stack slots.
                // Extra credit (Lab7): arrays are passed by reference (a single word
                // holding the base address), not copied onto the stack.
                int passSize = t.size;
                if (typeSym->GetDecl() != nullptr && typeSym->GetDecl()->IsArray())
                {
                    passSize = kWordSize;
                    node->SetComputedAttribute("byref", 1);
                }

                int slot = RoundUp(std::max(passSize, 1), kWordSize);
                int offset = m_argsTopOffset;
                node->SetComputedAttribute("size", passSize);
                node->SetComputedAttribute("offset", offset);
                m_declSize[node] = passSize;
                m_declOffset[node] = offset;
                m_argsTopOffset -= slot;
                m_argsTotalSize += slot;
                break;
            }
            case AllocKind::Locals:
            case AllocKind::StructFields:
            {
                int &cur = CurrentFrame().current;
                cur = AlignUp(cur, std::max(t.align, 1));

                node->SetComputedAttribute("size", t.size);
                node->SetComputedAttribute("offset", cur);
                m_declSize[node] = t.size;
                m_declOffset[node] = cur;

                cur += t.size;
                CurrentFrame().max = std::max(CurrentFrame().max, cur);

                if (CurrentAllocKind() == AllocKind::StructFields)
                {
                    m_structMaxAlign = std::max(m_structMaxAlign, std::max(t.align, 1));
                }

                break;
            }
            default:
                // Decls outside an allocation context don't get offsets.
                break;
        }
    }

    void Visit(cArgsNode *node) override
    {
        if (node == nullptr) return;

        // Layout for args is independent of locals. Offsets are negative.
        AllocKind prev = m_allocKind;
        m_allocKind = AllocKind::Args;

        int prevTop = m_argsTopOffset;
        int prevTotal = m_argsTotalSize;
        m_argsTopOffset = kFirstArgTopOffset;
        m_argsTotalSize = 0;

        cVisitor::Visit(node);

        if (m_argsTotalSize > 0) node->SetComputedAttribute("size", m_argsTotalSize);

        // Restore.
        m_argsTopOffset = prevTop;
        m_argsTotalSize = prevTotal;
        m_allocKind = prev;
    }

    void Visit(cFuncDeclNode *node) override
    {
        if (node == nullptr) return;

        // Compute arg layout first (if present).
        if (node->GetArgsNode() != nullptr)
        {
            node->GetArgsNode()->Visit(this);
        }

        // Only functions with definitions have a local frame.
        if (!node->HasDefinition())
        {
            // Still visit children for varrefs inside prototypes (rare).
            cVisitor::Visit(node);
            return;
        }

        // Locals frame starts at offset 0 and should not affect any outer
        // allocation frame.
        PushLocalsFrame(0, false);

        if (node->GetDeclsNode() != nullptr) node->GetDeclsNode()->Visit(this);
        if (node->GetStmtsNode() != nullptr) node->GetStmtsNode()->Visit(this);

        int funcSize = PopLocalsFrameAndGetSize();
        funcSize = RoundUp(funcSize, kWordSize);
        if (funcSize > 0)
        {
            node->SetComputedAttribute("size", funcSize);
            node->SetComputedAttribute("offset", 0);
        }
    }

    void Visit(cStructDeclNode *node) override
    {
        if (node == nullptr) return;

        // Lay out fields starting at offset 0.
        AllocKind prev = m_allocKind;
        m_allocKind = AllocKind::StructFields;

        int prevStructAlign = m_structMaxAlign;
        m_structMaxAlign = 1;

        PushLocalsFrame(0, false);
        if (node->GetFields() != nullptr) node->GetFields()->Visit(this);
        int structSize = PopLocalsFrameAndGetSize();

        m_typeSize[node] = structSize;
        m_typeAlign[node] = std::max(m_structMaxAlign, 1);

        node->SetComputedAttribute("size", structSize);
        node->SetComputedAttribute("offset", 0);

        m_structMaxAlign = prevStructAlign;

        m_allocKind = prev;
    }

    void Visit(cVarRefNode *node) override
    {
        if (node == nullptr) return;

        // Annotate, then traverse children normally.
        AnnotateVarRef(node);
        cVisitor::Visit(node);
    }

    void Visit(cFuncCallNode *node) override
    {
        if (node == nullptr) return;

        // params size in expected output corresponds to the return type size.
        cParamsNode *params = node->GetParamsNode();
        if (params != nullptr)
        {
            int retSize = GetReturnSize(node);
            if (retSize > 0) params->SetComputedAttribute("size", retSize);
        }

        cVisitor::Visit(node);
    }

private:
    static constexpr int kWordSize = 4;
    static constexpr int kFirstArgTopOffset = -12;

    enum class AllocKind
    {
        None,
        Locals,
        StructFields,
        Args,
    };

    struct Frame
    {
        int base = 0;    // absolute starting offset for this scope
        int current = 0; // current allocation position (absolute)
        int max = 0;     // max position reached (absolute)
        bool propagateMaxToParent = true;
    };

    struct TypeInfo
    {
        int size = 0;
        int align = 1;
        const cDeclNode *decl = nullptr;
    };

    AllocKind m_allocKind = AllocKind::None;
    std::vector<Frame> m_frames;

    // For args (temporary during Visit(cArgsNode*) traversal)
    int m_argsTopOffset = kFirstArgTopOffset;
    int m_argsTotalSize = 0;

    // For struct field layout.
    int m_structMaxAlign = 1;

    // Computed info caches.
    std::unordered_map<const cDeclNode*, int> m_typeSize;
    std::unordered_map<const cDeclNode*, int> m_typeAlign;
    std::unordered_map<const cDeclNode*, int> m_declSize;
    std::unordered_map<const cDeclNode*, int> m_declOffset;

    AllocKind CurrentAllocKind() const { return m_allocKind; }

    Frame &CurrentFrame() { return m_frames.back(); }
    const Frame &CurrentFrame() const { return m_frames.back(); }

    int CurrentLocalsOffsetOrZero() const
    {
        if (m_frames.empty()) return 0;
        // Nested blocks allocate after the parent's decls, i.e., at parent's
        // current offset.
        return m_frames.back().current;
    }

    int CurrentAllocOffset() const
    {
        if (m_frames.empty()) return 0;
        return m_frames.back().current;
    }

    void PushLocalsFrame(int start, bool propagateMaxToParent = true)
    {
        Frame f;
        f.base = start;
        f.current = start;
        f.max = start;
        f.propagateMaxToParent = propagateMaxToParent;
        m_frames.push_back(f);

        // Entering a block or function locals layout.
        if (m_allocKind == AllocKind::None) m_allocKind = AllocKind::Locals;
    }

    int PopLocalsFrameAndGetSize()
    {
        if (m_frames.empty()) return 0;

        Frame f = m_frames.back();
        m_frames.pop_back();

        int size = f.max - f.base;

        // Propagate max usage to parent frame only when this frame represents
        // a nested block that shares the parent's allocation area.
        if (!m_frames.empty())
        {
            if (f.propagateMaxToParent)
            {
                m_frames.back().max = std::max(m_frames.back().max, f.max);
            }
        }
        else
        {
            m_allocKind = AllocKind::None;
        }

        return size;
    }

    static int RoundUp(int value, int multiple)
    {
        if (multiple <= 0) return value;
        int rem = value % multiple;
        if (rem == 0) return value;
        return value + (multiple - rem);
    }

    static int AlignUp(int offset, int align)
    {
        if (align <= 1) return offset;
        int rem = offset % align;
        if (rem == 0) return offset;
        return offset + (align - rem);
    }

    TypeInfo GetTypeInfo(cSymbol *typeSym)
    {
        TypeInfo info;
        if (typeSym == nullptr) return info;

        cDeclNode *decl = typeSym->GetDecl();
        info.decl = decl;
        if (decl == nullptr) return info;

        auto labAlign = [](int size) -> int {
            // Lab 6 rule: 4-byte alignment for anything with size > 1.
            return (size <= 1) ? 1 : kWordSize;
        };

        // Primitive types (base types are the only decls with non-zero GetSize()).
        if (decl->IsType() && !decl->IsArray() && !decl->IsStruct() && decl->GetSize() > 0)
        {
            info.size = decl->GetSize();
            info.align = labAlign(info.size);
            return info;
        }

        // Array types.
        if (decl->IsArray())
        {
            auto *arr = dynamic_cast<cArrayDeclNode*>(decl);
            if (arr == nullptr) return info;

            cSymbol *base = arr->GetBaseTypeSym();
            TypeInfo baseInfo = GetTypeInfo(base);
            info.size = baseInfo.size * arr->GetCount();
            info.align = labAlign(info.size);
            return info;
        }

        // Struct types.
        if (decl->IsStruct())
        {
            auto itS = m_typeSize.find(decl);
            if (itS == m_typeSize.end())
            {
                // Force computation by visiting the struct decl node itself.
                if (auto *sd = dynamic_cast<cStructDeclNode*>(decl)) sd->Visit(this);
            }
            info.size = m_typeSize.count(decl) ? m_typeSize[decl] : 0;
            info.align = labAlign(info.size);
            return info;
        }

        // Fallback: unknown types treated as 0.
        return info;
    }

    int GetReturnSize(cFuncCallNode *call)
    {
        if (call == nullptr) return 0;

        cDeclNode *retDecl = call->GetType();
        if (retDecl == nullptr) return 0;

        // Base types.
        if (!retDecl->IsArray() && !retDecl->IsStruct() && retDecl->GetSize() > 0)
            return retDecl->GetSize();

        // Struct return.
        if (retDecl->IsStruct())
        {
            if (m_typeSize.find(retDecl) == m_typeSize.end())
            {
                if (auto *sd = dynamic_cast<cStructDeclNode*>(retDecl)) sd->Visit(this);
            }
            return m_typeSize.count(retDecl) ? m_typeSize[retDecl] : 0;
        }

        // Array return (unlikely, but supported).
        if (retDecl->IsArray())
        {
            auto *arr = dynamic_cast<cArrayDeclNode*>(retDecl);
            if (arr == nullptr) return 0;
            TypeInfo baseInfo = GetTypeInfo(arr->GetBaseTypeSym());
            return baseInfo.size * arr->GetCount();
        }

        return 0;
    }

    // Helpers for array rowsizes attribute.
    std::vector<int> GetRowSizes(cDeclNode *typeDecl, int numIndices)
    {
        std::vector<int> sizes;
        if (typeDecl == nullptr || numIndices <= 0) return sizes;

        cDeclNode *cur = typeDecl;
        while (cur != nullptr && cur->IsArray() && (int)sizes.size() < numIndices)
        {
            auto *arr = dynamic_cast<cArrayDeclNode*>(cur);
            if (arr == nullptr) break;
            cSymbol *baseSym = arr->GetBaseTypeSym();
            TypeInfo baseInfo = GetTypeInfo(baseSym);
            sizes.push_back(baseInfo.size);
            cur = (baseSym != nullptr) ? baseSym->GetDecl() : nullptr;
        }
        return sizes;
    }

    static std::string JoinRowSizes(const std::vector<int> &sizes)
    {
        std::ostringstream oss;
        for (size_t i = 0; i < sizes.size(); i++)
        {
            if (i) oss << ' ';
            oss << sizes[i];
        }
        return oss.str();
    }

    void AnnotateVarRef(cVarRefNode *node)
    {
        cSymbol *baseSym = node->GetBaseSymbol();
        if (baseSym == nullptr || baseSym->GetDecl() == nullptr) return;

        // Base must be a variable declaration.
        auto *baseVar = dynamic_cast<cVarDeclNode*>(baseSym->GetDecl());
        if (baseVar == nullptr) return;

        cSymbol *typeSym = baseVar->GetTypeSym();
        if (typeSym == nullptr || typeSym->GetDecl() == nullptr) return;

        TypeInfo curType = GetTypeInfo(typeSym);
        int curOffset = m_declOffset.count(baseVar) ? m_declOffset[baseVar] : 0;

        // Walk additional parts: either symbols (fields) or expressions (indices).
        int numIndices = 0;
        for (int i = 1; i < node->NumParts(); i++)
        {
            cAstNode *part = node->GetPart(i);
            if (dynamic_cast<cExprNode*>(part) != nullptr)
            {
                numIndices++;
                continue;
            }

            cSymbol *fieldSym = dynamic_cast<cSymbol*>(part);
            if (fieldSym == nullptr) continue;

            // Field access: current type must be struct.
            cDeclNode *typeDecl = typeSym->GetDecl();
            auto *structDecl = dynamic_cast<cStructDeclNode*>(typeDecl);
            if (structDecl == nullptr)
            {
                // Try if curType.decl is struct decl.
                structDecl = dynamic_cast<cStructDeclNode*>(const_cast<cDeclNode*>(curType.decl));
            }
            if (structDecl == nullptr) return;

            // Ensure struct layout computed.
            structDecl->Visit(this);

            // Find the field declaration symbol by name in the struct fields.
            // We rely on the symbol in the varref already being the resolved
            // symbol whose decl is the field var_decl.
            auto *fieldVar = dynamic_cast<cVarDeclNode*>(fieldSym->GetDecl());
            if (fieldVar == nullptr)
            {
                // If the lexer created a fresh symbol, fall back to lookup in
                // the struct's fields by name.
                fieldVar = FindStructField(structDecl, fieldSym->GetName());
                if (fieldVar == nullptr) return;
            }

            // Add field offset and update current type.
            int fieldOff = m_declOffset.count(fieldVar) ? m_declOffset[fieldVar] : 0;
            curOffset += fieldOff;

            typeSym = fieldVar->GetTypeSym();
            if (typeSym == nullptr) return;
            curType = GetTypeInfo(typeSym);
        }

        // Base size/offset.
        node->SetComputedAttribute("size", curType.size);
        node->SetComputedAttribute("offset", curOffset);

        if (numIndices > 0)
        {
            // For array indexing, the varref prints the full array size and the
            // base offset, plus a rowsizes list for each dimension indexed.
            cDeclNode *typeDecl = typeSym->GetDecl();
            std::vector<int> rows = GetRowSizes(typeDecl, numIndices);
            if (!rows.empty()) node->SetComputedAttribute("rowsizes", JoinRowSizes(rows));

            // In expected outputs, size for indexed arrays is the total array size.
            // curType is already that array type's size.
        }
    }

    cVarDeclNode *FindStructField(cStructDeclNode *structDecl, const std::string &name)
    {
        if (structDecl == nullptr || structDecl->GetFields() == nullptr) return nullptr;

        // Linear search via a tiny visitor that stops when found.
        struct Finder : public cVisitor
        {
            std::string name;
            cVarDeclNode *found = nullptr;
            explicit Finder(std::string n) : name(std::move(n)) {}
            void Visit(cVarDeclNode *n) override
            {
                if (n == nullptr) return;
                cSymbol *ns = n->GetNameSym();
                if (ns != nullptr && ns->GetName() == name) found = n;
            }
        };

        Finder f(name);
        structDecl->GetFields()->VisitAllChildren(&f);
        return f.found;
    }
};
