#include "cSymbolTable.h"

cSymbolTable::cSymbolTable()
{
    // Start with a global scope so Insert/FindLocal are always safe.
    mScopes.emplace_back();
}

symbolTable_t *cSymbolTable::IncreaseScope()
{
    mScopes.emplace_back();
    return &mScopes.back();
}

symbolTable_t *cSymbolTable::DecreaseScope()
{
    if (mScopes.size() <= 1)
        return &mScopes.back();

    mScopes.pop_back();
    return &mScopes.back();
}   

void cSymbolTable::Insert(cSymbol *sym)
{
    // Insert into the current (inner-most) scope only
    mScopes.back()[sym->GetName()] = sym;
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
