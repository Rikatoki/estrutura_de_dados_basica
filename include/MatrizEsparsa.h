#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H

struct NO{
    float dado;
    struct NO* next;
    int coluna;
};

#define PONT NO*

struct MATRIZ{
    PONT* A;
    int linhas;
    int colunas;
    MATRIZ(int lin, int col);
    bool append(int lin, int col, float valor);
    void imprimir();
    MATRIZ transposicao();
    MATRIZ operator+(MATRIZ &outra);
    MATRIZ operator*(MATRIZ &outra);
};
#endif