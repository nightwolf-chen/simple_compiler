#ifndef __num_h__
#define __num_h__

#include "token.h"

class Num : Token{
public:
    Num(int val);
    ~Num();
    virtual std::string toString();
private:
int _value;
};

#endif