#ifndef __and_h__
#define __and_h__

#include "logical.h"

class And : Logical{
public:
    And(Token *tok , Expr *x1 , Expr *x2) : Logical(tok,x1,x2){};
    ~And();
    void jumping(int t,int f){
        int label = f != 0 ? f : newlabel();
        expr1->jumping(0,label);
        expr2->jumping(t,f);
        if( f == 0) emitlabel(label);
    }
};


#endif