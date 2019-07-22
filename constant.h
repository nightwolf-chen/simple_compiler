#ifndef __constant_h__
#define __constant_h__

#include "expr.h"
#include "word.h"
#include <string>

class Type;
class Token;

class Constant : public Expr{
public:
    Constant(Token *tok, Type *p)
    : Expr(tok,p);
    {

    }
    ~Constant(){

    }

    static final Constant *True , *False;
    void jumping(int t , int f)
    {
        if(this == True && t != 0) emit("goto L" + std::to_string(t));
        else if(this == False && f != 0) emit("goto L" + std::to_string(f));
    }
};

Constant* Constant::True = new Constant(Word::True(),Type::Bool());
Constant* Constant::False = new Constant(Word::False(),Type::Bool());

#endif