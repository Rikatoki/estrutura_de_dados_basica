#include "ArvoreBin.h"
#include <iostream>
NO::NO(int ch){
    chave = ch;
    esq = nullptr;
    dir = nullptr;
}

ArvBin::ArvBin(){
    raiz = nullptr;
}

void ArvBin::FindParentAndNode(PONT &parent, PONT &node, int ch){
    parent = nullptr;
    node = raiz;
    while(node != nullptr && node->chave != ch){
        parent = node;
        if(node->chave < ch) node = node->dir;
        else node = node->esq;
    }
}
bool ArvBin::insert(int ch){
    PONT node, parent;
    FindParentAndNode(parent, node, ch);

    if(node != nullptr){ 
        return false;
    }
    NO* novo =  new NO(ch);
    if(parent == nullptr){
        raiz = novo;
    }
    else {
        if(parent->chave < ch) parent->dir = novo;
        else parent->esq = novo;
    }
    return true;
}
PONT ArvBin::search(int ch){
    PONT node, parent;
    FindParentAndNode(parent, node, ch);
    return node;
}
bool ArvBin::removerElem(int ch){
    PONT node, parent, sub, assis;
    FindParentAndNode(parent, node, ch);
    if(!node) return false;

    assis = nullptr;
    sub = nullptr;
    if(node->dir != nullptr){
        sub = node->dir;
        while(sub->esq != nullptr){
            assis = sub;
            sub = sub->esq;
        }
        if(assis != nullptr){
            assis->esq = sub->dir;
            sub->dir = node->dir;
        }
        sub->esq = node->esq;
    } else if(node->esq != nullptr) sub = node->esq;
    if(!parent) raiz = sub;
    else{
        if(node->chave < parent->chave) parent->esq = sub;
        else parent->dir = sub;
    }
    delete node;
    return true;
}

void ArvBin::elementos(PONT node, int &cont){
    if(node != nullptr) cont += 1;
    else return;
    elementos(node->dir, cont);
    elementos(node->esq, cont);
}
int ArvBin::contagem(){
    int elem = 0;
    elementos(raiz, elem);
    return elem;
}

void ArvBin::imprirec(PONT node){
    if(node != nullptr){
        std::cout << node->chave << std::endl;
        std::cout <<  " ( "; 
        imprirec(node->esq);
        std::cout << ")" << std::endl;
        std::cout <<  " ( "; 
        imprirec(node->dir);
        std::cout << ")" << std::endl;
    }
}
void ArvBin::imprimir(){
    imprirec(raiz);
}

void ArvBin::delrec(PONT &node){
    if(node == nullptr) return;
    delrec(node->dir);
    delrec(node->esq);
    delete node;
}
ArvBin::~ArvBin(){
    delrec(raiz);
}