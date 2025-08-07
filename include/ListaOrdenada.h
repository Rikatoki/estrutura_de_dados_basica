#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include <iostream>
#include <string>

#define MAX 10
//Esta lista será usada para criar as buscas
struct ListaOrdernada{
    std::string A[MAX+1];
    int NElem = 0;

    bool InserirValOrd(std::string x);

    //Nada demais, vai um por um.
    int BuscaSequencial(std::string x);

    //O uso de um "Sentinela" diminui as verificações feita na interação
    int BuscaSentinela(std::string x);

    //A que a mais gosto e também uma das formas mais eficientes, porém, só funciona em lista ordenada.
    int BuscaBinaria(std::string x);
};

#endif