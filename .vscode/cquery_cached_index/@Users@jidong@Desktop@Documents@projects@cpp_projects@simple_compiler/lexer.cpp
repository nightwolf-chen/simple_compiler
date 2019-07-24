#include "lexer.h"
#include "word.h"
#include "type.h"
#include "num.h"
#include "real.h"

int Lexer::line = 1;

Lexer::Lexer(std::string input){

    _input = input;
    Lexer::line = 0;

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

void Lexer::reserve(Word *w)
{
    words[w->lexeme()] = w;
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
        else if( peek == '\n') Lexer::line = Lexer::line + 1;
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

    if(isdigit(peek)){
        int v = 0;
        do{
            v = 10*v + peek - '0'; 
            readch();
        }while(isdigit(peek));

        if(peek != ' ') return new Num(v);
        float x = v;
        float d = 10;
        while(true){
            readch();
            if(!isdigit(peek)) break;
            x = x + (peek-'0')/d;
            d = d * 10;
        }
        return new Real(x);
    }

    if(isalpha(peek)){
        std::string b = "";
        do{
            b += peek;
            readch();
        }while(isalpha(peek) || isdigit(peek));
        std::string &s = b;
        Word *w = words[s];
        if(w != NULL){
            return w;
        }

        w = new Word(s,ID);
        words[s] = w;
        return w;
    }

    Token *tok = new Token(peek);
    peek = ' ';
    return tok;
}
