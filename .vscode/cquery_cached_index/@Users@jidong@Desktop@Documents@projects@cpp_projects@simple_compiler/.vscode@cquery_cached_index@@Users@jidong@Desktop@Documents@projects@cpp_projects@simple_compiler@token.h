#ifndef __token_h__
#define __token_h__

#include <string>
#include "tag.h"

class Token{
public:
    Token(int tag);
    ~Token();
    int tag();
    virtual std::string toString();
private:
    int _tag;
};

#endif