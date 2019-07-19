#include <iostream>
#include <vector>
#include <stack>
#include <string>

#include "lexer.h"
#include "parser.h"

using namespace std;

int main(int, char**) {
    Lexer lex;
    Parser parser(lex);
    string code = parser.program();

    cout<<code<<endl;
}
