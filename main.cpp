#include <iostream>
#include <vector>
#include <stack>
#include <string>

#include "lexer.h"
#include "parser.h"

using namespace std;

int main(int, char**) {
    std::string input = "test";
    Parser parser(new Lexer(input));
    string code = parser.program();

    cout<<code<<endl;
}
