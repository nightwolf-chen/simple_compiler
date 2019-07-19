#ifndef __word_h__
#define __word_h__

#include "token.h"
#include <string>
#include <map>

class Word : Token{
public:
    Word(std::string , Tag tag);
    ~Word();
    virtual std::string toString();
    std::string lexeme();

    static Word * getWord(Tag tag);
private:
    std::string _lexeme;
};

#endif