#include <iostream>
#include <vector>
#include <stack>
#include <string>

#include "lexer.h"
#include "parser.h"
#include <string>
#include <fstream>
#include <streambuf>

using namespace std;

int main(int, char**) {

    std::ifstream t("/Users/jidong/Desktop/Documents/projects/cpp_projects/simple_compiler/test.c");
    std::string input((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
    Parser *parser = new Parser(new Lexer(input));
    parser->program();
    cout<<endl;
}
