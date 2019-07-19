#include "real.h"

Real::Real(float v)
: Token(REAL)
{
    _val = value;
}

std::string Real::toString()
{
    return "" + _val;
}

