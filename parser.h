#ifndef __parse_h__
#define __parse_h__

#include <string>

class Lexer;

class Parser{
public:
    Parser(Lexer lexer);
    ~Parser();
    std::string program();
private:
};

#endif