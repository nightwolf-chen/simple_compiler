#ifndef __real_h__
#define __real_h__

#include "token.h"
#include <string>

class Real : public Token{
public:
    float value();
    Real(float v);
    virtual std::string toString();
private:
    float _val;
};

#endif