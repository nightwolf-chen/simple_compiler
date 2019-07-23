#ifndef __parse_h__
#define __parse_h__

#include <string>

class Lexer;
class Token;
class Env;

class Parser{
public:
    Parser(Lexer *lexer);
    ~Parser();
    std::string program();
protected:
    void move();
    void error(std::string e);
    void match(int t);
private:
    Lexer *lex;
    Token *look;
    Env *top;
    int used;
};

#endif