#ifndef __node_h__
#define __node_h__

#include <string>

class Node{
public:
    Node();
    ~Node();
    void error(std::string s);
    int newlabel();
    void emitlabel(int i);
    void emit(std::string s);
protected:
    int lexline;
};

#endif