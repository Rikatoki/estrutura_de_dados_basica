#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#define MAX 50
#define INVALIDO -1
//Dados a serem guardados
struct REGISTRO{
    int chave;
    //Em construção...
};
//O dado + ponteiro
struct ELEMENTO{
    REGISTRO reg;
    int prox;
};
//Estrutura da lista em si
struct ListaLigada{
    ELEMENTO A[MAX];
    int inicio;
    int dispo;
    //Inicialização
    ListaLigada();
    //Pega o tamanho para fazer loops baseado nele
    int tamanho();
    //Mostra a chave de cada valor registrado
    void exibirLista();
    //A busca sequencial ordenada é mais eficiente que a tradicional
    int buscaSeqOrd(int ch);
    //Retorna o index do disponível e muda o dispo pro próximo dispónivel
    int obterNo();
    //Insere um elemento na lista, ordenado
    bool appendElemOrd(REGISTRO reg);
    //Excluir o elemento da lista
    bool excluirElem(int ch);
    //O elemento se torna o próximo idx e ele é ligado ao próximo da idx
    void devolverNo(int j);
    //Zera a lista
    void reiniciarLista();
};
#endif