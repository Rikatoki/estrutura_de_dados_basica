#ifndef LISTALIGADADINAMICA_H
#define LISTALIGADADINAMICA_H

#include <string>

struct TAREFA{
    int chave;
    std::string título;
    std::string descricao ;
    std::string prioridade;
};
struct Node{
    TAREFA A;
    struct Node* next;
    Node(TAREFA taf);
};
typedef Node* PONT;

struct LinkedListDinamic{
    PONT inicio;
    LinkedListDinamic();
    // Busca um elemento pela chave (ch).
    // Retorna um ponteiro para o nó encontrado ou NULL se não existir.
    // O parâmetro 'ant' (ponteiro para ponteiro) retorna o nó anterior ao encontrado.
    PONT busca(int ch, PONT* ant);

    // Insere uma nova tarefa (taf) mantendo a lista ordenada pela chave.
    // Retorna false se já existir um elemento com a mesma chave, true se inseriu.
    bool inserirOrd(TAREFA taf);

    // Remove um elemento com a chave (ch) da lista.
    // Retorna false se a chave não existir, true se removeu.
    bool remover(int ch);

    // Retorna a quantidade de elementos na lista.
    int tamanho();

    // Mescla outra lista ordenada (lista) na lista atual, preservando a ordem.
    // Elementos duplicados (mesma chave) são ignorados.
    bool mesclarlistas(LinkedListDinamic* lista);

    // Remove todos os elementos da lista, deixando-a vazia.
    bool reiniciarlista();

    // Insere um elemento (taf) no final da lista, ignorando ordenação.
    // Retorna false se já existir elemento com a mesma chave, true se inseriu.
    bool inserirFim(TAREFA taf);
};
#endif