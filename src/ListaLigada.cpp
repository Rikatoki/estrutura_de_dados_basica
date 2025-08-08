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

//Lista Ordenada
bool ListaLigada::inserirOrd(REGISTRO reg){
    int i = inicio;
    int ant = INVALIDO;
    while(i !=  INVALIDO && A[i].reg.chave < reg.chave){
        ant =  i;
        i = A[i].prox;
    }
    if(i != INVALIDO && A[i].reg.chave == reg.chave) return false; //Previnir valores identicos
    int n = obterNo();
    if(n == INVALIDO) return false;

    A[n].reg = reg;
    A[n].prox = i;

    if(ant == INVALIDO) inicio = n; //Primeiro da listainicio 
    else A[ant].prox = n;

    return true;
}
//Lista Ordenada
int ListaLigada::buscaOrd(int ch){
    int i = inicio;
    while(i != INVALIDO && A[i].reg.chave < ch) i = A[i].prox;
    if(i == INVALIDO || A[i].reg.chave != ch) return INVALIDO;
    return i;
}
//Lista Ordenada
bool ListaLigada::removerOrd(int ch){
    if(inicio == INVALIDO) return false;
    int i = inicio;
    int ant = INVALIDO;
    while(i != INVALIDO && A[i].reg.chave < ch){
        ant = i;
        i = A[i].prox;
    }
    if(i == INVALIDO || A[i].reg.chave != ch) return false;
    if(ant != INVALIDO){
        A[ant].prox = A[i].prox;
    } else{
        inicio = A[i].prox;
    }
    devolverNo(i);
    return true;
}