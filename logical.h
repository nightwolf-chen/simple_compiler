#ifndef __logical_h__
#define __logical_h__

#include "expr.h"
#include <string>

class Token;
class Type;

class Logical : public Expr{
public:
    Expr expr1 , expr2;
    Logical(Token * tok,Expr *x1 , Expr *x2)
    : Expr(tok,NULL)
    {
        expr1 = x1;
        expr2 = x2;
        type = check(expr1->type,expr2->type);
        if(type == NULL) error("type eroor");
    }

    Type *check(Type *p1 , Type *p2)
    {
        if(p1 == Type::Bool() && p2 == Type::Bool()){
            return Type::Bool();
        }
        return NULL;
    }

    Expr * gen()
    {
        int f = newlabel();
        int a = newlabel();
        this.jumping(0,f);
        Temp *temp = new Temp(type);
        emit(temp->toString()+" = true");
        emit("goto L " + std::to_string(a));
        emitlabel(f);
        emit(temp->toString() + " = false");
        emitlabel(a);
        return temp;
    }

    std::string toString()
    {
        return expr1->toString()+" "+op->toString()+" "+expr2->toString();
    }
};

#endif