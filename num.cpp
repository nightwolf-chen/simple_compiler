
#include "num.h"
#include <string>

Num::Num(int val)
:Token(NUM){
    _value = val;
}

std::string Num::toString(){
    return std::to_string(_value);
}