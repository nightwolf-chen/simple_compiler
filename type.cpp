#include "type.h"

Type::Type(std::string s, Tag tag , int width)
:Word(s,tag)
{
    _width = width;
}

Type::~Type()
{

}

int Type::width()
{
    return _width;
}
