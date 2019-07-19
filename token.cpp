#include "token.h"

Token::Token(Tag tag){
    _tag = tag;
}

Token::~Token(){

}

Tag Token::tag(){
    return _tag;
}

std::string Token::toString(){
    return "todo";
}

