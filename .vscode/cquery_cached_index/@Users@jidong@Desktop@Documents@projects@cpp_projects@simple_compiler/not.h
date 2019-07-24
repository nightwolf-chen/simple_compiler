#ifndef __not_h__
#define __not_h__

#include "logical.h"
#include <string>

class Not : public Logical{
public:
    Not(Token *tok , Expr *x2) : Logical(tok,x2,x2){};
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