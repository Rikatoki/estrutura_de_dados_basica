#ifndef ARVOREBIN_H
#define ARVOREBIN_H

struct NO{
    int chave;
    //outros dados
    struct NO *dir, *esq;
    NO(int ch);
};

typedef NO* PONT;

struct ArvBin{
    PONT raiz;
    ArvBin();
    void FindParentAndNode(PONT &parent, PONT &node, int ch);
    bool insert(int ch);
    PONT search(int ch);
    bool removerElem(int ch);
    void elementos(PONT node, int &cont);
    int contagem();
    void imprirec(PONT node);
    void imprimir();
    void delrec(PONT &raiz);
    ~ArvBin();
};

#endif