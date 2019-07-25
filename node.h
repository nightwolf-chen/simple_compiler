#ifndef __node_h__
#define __node_h__

#include <string>

class Node{
public:
    Node();
    ~Node();
    void error(std::string s);
    int newlabel();
    virtual void emitlabel(int i);
    virtual void emit(std::string s);
protected:
    int lexline;
};

#endif