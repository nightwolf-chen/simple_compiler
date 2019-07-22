
#ifndef __evn_h__
#define __evn_h__

#include <map>

class Id;
class Token;

class Env{
public:
    Env();
    ~Env();
    void put(Token *w , Id *i);
    Id* get(Token *w);
protected:
    Env *prev;
    std::map<Token *,Id *> table;
};


#endif