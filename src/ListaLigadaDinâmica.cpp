#include "ListaLigadaDinâmica.h"

Node::Node(TAREFA taf){
    A = taf;
    next = NULL;
}

LinkedListDinamic::LinkedListDinamic(){
    inicio = NULL;
}
PONT LinkedListDinamic::busca(int ch, PONT* ant){
*ant = NULL;
PONT end =  inicio;
while(end != NULL && end->A.chave < ch){
    *ant =  end;
    end = end->next;
}
return end;
}
bool LinkedListDinamic::inserirOrd(TAREFA taf){
    PONT ant;
    PONT data = busca(taf.chave, &ant);
    if(data != NULL && data->A.chave == taf.chave) return false;
    data = new Node(taf);
    if(ant == NULL){
        inicio = data;
    } else{
        data->next = ant->next;
        ant->next = data;
    }
    return true;
}
bool LinkedListDinamic::remover(int ch){
    PONT ant;
    PONT data = busca(ch, &ant);
    if(data == NULL || data->A.chave != ch) return false;
    if(ant == NULL){
        inicio = data->next;
    }else{
        ant->next = data->next;
    }
    delete data;
    return true;
}
int LinkedListDinamic::tamanho(){
    PONT end = inicio;
    int tam = 0;
    while(end != NULL){
        tam++;
        end = end->next;
    }
    return tam;
}
bool LinkedListDinamic::mesclarlistas(LinkedListDinamic* lista){
    PONT end = lista->inicio;
    while(end != NULL){
        inserirOrd(end->A);
        end = end->next;
    }
    return true;
}
bool LinkedListDinamic::reiniciarlista(){
    PONT end = inicio;
    while(end != NULL){
        PONT ant = end;
        end = end->next;
        delete ant;
    }
    inicio = NULL;
    return true;
}
bool LinkedListDinamic::inserirFim(TAREFA taf){
    PONT end = inicio;
    PONT ant = NULL;
    while(end != NULL){
        if(end->A.chave == taf.chave) return false;
        ant = end;
        end = end->next;
    }
    end = new Node(taf);
    if(ant == NULL)inicio = end; 
    else ant->next = end;
    return true;
}