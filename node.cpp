#include "node.h"
#include "lexer.h"
#include <iostream>

 Node::Node(){
     lexline = Lexer::line;
 }
  
 Node::~Node(){

 }

 void Node::error(std::string s){
     throw s;
 }

 int Node::newlabel(){
     static int labels = 0;
     return ++labels;
 }
 
 void Node::emitlabel(int i){
     std::cout<<"L"<<i<<":"<<std::endl;
 }

 void Node::emit(std::string s){
     std::cout<<"   "<<s<<std::endl;
 }