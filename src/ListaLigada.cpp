#include "ListaLigada.h"
#include <iostream>

ListaLigada::ListaLigada(){
    for(int i = 0; i < MAX-1; i++){
        A[i].prox = i + 1;
    }
    A[MAX-1].prox = INVALIDO;
    inicio = INVALIDO;
    dispo = 0;
}

int ListaLigada::tamanho(){
    int i = inicio;
    int tam = 0;
    while(i != INVALIDO){
        tam ++;
        i = A[i].prox;
    }
    return tam;
}
void ListaLigada::exibirLista(){
    int i = inicio;
    std::cout << "Lista: \"";
    while(i != INVALIDO){
        std::cout << A[i].reg.chave << " ";
        i = A[i].prox;
    }
    std::cout << "\"\n";
}
int ListaLigada::buscaSeqOrd(int ch){
    int i =  inicio;
    while(i != INVALIDO && A[i].reg.chave < ch){
        i = A[i].prox;
    }
    if(i != INVALIDO && A[i].reg.chave == ch) return i;
    else return INVALIDO;
}
int ListaLigada::obterNo(){
    int resultado = dispo;
    if(dispo != INVALIDO){
        dispo = A[dispo].prox;
    }
    return resultado;
}
bool ListaLigada::appendElemOrd(REGISTRO reg){
    if(dispo == INVALIDO) return false;
    int ant = INVALIDO;
    int i = inicio;
    int ch = reg.chave;
    while((i != INVALIDO) && (A[i].reg.chave < ch)){
        ant = i;
        i = A[i].prox;
    }
    if(i != INVALIDO && A[i].reg.chave == ch) return false;
    i = obterNo();
    A[i].reg = reg;
    if(ant == INVALIDO){
        A[i].prox = inicio;
        inicio = i;
    } else{
        A[i].prox = A[ant].prox;
        A[ant].prox = i;
    }
    return true;
}
bool ListaLigada::excluirElem(int ch){
    int ant = INVALIDO;
    int i = inicio;
    while((i!=INVALIDO) && (A[i].reg.chave < ch)){
        ant = i;
        i = A[i].prox;
    }
    if(i == INVALIDO || A[i].reg.chave != ch) return false;
    if(ant == INVALIDO) inicio = A[i].prox;
    else A[ant].prox = A[i].prox;
    devolverNo(i);
    return true;
}
void ListaLigada::devolverNo(int j){
    A[j].prox = dispo;
    dispo = j;
}
void ListaLigada::reiniciarLista(){
    ListaLigada();
}