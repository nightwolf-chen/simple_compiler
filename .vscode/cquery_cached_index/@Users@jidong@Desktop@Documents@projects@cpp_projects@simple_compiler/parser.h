#ifndef __parse_h__
#define __parse_h__

#include <string>

class Lexer;
class Token;
class Env;
class Stmt;
class Type;
class Expr;
class Access;
class Id;

class Parser{
public:
    Parser(Lexer *lexer);
    ~Parser();
    void program();
protected:
    void move();
    void error(std::string e);
    void match(int t);
    Stmt* block();
    Type * type();
    void decls();
    Type * dims(Type *p);
    Stmt * stmts();
    Stmt * stmt();
    Stmt * assign();
    Expr * Bool();
    Expr * join();
    Expr * equality();
    Expr * rel();
    Expr * expr();
    Expr * term();
    Expr * unary();
    Expr * factor();
    Access * offset(Id *a);
private:
    Lexer *lex;
    Token *look;
    Env *top;
    int used;
};

#endif