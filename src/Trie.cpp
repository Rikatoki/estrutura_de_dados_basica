#include "Trie.h"

no::no(){
    fim = false;
    for(int i = 0; i < alfabeto; i++){
        letras[i] = nullptr;
    }
}

Trie::Trie(){
    raiz = new no();
}
Trie::~Trie(){
    liberar(raiz);
}
void Trie::liberar(PONT node){
    if(!node) return;
    for(int i = 0; i < alfabeto; i++) liberar(node->letras[i]);
    delete node;
}

int Trie::mapearindice(char c){
    return((int)c - (int)'a');
}
void Trie::inserir(std::string chave){
    PONT node = raiz;
    int idx;
    for(int i = 0; i < chave.length(); i++){
        idx = mapearindice(chave[i]);
        if(!node->letras[idx]) node->letras[idx] = new no();
        node = node->letras[idx];
    }
    node->fim = true;
}
bool Trie::buscar(std::string chave){
    PONT node = raiz;
    int idx;
    for(int i = 0; i < chave.length(); i++){
        idx = mapearindice(chave[i]);
        if(!node->letras[idx]) return false;
        node = node->letras[idx];
    }
    return node->fim;
}