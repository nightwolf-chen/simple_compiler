#include "parser.h"
#include "lexer.h"
#include "token.h"
#include "stmt.h"
#include "tag.h"
#include "array.h"
#include "num.h"
#include "env.h"
#include "seq.h"
#include "expr.h"
#include "while.h"
#include "rel.h"
#include "do.h"
#include "else.h"
#include "break.h"
#include "if.h"
#include "id.h"
#include "or.h"
#include "and.h"
#include "real.h"
#include "set.h"
#include "set_elem.h"
#include "arith.h"
#include "unary.h"
#include "not.h"
#include "type.h"
#include "constant.h"

Parser::Parser(Lexer *lex){
    used = 0;
    this->lex = lex;
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
    throw e;
}

void Parser::match(int t)
{
    if( look->tag() == t) move();
    else error("syntax error");
}

void Parser::program(){
    Stmt *s = block();
    int begin = s->newlabel();
    int after = s->newlabel();
    s->emitlabel(begin);
    s->gen(begin,after);
    s->emitlabel(after);

}

Stmt* Parser::block()
{
    match('{');
    Env *savedEnv = top; 
    top = new Env(top);
    decls(); Stmt *s = stmts();
    match('}'); top = savedEnv;
    return s;
}

void Parser::decls()
{
    while( look->tag() == BASIC)
    {
        Type *p = type(); Token *tok = look; match(ID);match(';');
        Id *id = new Id((Word *)tok,p,used);
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

Type * Parser::dims(Type *p)
{
    match('['); Token *tok = look; match(NUM); match(']');
    if( look->tag() == '[' )
    {
        p = dims(p);
    }

    return new Array(((Num *)tok)->_value, p);
}

Stmt * Parser::stmts()
{
    if( look->tag() == '}' ) return Stmt::Null;
    else return new Seq(stmt(),stmts());
}

Stmt * Parser::stmt()
{
    Expr *x;
    Stmt *s,*s1,*s2;
    Stmt *savedStmt;

    switch( look->tag() ){
        case ';':{
            move();
            return Stmt::Null;
        }
        case IF:{
            match(IF); match('('); x = Bool() ; match(')');
            s1 = stmt();
            if( look->tag() != ELSE ) return new If(x,s1);
            s2 = stmt();
            return new Else(x,s1,s2);
        }
        case WHILE:{
            While *whilenode = new While();
            savedStmt = Stmt::Enclosing; Stmt::Enclosing = whilenode;
            match(WHILE); match('('); x = Bool(); match(')');
            s1 = stmt();
            whilenode->init(x,s1);
            Stmt::Enclosing = savedStmt;
            return whilenode;
        }
        case DO:{
            Do *donode = new Do();
            savedStmt = Stmt::Enclosing; Stmt::Enclosing = donode;
            match(DO);
            s1 = stmt();
            match(WHILE); match('('); x = Bool(); match(')'); match(';');
            donode->init(s1,x);
            Stmt::Enclosing = savedStmt;
            return donode;
        }
        case BREAK:{
            match(BREAK); match(';');
            return new Break();
        }
        case '{':{
            return block();
        }
        default:
            return assign();
    }
}

Stmt * Parser::assign()
{
    Stmt *stmt;
    Token *t = look;
    match(ID);
    Id *id = top->get(t);
    if( id == NULL){
        error(t->toString() + " undecleared");
    } 

    if( look->tag() == '='){
        move(); 
        stmt = new Set(id,Bool());
    }else {
        Access *x = offset(id);
        match('=');
        stmt = new SetElem(x,Bool());
    }
    match(';');
    return stmt;
}

Expr * Parser::Bool()
{
    Expr *x = join();
    while( look->tag() == OR )
    {
        Token *tok = look;
        move();
        x = new Or(tok,x,join());
    }

    return x;
}
    

Expr * Parser::join()
{
    Expr *x = equality();
    while( look->tag() == AND )
    {
        Token *tok = look;
        move();
        x = new And(tok, x , equality());
    }
    return x;
}
    

Expr * Parser::equality()
{
    Expr *x = rel();
    while( look->tag() == EQ || look->tag() == NE )
    {
        Token *tok = look;
        move();
        x = new Rel(tok, x, rel());
    }
    return x;
}
    

Expr * Parser::rel()
{
    Expr *x = expr();
    switch (look->tag())
    {
    case '<': 
    case LE:
    case GE:
    case '>':{
        Token *tok = look;
        move();
        return new Rel(tok,x,expr());
    }
    default:
        return x;
    }
}
    

Expr * Parser::expr()
{
    Expr *x = term();
    while( look->tag() == '+' || look->tag() == '-' )
    {
        Token *tok = look;
        move();
        x = new Arith(tok,x,term());
    }
    return x;
}
    

Expr * Parser::term()
{
    Expr *x = unary();
    while( look->tag() == '*' || look->tag() == '/')
    {
        Token *tok = look;
        move();
        x = new Arith(tok,x,term());
    }

    return x;
}
    

Expr * Parser::unary()
{
    if( look->tag() == '-'){
        move();
        return new Unary(Word::word(MINUS),unary());
    }else if( look->tag() == '!'){
        Token *tok = look;
        move();
        return new Not(tok,unary());
    }else return factor();
}
    

Expr * Parser::factor()
{
    Expr *x = NULL;
    switch ( look->tag() )
    {
    case '(':{
        move(); x = Bool();match(')');
        return x;
    }
    break;
    case NUM:{
        x = new Constant(look,Type::Int());
        move();
        return x;
    }
    break;
    case REAL:{
        x = new Constant(look,Type::Float());
        move();
        return x;
    }
    break;
    case TRUE:{
        x = (Expr *)Constant::True;
        move();
        return x;
    }
    break;
    case FALSE:{
        x = (Expr *)Constant::False;
        move();
        return x;
    }
    break;
    case ID:{
        std::string s = look->toString();
        Id *id = top->get(look);
        if( id == NULL ) {
            error(look->toString() + " undecleared");
        }
        move();
        if( look->tag() != '[') return id;
        else return offset(id);
    }
    break;
    
    default:{
        error("syntax error");
        return x;
    }
        break;
    }

    return x;
}
    

Access * Parser::offset(Id *a)
{
    Expr *i;
    Expr *w;
    Expr *t1;
    Expr *t2;
    Expr *loc;
    Type *type = a->type;
    match('[');i = Bool();match(']');
    type = ((Array *)type)->of;
    w = new Constant(type->width());
    t1 = new Arith(new Token('*'),i,w);
    loc = t1;
    while( look->tag() == '[')
    {
        match('['); i = Bool(); match(']');
        type = ((Array*)type)->of;
        w = new Constant(type->width());
        t1 = new Arith(new Token('*'),i,w);
        t2 = new Arith(new Token('+'),loc,t1);
        loc = t2;
    }
    return new Access(a,loc,type);
}
    
