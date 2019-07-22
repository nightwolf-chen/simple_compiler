#include "real.h"

Real::Real(float v)
: Token(REAL)
{
    _val = v;
}

std::string Real::toString()
{
    return "" + std::to_string(_val);
}

