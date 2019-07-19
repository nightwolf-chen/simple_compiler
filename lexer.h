#ifndef __lexer_h__
#define __lexer_h__

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
    Lexer();
    ~Lexer();
    private:
};

#endif