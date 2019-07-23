#ifndef __while_h__
#define __while_h__

#include "stmt.h"
#include <string>

class While : public Stmt{
public:
    Expr *expr;
    Stmt *stmt;

    While()
    {
        expr = stmt = null;
    };

    void init(Expr *x , Stmt *s)
    {
        expr = x;
        stmt = s;
        if( expr->type != Type::Bool())
        {
            expr->error("boolean required in while");
        }
    };

    void gen(int b , int a)
    {
        after = a;
        expr->jumping(0,a);
        int label = newlabel();
        emitlabel(label); stmt->gen(label,b);
        emit("goto L " + std::to_string(b));
    }
};

#endif