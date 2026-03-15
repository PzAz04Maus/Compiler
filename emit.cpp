//*******************************************************
// Purpose: Utility routines used for code generation
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
//*******************************************************

#include <iostream>
#include <stdio.h>
#include <string>
#include "emit.h"

using std::string;

// Output files
static FILE* Output;

static int  Next_Label = 1;

//*****************************************
// Opens the output file for code generation.
// filename: name of the output file to write.
// Returns true on success, false on failure.
bool InitOutput(const std::string filename)
{
    Output = fopen(filename.c_str(), "w");
    if (Output == NULL)
    {
        std::cerr << "Unable to open output file." << std::endl;
        return false;
    }

    return true;
}
//*****************************************
// output postfix, copy functions to tail of main file and close files
// Closes the output file after code generation is complete.
// Returns true on success.
bool FinalizeOutput()
{
    fclose(Output);

    return true;
}
//*****************************************
// Generates a unique label string for use in code generation (e.g., for jumps).
// Returns a new unique label each call.
std::string GenerateLabel()
{
    Next_Label++;
    std::string label("$LANG_LABEL");
    label += std::to_string(Next_Label);
    return label;
}
//*****************************************
// Writes an integer constant to the output file.
// val: integer value to write.
void EmitInt(int val)
{
    fprintf(Output, " %d ", val);
}
//*****************************************
// Writes a string to the output file.
// str: string to write.
void EmitString(std::string str)
{
    fprintf(Output, "%s", str.c_str());
}
