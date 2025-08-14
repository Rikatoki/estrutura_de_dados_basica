#include "MatrizEsparsa.h"

MATRIZ::MATRIZ(int l, int c){
    linhas = l;
    colunas = c;
    A = (PONT*) new PONT[linhas];
    for(int i = 0; i < l; i++) A[i] = nullptr;
}
bool MATRIZ::append(int l, int c, float val){
    if(l < 0 || l >= linhas || c < 0 || c >= colunas) return false;
    PONT ant = nullptr;
    PONT atual = A[l];
    while(atual != nullptr && atual->coluna < c){
        ant = atual;
        atual = atual->prox;
    }
    if(atual != nullptr && atual->coluna == c){
        if(val == 0){
            if(ant == nullptr)A[l] = atual->prox;
            else ant->prox = atual->prox;
            delete atual;
        }
        else atual->valor = val;
    }
    else{
        PONT novo = (PONT) new No;
        novo->coluna = c;
        novo->valor = val;
        novo->prox = atual;
        if(ant == nullptr) A[l] = novo;
        else ant->prox = novo;
    }
    return true;
}
float MATRIZ::buscar(int l, int c){
    if(l < 0 || l >= linhas || c < 0 || c >= colunas) return 0;
    PONT atual = A[l];
    while(atual != nullptr && atual->coluna < c){
        atual = atual->prox;
    }
    if(atual != nullptr && atual->coluna == c) return atual->valor;
    return 0;
}