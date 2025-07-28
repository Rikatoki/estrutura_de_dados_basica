#ifndef LISTALINEAR01_H
#define LISTALINEAR01_H

#include <iostream>
#include <string>
#define MAX 10

//Lista Linear da primeira atividade
struct ListaLinear01{
    int A[MAX]; //atributo, variável onde fica os dados
    int NElem = 0; //atributo, quantidade de elementos (funciona para validade)

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