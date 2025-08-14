#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H

struct No{
    float valor;
    int coluna;
    struct No* prox;
};
typedef No* PONT;

struct MATRIZ{
    PONT* A;
    int linhas;
    int colunas;
    //INICIALIZAÇÂO
    //Os argunmentos são as linhas e as colunas da matriz
    MATRIZ(int l, int c);
    bool append(int l, int c, float x);
    float buscar(int l, int c);
};

#endif