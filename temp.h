#ifndef __temp_h__
#define __temp_h__

#include "expr.h"
#include "word.h"
#include <string>


class Temp : public Expr{
public:
    static int count;
    int number;
    Temp(Type *p)
    : Expr(Word::word(TEMP),p)
    {
        number = ++count;
    }

    std::string toString(){
        return "t" + std::to_string(number);
    }
};

int Temp::count = 0;

#endif