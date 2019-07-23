#ifndef __set_h__
#define __set_h__

#include "stmt.h"
#include "id.h"
#include "expr.h"
#include <string>

class Set : Stmt{
public:
    Id *id;
    Expr *expr;
    Set(Id *i , Expr *x)
    {
        id = i;
        expr = x;
        if( check(id->type,expr->type) == NULL)
        {
            error("type error");
        }
    };

    Type *check(Type *p1 , Type *p2)
    {
        if(Type::numeric(p1) && Type::numeric(p2) ) return p2;
        else if(p1 == Type::Bool() && p2 == Type::Bool()) return p2;
        else NULL;
    };

    void gen(int b ,int a)
    {
        emit(id->toString() + " = " + expr->gen()->toString());
    };
};

#endif
