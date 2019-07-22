#include "array.h"
#include "tag.h"

Array::Array(int sz , Type *p)
:Type("[]",INDEX, sz)
{
    size = sz;
    of = p;
}

Array::~Array(){

}

std::string Array::toString(){
    return "[]" + of->toString(); 
}