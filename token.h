#ifndef __token_h__
#define __token_h__

#include "lexer.h"

#include <string>

class Token{
public:
    Token(Tag tag);
    ~Token();
    Tag tag();
    virtual std::string toString();
private:
    Tag _tag;
};

#endif