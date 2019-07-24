#ifndef __id_h__
#define __id_h__

#include "expr.h"

class Id : public Expr{
public:
    int offset;
    Id(Word *id, Type *p , int b)
    : Expr(id,p)
    {
        offset = b;
    };
    ~Id(){

    };
};


#endif