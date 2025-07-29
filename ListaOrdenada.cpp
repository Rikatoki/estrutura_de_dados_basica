#include "ListaOrdenada.h"

bool ListaOrdernada::InserirValOrd(std::string x){
    int i;
    if(NElem == 0){
        A[NElem] = x;
        NElem++;
        return true;
    } 
    if (NElem != MAX){
    for(i = NElem-1; i >= 0 && A[i] > x; i--){  
        A[i+1] = A[i];
    }
    A[i+1] = x;
    NElem++;
    return true;
}
    return false;
}
int ListaOrdernada::BuscaSequencial(std::string x){
    int i;
    for(i=0; i < NElem; i++){
        if(A[i] == x) return i;
    }
    return -1;
}
int ListaOrdernada::BuscaSentinela(std::string x){
    int i;
    A[NElem] = x;
    for(i = 0; A[i] != x; i++);
    if(i == NElem) return -1;
    return i;
}
int ListaOrdernada::BuscaBinaria(std::string x){
    int i, esq, dir, meio;
    esq = 0;
    dir = NElem-1;
    meio = 0;
    while((A[meio] != x) && (esq <= dir)){
        meio = (esq + dir) / 2;
        if(A[meio] > x){
            dir = meio - 1;
        } else{
            esq = meio + 1;
        }
    }
    if(A[meio] == x){
        return meio;
    }
    return -1;
}