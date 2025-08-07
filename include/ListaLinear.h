#ifndef LISTALINEAR_H
#define LISTALINEAR_H

#include <iostream>

#define MAX 10
//Lista Linear, não a mais eficiente, mas uma que ensina bem
struct ListaLinear{
    int A[MAX];
    int NElem = 0;

    //Método para inserir valores |ERRO: false
    bool InserirValor(int l);

    //Imprime no console
    void MostrarValores();

    //Método para reover um valor de posição x |ERRO: false
    bool RemoverValor(int x);

    //Busca Ordenada de um elemento x |ERRO: -1
    int BuscaOrdernada(int x);

    //Retorna o maior valor da lista |ERRO: -1
    int MaiorValor();
};

#endif