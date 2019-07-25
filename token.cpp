#include "token.h"

Token::Token(int tag){
    _tag = tag;
}

Token::~Token(){

}

int Token::tag(){
    return _tag;
}

std::string Token::toString(){
    return std::string(1,(char)_tag);
}

