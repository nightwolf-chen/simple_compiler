#ifndef __arith_h__
#define __arith_h__

#include "op.h"

class Arith : public Op{
public:
    Expr *expr1 , *expr2;
    Arith(Token *tok , Expr *x1 , Expr *x2)
    :Op(tok,NULL)
    {
        expr1 = x1;
        expr2 = x2;
    }
    ~Arith(){

    }

    Expr *gen(){
        return new Arith(op,expr1->reduce(),expr2->reduce());
    }

    std::string toString(){
        return expr1->toString() + " " + op->toString() + " " + expr2->toString();
    }
};

#define