#pragma once

#include <string>
#include "cVisitor.h"

// Stub for future labs (code generation).
// For Lab 5b, this is intentionally a no-op so the project can build.
class cCodeGen : public cVisitor
{
public:
    explicit cCodeGen(const std::string & /*outputFile*/) {}
};
