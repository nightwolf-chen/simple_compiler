#include "word.h"

Word::Word(std::string lexeme , Tag tag)
:Token(tag)
{
    _lexeme = lexeme;
}

Word::~Word()
{

}

std::string Word::toString()
{
    return _lexeme;
}

std::string Word::lexeme()
{
    return _lexeme;
}

Word* Word::word(Tag tag){
    static std::map<Tag,Word *> words;
    if(words.size() == 0){
        words[AND] = new Word("&&",AND);
        words[OR] = new Word("||",OR);
        words[EQ] = new Word("==",EQ);
        words[NE] = new Word("!=",NE);
        words[LE] = new Word("<=",LE);
        words[GE] = new Word(">=",GE);
        words[MINUS] = new Word("-",MINUS);
        words[TRUE] = new Word("true",TRUE);
        words[FALSE] = new Word("false",FALSE);
        words[TEMP] = new Word("t",TEMP);
    }
    return words[tag];
}



