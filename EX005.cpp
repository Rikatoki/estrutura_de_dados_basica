// Exercícios especialmente de estruturas de dados :)

/*
📦 1. Lista Linear (vetor)
🔹 Exercícios básicos
Crie uma lista de inteiros com capacidade para 10 números e:

Insira valores manualmente

Imprima a lista

Remova um número de uma posição

Escreva uma função que retorne o maior valor da lista.

🔥 Desafios
Faça uma função que insira em ordem crescente automaticamente.

Faça uma função que inverta a lista ([1, 2, 3] → [3, 2, 1]).


🔍 2. Busca (sequencial, ordenada, binária, sentinela)
🔹 Exercícios básicos
Dado um vetor de strings ordenado, implemente:

Busca sequencial

Busca binária

Dado um vetor de inteiros desordenado, implemente:

Busca sentinela

🔥 Desafios
Escreva uma função que receba uma lista de nomes e busque um nome com busca binária, ignorando maiúsculas/minúsculas.

Faça uma função que conte quantas vezes um valor aparece na lista.


🔗 3. Lista Ligada (simples)
🔹 Exercícios básicos
Crie uma lista ligada de inteiros.

Função para inserir no início

Função para imprimir

Adicione função de remoção de um valor.

🔥 Desafios
Implemente uma função para inserir em ordem crescente.

Faça uma função que busque um valor na lista e diga em qual posição está.

*/
#include <iostream>
#include <string>

#define MAX 10
//Lista Linear para a primeira atividade
struct LISTA001{
    int A[MAX]; //atributo, variável onde fica os dados
    int NElem = 0; //atributo, quantidade de elementos (funciona para validade)

    //Método para inserir valores ERRO: false
    bool InserirValor(int l){
        if(NElem < MAX){
            A[NElem] = l;
            NElem++;
            return true;
        }
        return false;
    }
    //Método para mostar valores da lista
    void MostrarValores(){
        if(NElem == 0){
            std::cout << "Não há valores.\n";
        }
        std::cout << "Valores: {\n";
        for(int i = 0; i < NElem-1; i++){
            std::cout << A[i] << "\n";
        }
        std::cout << "}\n";
    }
    //Método para reover um valor de posição x ERRO: false
    bool RemoverValor(int x){
        int i = BuscaOrdernada(x);
        if(i != -1){
            for(; i < NElem; i++){
                A[i] = A[i+1];
            }
            NElem--;
            return true;
        }
        return false;
    }
    //Busca Ordenada de um elemento x ERRO> -1
    int BuscaOrdernada(int x){
        for(int i = 0; i < NElem; i++){
            if(A[i] == x) return i;
        }
        return -1;
    }
    //Retorna o maior valor da lista ERRO: -1
    int MaiorValor(){
        int x = A[0];
        if(NElem != 0){
        for(int i=0; i < NElem-1; i++){
            if(A[i] > x) x = A[i];
        }
        return x;
    }
        return -1;
    }
};

int main(){
    std::cout << "Escolha uma atividade\n"
    << "[1] Exercícios básicos -- Lista Linear\n"
    << "[2] Exercícios básicos -- Lista Linear\n"
    << "[0] Sair\n"
    << "Opção: ";
    int opc; std::cin >> opc;
    switch (opc){
    case 1:{
        LISTA001 l;
        while(true){
            std::cout << "Lista de 10 números inteiros\n"
            << "[1] - Inserir valor;\n"
            << "[2] - Impremir valores;\n"
            << "[3] - Remover valor;\n"
            << "[4] - Maior valor da lista;\n"
            << "[0] - Voltar;\n"
            << "Opção: ";
            int op; std::cin >> op;
            if(op == 0){
                break;
            }
            switch (op)
            {
            case 1:
                if(l.NElem < MAX-1){
                    int o = 1;
                    while(o != 0){
                        std::cout << "\nValor (0 para sair): ";
                        std::cin >> o;
                        l.InserirValor(o);
                    }
                }
                break;
            case 2:{
                l.MostrarValores();
                break;
            }
            case 3:{
                l.MostrarValores();
                std::cout << "Digite o valor que deseja remover: ";
                int x; std::cin >> x;
                l.RemoverValor(x);
                break;
            }
            case 4:{
                std::cout << "\nO maior valor é: " << l.MaiorValor() << "\n";
                break;
            }
        }}
        break;
    }
    case 2:{
        break;
    }}
    if(opc == 0){
        return 0;
    }
    return 0;}