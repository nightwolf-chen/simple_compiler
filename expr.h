#ifndef __expr_h__
#define __expr_h__

#include "node.h"
#include "type.h"

class Token;

class Expr : public Node{
public:
    Token *op;
    Type *type;
    Expr(Token *tok , Type *p){
        op = tok;
        type = p;
    }

    ~Expr(){

    }

    virtual Expr * gen(){
        return this;
    }
    virtual Expr * reduce(){
        return this;
    }

    virtual std::string toString(){
        return op->toString();
    }

    void emitjumps(std::string test , int t , int f){
        if(t != 0 && f != 0){
            emit("if" + test + " goto L" + std::to_string(t));
            emit("goto L" + std::to_string(f));
        }else if(t != 0){
            emit("if " + test + " goto L" + std::to_string(t));
        }else if(f != 0){
            emit("iffalse " + test + " goto L" + std::to_string(f));
        }
    }

    void jumping(int t ,int f){
        emitjumps(toString(),t,f);
    }
};

#endif 