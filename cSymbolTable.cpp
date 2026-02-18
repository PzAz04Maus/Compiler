#include "cSymbolTable.h"

// Global symbol table instance
cSymbolTable g_symbolTable;

cSymbolTable::cSymbolTable()
{
    mScopes.emplace_back();
    mTypeScopes.emplace_back();
}

symbolTable_t *cSymbolTable::IncreaseScope()
{
    mScopes.emplace_back();
    mTypeScopes.emplace_back();
    return &mScopes.back();
}

symbolTable_t *cSymbolTable::DecreaseScope()
{
    if (mScopes.size() <= 1)
        return &mScopes.back();

    mScopes.pop_back();
    if (mTypeScopes.size() > 1) mTypeScopes.pop_back();
    return &mScopes.back();
}   

void cSymbolTable::Insert(cSymbol *sym)
{
    // Insert into the current (inner-most) scope only
    mScopes.back()[sym->GetName()] = sym;
}

void cSymbolTable::DeclareType(cSymbol *sym)
{
    if (sym == nullptr) return;
    mTypeScopes.back().insert(sym->GetName());
}

cSymbol *cSymbolTable::Find(string name)
{
    // Search from inner-most (back) to outer-most (front)
    for (auto it = mScopes.rbegin(); it != mScopes.rend(); ++it)
    {
        auto found = it->find(name);
        if (found != it->end())
        {
            return found->second; // cSymbol*
        }
    }
    return nullptr;
}

cSymbol *cSymbolTable::FindLocal(string name)
{
    if (mScopes.empty())
        return nullptr;

    auto& current = mScopes.back();
    auto it = current.find(name);

    if (it != current.end())
        return it->second;

    return nullptr;
}

bool cSymbolTable::IsType(const string &name) const
{
    for (auto it = mTypeScopes.rbegin(); it != mTypeScopes.rend(); ++it)
        if (it->find(name) != it->end()) return true;
    return false;
}
