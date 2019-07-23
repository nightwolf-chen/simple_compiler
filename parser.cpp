#include "parser.h"
#include "lexer.h"
#include "token.h"
#include "stmt.h"

Parser::Parser(Lexer *lex){
    used = 0;
    lex = lex;
    move();
}

Parser::~Parser(){

}

void Parser::move()
{
    look = lex->scan();
}

void Parser::error(std::string e)
{
    //TODO:
}

void Parser::match(int t)
{
    if( look->tag() == t) move();
    else error("syntax error");
}

std::string Parser::program(){
    Stmt *s = block();
    int begin = s->newlabel();
    int after = s->newlabel();
    s->emitlabel(begin);
    s->gen(begin,after);
    s->emitlabel(after);
}

Stmt* Parse::block()
{
    match('{'); Env *savedEnv = top; *top = new Env(top);
    decls(); Stmt *s = stmts();
    match('}'); top = savedEnv;
    return s;
}