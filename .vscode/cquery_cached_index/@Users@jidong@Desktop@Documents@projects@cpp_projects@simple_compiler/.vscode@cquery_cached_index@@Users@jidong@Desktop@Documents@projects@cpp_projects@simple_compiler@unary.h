#ifndef __unary_h__
#define __unary_h__

#include "op.h"
#include "token.h"
#include "type.h"

class Unary : public Op{
public:
    Expr *expr;
    Unary(Token *tok , Expr *x)
    : Op(tok,NULL)
    {
        expr = x;
        type = Type::max(Type::Int(),expr->type);
        if(type == NULL) error("type errer");
    }

    Expr * gen()
    {
        return new Unary(op,expr->reduce());
    }

    std::string toString(){
        return op->toString()+" "+expr->toString();
    }
};

#endif