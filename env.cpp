#include "env.h"
#include "id.h"

Env::Env(){
    prev = NULL;
}

Env::~Env(){

}

void Env::put(Token *w , Id *i){
    table[w] = i;
}

Id* Env::get(Token *w){
    Env *p = this;
    while(p != NULL){
        if(p->table.find(w) != p->table.end()){
            return p->table[w];
        }
        p = p->prev;
    }
    return NULL;
}