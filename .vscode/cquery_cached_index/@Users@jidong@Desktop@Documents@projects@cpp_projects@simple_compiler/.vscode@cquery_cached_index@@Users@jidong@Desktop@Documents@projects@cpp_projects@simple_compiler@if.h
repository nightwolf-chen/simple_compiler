#ifndef __if_h__
#define __if_h__

#include "stmt.h"
#include "type.h"
#include "expr.h"


class If : public Stmt{
public:
    Expr *expr;
    Stmt *stmt;
    If(Expr *x , Stmt *s)
    {
        expr = x;
        stmt = s;
        if(expr->type != Type::Bool()){
            expr->error("boolean required in if");
        }
    }

    void gen(int b , int a)
    {
        int label = newlabel();
        expr->jumping(0,a);
        emitlabel(label);
        stmt->gen(label,a);
    }
};

#endif