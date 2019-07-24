#ifndef __op_h__
#define __op_h__

#include "expr.h"

class Token;
class Type;
class Temp;

class Op : public Expr{
public:
    Op(Token *tok , Type *p) 
    : Expr(tok,p)
    {

    }
    ~Op(){

    }
    Expr *reduce(){
        Expr *x = gen();
        Temp *t = new Temp(type);
        emit(t->toString() + " = " + x->toString());
        return t;
    }
};

#endif