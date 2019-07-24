#ifndef __array_h__
#define __array_h__

#include "type.h"
#include <string>

class Array : public Type{
public:
    Type *of;
    int size ;
    bool isArray(){
        return true;
    }
    Array(int sz , Type *p);
    ~Array();
    std::string toString();
}; 

#endif 