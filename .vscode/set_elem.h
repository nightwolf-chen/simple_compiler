#ifndef __set_elem_h__
#define __set_elem_h__

#include "stmt.h"
#include "access.h"

class SetElem : Stmt{
public:
    Id *array;
    Expr *index;
    Expr *expr;
    SetElem(Access *x , Expr *y)
    {
        array = x->array;
        index = x->index;
        expr = y;
        if( check(x->type,expr->type) == NULL)
        {
            error("type error");
        }
    };

    Type * check(Type *p1 , Type *p2)
    {
        if(p1->isArray() || p2->isArray()) return NULL;
        else if( p1 == p2) return p2;
        else if ( Type::numeric(p1) && Type::numeric(p2) ) return p2;
        else return NULL;
    };

    void gen(int b , int a)
    {
        std::string s1 = index->reduce()->toString();
        std::string s2 = expr->reduce()->toString();
        emit(array->toString() + " [" + s1 + " ]= " + s);
    };
};


#endif