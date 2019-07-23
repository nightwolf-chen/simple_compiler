#include "parser.h"
#include "lexer.h"
#include "token.h"
#include "stmt.h"
#include "tag.h"

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

Stmt* Parser::block()
{
    match('{'); Env *savedEnv = top; *top = new Env(top);
    decls(); Stmt *s = stmts();
    match('}'); top = savedEnv;
    return s;
}

void Parser::decls()
{
    while( look->tag() == BASIC)
    {
        Type *p = type(); Token *tok = look; match(ID);match(';');
        Id *id = new Id(Word *)tok,p,used);
        top->put(tok,id);
        used += p->width();
    }
}

Type * Parser::type()
{
    Type *p = (Type *)look;
    match(BASIC);
    if( look->tag() != '[') return p;
    else return dims(p);
}
