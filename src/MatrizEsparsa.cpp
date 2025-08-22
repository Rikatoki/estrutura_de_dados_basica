#include "MatrizEsparsa.h"
#include <iostream>

MATRIZ::MATRIZ(int lin, int col){
    linhas = lin;
    colunas = col;
    A = (PONT*) new PONT[linhas];
    for(int i = 0; i < linhas; i++) A[i] = nullptr;
}
bool MATRIZ::append(int lin, int col, float valor){
    if(lin < 0 || lin >= linhas || col < 0 || col >= colunas) return false;
    PONT ant = nullptr;
    PONT end = A[lin];
    while(end != nullptr && end->coluna < col){
        ant = end;
        end = end->next;
    }
    if(end != nullptr && end->coluna == col){
        if(valor == 0){
            if(ant == nullptr) A[lin] = end->next;
            else ant->next = end->next;
            delete end;
        }
        else end->dado = valor;
    }
    else{ //Situações: A lista ta vazia e ou chegou no final, ou precisa inserir no meio
        if(valor == 0) return true;
        PONT novo = new NO; novo->dado = valor; novo->next = end; novo->coluna = col;
        if(ant == nullptr) A[lin] = novo; 
        else ant->next = novo;
    }
    return true;
}
void MATRIZ::imprimir(){
    PONT end;
    for(int i = 0; i < linhas; i++){
        end = A[i];
        for(int j = 0; j < colunas; j++){
            std::cout << "[ ";
            if(end != nullptr && end->coluna == j){
                std::cout << end->dado;
                end = end->next;
            }
            else std::cout << 0;
            std::cout << " ]";
        }
        std::cout << std::endl;
    }
}
MATRIZ MATRIZ::transposicao(){
    MATRIZ mat(colunas, linhas);
    for(int i = 0; i < linhas; i++){
        PONT end = A[i];
        while(end != nullptr){
            mat.append(end->coluna, i, end->dado);
            end = end->next;
        }
    }
    return mat;
}
MATRIZ MATRIZ::operator+(MATRIZ &outra){
    //Pega a maior matriz da operação
    int l = linhas > outra.linhas ? linhas : outra.linhas;
    int c = colunas > outra.colunas ? colunas : outra.colunas;
    MATRIZ mC(l, c);
    for(int i = 0; i < l; i++){
        NO* mA = nullptr;
        NO* mB =  nullptr;
        if(i < linhas) mA = A[i];
        if(i < outra.linhas) mB = outra.A[i];
        while(mA != nullptr || mB != nullptr){
            if((mA != nullptr && mB != nullptr) && (mA->coluna == mB->coluna)){
                mC.append(i, mA->coluna, mA->dado + mB->dado);
                mA = mA->next;
                mB = mB->next;
            }
            else if( mA != nullptr && ( mB == nullptr || mA->coluna < mB->coluna )){
                mC.append(i, mA->coluna, mA->dado);
                mA = mA->next;
            } 
            else if( mB != nullptr && ( mA == nullptr || mB->coluna < mA->coluna )){
                mC.append(i, mB->coluna, mB->dado);
                mB = mB->next;
            }
        }
    }
    return mC;
}
MATRIZ MATRIZ::operator*(MATRIZ &outra){
    MATRIZ maC(0,0);
    if(colunas != outra.linhas) return maC;
    int mult;
    maC = MATRIZ(linhas, outra.colunas);
    for(int l = 0; l < maC.linhas; l++){
        for (int c = 0; c < outra.colunas; c++) {
            int mult = 0;
            PONT mA = A[l];
            while (mA != nullptr) {
                int k = mA->coluna; // índice intermediário
                PONT mB = outra.A[k]; // pega a linha k de B
                while (mB != nullptr && mB->coluna < c) {
                    mB = mB->next;
                }
                if (mB != nullptr && mB->coluna == c) {
                    mult += mA->dado * mB->dado;
                }
                mA = mA->next;
            }
            if (mult != 0) {
                maC.append(l, c, mult);
            }
        }
    }
    return maC;
}