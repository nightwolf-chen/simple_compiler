#ifndef __type_h__
#define __type_h__

#include <string>
#include "word.h"

class Type : public Word
{
protected:
    /* data */
    int _width;
public:
    Type(std::string,Tag tag,int width);
    ~Type();

    virtual bool isArray()
    {
        return false;
    }

    int width();

    static Type * Int(){
        static Type *i = new Type("int",BASIC,4);
        return i;
    }

    static Type * Float(){
        static Type * i = new Type("float",BASIC,8);
        return i;
    }
    static Type * Bool(){
        static Type * i = new Type("bool",BASIC,1);
        return i;
    }

    static Type * Char(){
        static Type *i = new Type("char",BASIC,1);
        return i;
    }

    static bool numeric(Type *p){
        if(p == Type::Float() || p == Type::Int() || p == Type::Char()) return true;
        return false;
    }

    static Type* max(Type *p1 , Type *p2){
        if(!numeric(p1) || !numeric(p2)) return NULL;
        else if(p1 == Type::Float() || p2 == Type::Float()) return Type::Float();
        else if(p1 == Type::Int() || p2 == Type::Int()) return Type::Int();
        else return Type::Char();
    }
};



#endif