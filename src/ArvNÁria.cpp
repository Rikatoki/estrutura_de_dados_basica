#include "ArvNÁria.h"

NO::NO(int chave){
    ch = chave;
    filho = nullptr;
    irmao = nullptr;
}

NAria::NAria(int ch){
    raiz = new NO(ch);
}

bool NAria::insert(int p,int n){
    PONT pai = search(raiz, p); 
    if(!pai || search(raiz, n)) return false;
    PONT novo = new NO(n);
    novo->irmao = pai->filho;
    pai->filho = novo;
    return true;
}

PONT NAria::search(PONT no, int chave){
    if(no == nullptr) return nullptr;
    if(no->ch == chave) return no;
    PONT resp = search(no->filho, chave);
    if(resp) return resp;
    return search(no->irmao, chave);
}
PONT NAria::searchant(PONT no, int chave){
    if(no == nullptr) return nullptr;
    if(no->filho && no->filho->ch == chave) return no;
    if(no->irmao && no->irmao->ch == chave) return no;
    PONT resp = searchant(no->filho, chave);
    if(resp) return resp;
    return searchant(no->irmao, chave);
}

bool NAria::del(int chave){
    PONT no = search(raiz, chave);
    if(!no) return false;
    PONT ant = searchant(raiz, chave);
    if(ant != nullptr){
        if(ant->filho && ant->filho->ch == chave) ant->filho = no->irmao;
        else if(ant->irmao && ant->irmao->ch == chave) ant->irmao = no->irmao;
    } else return false;
    delrec(no->filho);
    delete no;
    return true;
}
void NAria::delrec(PONT no){
    if(no == nullptr) return;
    delrec(no->filho);
    delrec(no->irmao);
    delete no;
}