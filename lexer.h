#ifndef __lexer_h__
#define __lexer_h__

#include <map>
#include <string>
#include "tag.h"

class Word;
class Token;

class Lexer{
public:
    Lexer(std::string input);
    ~Lexer();
    static int line;
    void reserve(Word *w);
    void readch();
    bool readch(char c);
    Token * scan();
private:
    char peek;
    std::string _input;
    int _currentPos;
    std::map<std::string,Word *> words;
};

#endif