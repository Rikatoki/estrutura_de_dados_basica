#include <iostream>
#include "ListaLinear01.h"

//Método para inserir valores ERRO: false
bool ListaLinear01::InserirValor(int l){
    if(NElem < MAX){
        A[NElem] = l;
        NElem++;
        return true;
    }
    return false;
}
//Método para mostar valores da lista
void ListaLinear01::MostrarValores(){
    if(NElem == 0){
        std::cout << "Não há valores.\n";
    }
    std::cout << "Valores: {\n";
    for(int i = 0; i < NElem-1; i++){
        std::cout << A[i] << "\n";
    }
    std::cout << "}\n";
}
//Método para reover um valor de posição x ERRO: false
bool ListaLinear01::RemoverValor(int x){
    int i = BuscaOrdernada(x);
    if(i != -1){
        for(; i < NElem; i++){
            A[i] = A[i+1];
        }
        NElem--;
        return true;
    }
    return false;
}
//Busca Ordenada de um elemento x ERRO> -1
int ListaLinear01::BuscaOrdernada(int x){
    for(int i = 0; i < NElem; i++){
        if(A[i] == x) return i;
    }
    return -1;
}
//Retorna o maior valor da lista ERRO: -1
int ListaLinear01::MaiorValor(){
    int x = A[0];
    if(NElem != 0){
    for(int i=0; i < NElem-1; i++){
        if(A[i] > x) x = A[i];
    }
    return x;
}
    return -1;
}