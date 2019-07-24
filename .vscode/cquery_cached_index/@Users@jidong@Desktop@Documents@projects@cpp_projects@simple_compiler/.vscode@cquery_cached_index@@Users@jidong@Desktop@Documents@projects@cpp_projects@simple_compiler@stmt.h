#ifndef __stmt_h__
#define __stmt_h__

#include "node.h"

class Stmt : public Node{
public:
    Stmt(){
        after = 0;
    }
    static Stmt *Null;
    static Stmt *Enclosing;
    void gen(int b , int a){

    };
    int after;
};

Stmt* Stmt::Null = new Stmt();
Stmt* Stmt::Enclosing = Stmt::Null;

#endif