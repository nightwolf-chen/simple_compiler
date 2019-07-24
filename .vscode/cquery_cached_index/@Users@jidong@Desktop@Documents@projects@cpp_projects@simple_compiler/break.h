#ifndef __break_h__
#define __break_h__

#include "stmt.h"
#include <string>

class Break :  public Stmt{
public:
    Stmt *stmt;
    Break(){
        if(Stmt::Enclosing == Stmt::Null)
        {
            error("unenclosed break!");
        }
        stmt = Stmt::Enclosing;
    };

    void gen(int b , int a)
    {
        emit("goto L " + std::to_string(stmt->after) );
    };
};

#endif