#ifndef __not_h__
#define __not_h__

#include "logical.h"
#include <string>

class Not : Logical{
public:
    Not(Token *tok , Expr *x1 ,Expr *x2) : Logical(tok,x1,x2){};
    void jumping(int t, int f)
    {
        expr2->jumping(f,t);
    }

    std::string toString()
    {
        return op->toString() +  " " + expr2->toString();
    }
};

#endif