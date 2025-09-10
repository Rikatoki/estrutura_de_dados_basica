#ifndef TRIE_H
#define TRIE_H

#define alfabeto 26
#include <string>

struct no{
    struct no *letras[alfabeto];
    bool fim;
    no();
};
#define PONT no*

struct Trie{
    PONT raiz;
    Trie();
    ~Trie();
    void liberar(PONT node);
    int mapearindice(char c);
    void inserir(std::string chave);
    bool buscar(std::string chave);
};

#endif