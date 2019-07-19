#ifndef __lexer_h__
#define __lexer_h__

#include <map>
#include <string>

class Word;
class Token;

typedef enum Tag{
    AND = 256,
    BASIC,
    BREAK,
    DO,
    ELSE,
    EQ,
    FALSE,
    GE,
    ID,
    IF,
    INDEX,
    LE,
    MINUS,
    NE,
    NUM,
    OR,
    REAL,
    TEMP,
    TRUE,
    WHILE
}Tag;

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