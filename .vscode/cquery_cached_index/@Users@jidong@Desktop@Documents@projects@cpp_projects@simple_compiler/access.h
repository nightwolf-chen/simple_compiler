#ifndef __access_h__
#define __access_h__

#include "op.h"
#include "word.h"
#include "tag.h"
#include "id.h"
#include <string>


class Access : public Op{
public:
    Id *array;
    Expr *index;
    Access(Id *a , Expr *i, Type *p)
    : Op(new Word("[]",INDEX),p)
    {
        array = a;
        index = i;
    };

    Expr* gen()
    {
        return new Access(array,index->reduce(),type);
    };

    void jumping(int t,int f)
    {
        return emitjumps(reduce()->toString(),t,f);
    };

    std::string toString()
    {
        return array->toString() + "[" + index->toString() + "]";
    };
};


#endif