#ifndef __constant_h__
#define __constant_h__

#include "expr.h"
#include "word.h"
#include <string>
#include "num.h"

class Type;
class Token;

class Constant : public Expr{
public:
    Constant(Token *tok, Type *p)
    : Expr(tok,p)
    {

    };
    Constant(int i)
    : Expr(new Num(i) ,Type::Int())
    {

    };
    ~Constant(){

    };

    static const Constant *True , *False;
    void jumping(int t , int f)
    {
        if(this == Constant::True && t != 0) emit("goto L " + std::to_string(t));
        else if(this == Constant::False && f != 0) emit("goto L " + std::to_string(f));
    }
};

const Constant* Constant::True = new Constant(Word::word(TRUE),Type::Bool());
const Constant* Constant::False = new Constant(Word::word(FALSE),Type::Bool());

#endif