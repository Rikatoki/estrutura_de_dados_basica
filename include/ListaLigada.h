#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#define MAX 50
#define INVALIDO -1

struct REGISTRO{
    //Identificador
    int chave;

    std::string nome;
    int idade;
    //Outros dados...
};

struct ELEMENTO{
    REGISTRO reg;
    int prox;
};

struct ListaLigada{
    ELEMENTO A[MAX];
    int inicio;
    int dispo;
    //Inicialização
    ListaLigada();
    //Pega o índice do dispónivel
    int obterNo();
    //Devolve tal valor para a lista de disponíveis
    void devolverNo(int i);
    //Exibir todos os elementos da lista
    void exibir();
    //insere tal valor ao início da lista | inserir_inicio <-> busca <-> remover 
    bool inserir_inicio(REGISTRO reg);
    //Busca um elemento interando por todos sequencialmente |  busca <-> inserir_inicio <-> remover
    int busca(int ch);
    //Remover um elemento | remover <-> inserir_inicio <-> busca 
    bool remover(int ch);
};

#endif