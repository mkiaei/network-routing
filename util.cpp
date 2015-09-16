// Network traffic routing
// 
// Mohammad Kiaei
// August 2015
//
// util.cpp
// Utility functions implementation

#include "util.h"

// itos: Convert input integer to a string
// Argument: input interger
string itos(int i)
{
    stringstream s;
    s << i;
    return s.str();
}
/******************************************************************************/
