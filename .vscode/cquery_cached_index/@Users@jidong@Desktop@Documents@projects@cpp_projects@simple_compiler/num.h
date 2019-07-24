#ifndef __num_h__
#define __num_h__

#include "token.h"

class Num : public Token{
public:
    Num(int val);
    ~Num();
    virtual std::string toString();
    int _value;
private:
};

#endif