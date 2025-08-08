#include "ListaLigada.h"
#include <iostream>

ListaLigada::ListaLigada(){
    inicio = INVALIDO;
    dispo = 0;
    for(int i = 0; i < MAX-1; i++){
        A[i].prox = i+1;
    }
    A[MAX-1].prox = INVALIDO;
}

int ListaLigada::obterNo(){
    int no = dispo;
    if(dispo != INVALIDO) dispo = A[dispo].prox;
    return no;
}
void ListaLigada::devolverNo(int i){
    A[i].prox = dispo;
    dispo = i;
}
void ListaLigada::exibir(){
    std::cout << "Valores: \n";
    for(int i = inicio; i != INVALIDO; i = A[i].prox){
        std::cout << "[ " << A[i].reg.chave << " | " << A[i].reg.nome << " ]\n";
    }
}
//lista desordenada
bool ListaLigada::inserir_inicio(REGISTRO reg){
    int i = obterNo();
    if(i == INVALIDO) return false; //Memória cheia
    A[i].reg = reg;
    A[i].prox = inicio;
    inicio = i;
    return true;
}
//lista desordenada
int ListaLigada::busca(int ch){
    int i = inicio;
    while(i != INVALIDO && A[i].reg.chave != ch) 
        i = A[i].prox;
    return i;
}
//lista desordenada
bool ListaLigada::remover(int ch){
    int i = inicio;
    int ant = INVALIDO;
    while(i != INVALIDO && A[i].reg.chave != ch){
        ant = i;
        i = A[i].prox;
    }
    if(i == INVALIDO) return false; //Valor não encontrado

    if(ant == INVALIDO) inicio = A[inicio].prox;
    else A[ant].prox = A[i].prox;

    devolverNo(i);
    return true;
}