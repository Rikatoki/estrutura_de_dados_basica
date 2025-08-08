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
    // Construtor: inicializa a lista ligada estática, 
    // configurando todos os índices e a lista de nós livres.
    ListaLigada();

    // Retorna o índice do próximo nó livre disponível na lista de nós livres
    // e atualiza o ponteiro (índice) para o próximo nó livre.
    // Retorna INVALIDO se não houver nós disponíveis (memória cheia).
    int obterNo();

    // Devolve um nó (índice 'i') para a lista de nós livres,
    // permitindo que ele seja reutilizado em futuras inserções.
    void devolverNo(int i);

    // Exibe todos os elementos da lista na ordem de ligação,
    // a partir do índice 'inicio'.
    void exibir();

    // Insere um novo elemento no início da lista não ordenada.
    // Atualiza o índice 'inicio' para o novo nó.
    bool inserir_inicio(REGISTRO reg);

    // Busca sequencial em lista não ordenada.
    // Percorre a lista do índice 'inicio' até encontrar a chave 'ch'.
    // Retorna o índice do nó encontrado ou INVALIDO se não existir.
    int busca(int ch);

    // Remove um elemento com chave 'ch' da lista não ordenada.
    // Ajusta os ponteiros para manter a integridade da lista
    // e devolve o nó removido para a lista de nós livres.
    bool remover(int ch);

    // Insere um novo elemento na lista de forma ordenada por chave.
    // Garante que a ordem seja mantida após a inserção.
    bool inserirOrd(REGISTRO reg);

    // Busca sequencial otimizada para lista ordenada.
    // Para de percorrer assim que encontra chave maior que 'ch'.
    int buscaOrd(int ch);

    // Remove um elemento com chave 'ch' da lista ordenada.
    // Utiliza a mesma lógica de ajuste de ponteiros e devolução do nó.
    bool removerOrd(int ch);
};
#endif