#ifndef __or_h__
#define __or_h__

#include "logical.h"

class Token;

class Or : Logical{
public:
    Or(Token *tok , Expr *x1 , Expr *x2)
    : Logical(tok,x1,x2)
    {

    }

    void jumping(int t , int f)
    {
        int label = t != 0 ? t : newlabel();
        expr1->jumping(label,0);
        expr2->jumping(t,f);
        if( t == 0) emitlabel(label);
    }
};

#endif