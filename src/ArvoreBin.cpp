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
    PONT parent, node, p, q;
    FindParentAndNode(parent, node, ch);
    if(node == nullptr) return false;
    if(!node->esq || !node->dir){
        if(!node->esq) q = node->dir;
        else q = node->esq;
    }
    else{
        p = node;
        q = node->esq;
        while(q->dir){
            p = q;
            q = q->dir;
        }
        if(p != node){
            p->dir = q->esq;
            q->esq = node->esq;
        }
        q->dir = node->dir;
    }
    if(parent == nullptr) raiz = q;
    else if(ch < parent->chave) parent->esq = q;
    else parent->dir = q;
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