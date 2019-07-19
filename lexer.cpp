#include "lexer.h"
#include "word.h"
#include "type.h"

Lexer::Lexer(std::string input){

    _input = input;
    line = 0;

    reserve(new Word("if",IF));
    reserve(new Word("else",ELSE));
    reserve(new Word("while",WHILE));
    reserve(new Word("do",DO));
    reserve(new Word("break",BREAK));

    reserve(Word::word(TRUE));
    reserve(Word::word(FALSE));

    reserve(Type::Int());
    reserve(Type::Float());
    reserve(Type::Char());
    reserve(Type::Bool());

    _currentPos = 0;
    peek = ' ';
    
}

Lexer::~Lexer()
{

}

void Lexer::readch()
{
    //TODO:next
    if(_currentPos < _input.size()){
        peek = _input[_currentPos++];
    }else{
        peek = EOF;
    }
}

bool Lexer::readch(char c)
{
    readch();
    if( peek != c) return false;
    peek = ' ';
    return true;
}

Token* Lexer::scan()
{
    for(;;readch()){
        if( peek == ' ' || peek == '\t') continue;
        else if( peek == '\n') line = line + 1;
        else break;
    }


    switch (peek)
    {
    case '&':
        if( readch('&') ) return Word::word(AND); else return new Token((Tag)'&');
    case '|':
        if( readch('|') ) return Word::word(OR); else return new Token((Tag)'|');
    case '=':
        if( readch('=') ) return Word::word(EQ); else return new Token((Tag)'=');
    case '!':
        if( readch('=') ) return Word::word(NE); else return new Token((Tag)'!');
    case '<':
        if( readch('=') ) return Word::word(LE); else return new Token((Tag)'<');
    case '>':
        if( readch('=') ) return Word::word(GE); else return new Token((Tag)'>');
    default:
        break;
    }

    //TODO:
    if(isdigit(peek)){

    }

}
