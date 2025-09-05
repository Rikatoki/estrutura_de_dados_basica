#ifndef ARVNARIA_H
#define ARVNARIA_H
// Cada nó da árvore N-ária
// ch -> identificador do nó (poderia ser um id, chave, ou valor)
// filho -> aponta para o primeiro filho direto do nó
// irmao -> aponta para o próximo nó que compartilha o mesmo pai
struct NO{
    int ch;         // identificador ou valor do nó
    // aqui poderiam ser adicionados outros dados, dependendo do sistema
    NO* filho;      // ponteiro para o primeiro filho
    NO* irmao;      // ponteiro para o próximo irmão (mesmo pai)
    NO(int ch);     // construtor para inicializar
};

typedef NO* PONT;   // definição de tipo para facilitar a leitura do código

// Estrutura que representa a árvore N-ária
// Essa estrutura é flexível, podendo servir de base para sistemas mais complexos
// (com botões, regras, menus, ou hierarquias organizacionais).
struct NAria{
    PONT raiz;  // a árvore sempre começa com uma raiz definida

    // Construtor: cria a árvore com uma raiz
    NAria(int ch);

    // Insere um novo nó como filho do pai indicado
    // Obs: a inserção não mantém ordem, o novo filho é colocado no início da lista de filhos
    bool insert(int pai, int novo);

    // Busca um nó de forma recursiva
    // Importante: não é uma árvore de busca binária, portanto a busca não é otimizada
    PONT search(PONT no, int chave);

    // Busca o "pai" de um nó (antecessor direto)
    PONT searchant(PONT no, int chave);

    // Exclusão de um nó:
    // Aqui, a regra definida foi que ao deletar um nó,
    // todos os seus filhos e descendentes também são apagados.
    bool del(int ch);

    // Função auxiliar recursiva para apagar todos os descendentes de um nó
    void delrec(PONT no);
};
#endif