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


NAO ESQUECER: ctrl + shift + b para compilar tudo
*/
#include <iostream>
#include <string>
#include "ListaLinear01.h"

int main(){
    std::cout << "Escolha uma atividade\n"
    << "[1] Exercícios básicos -- Lista Linear\n"
    << "[2] Exercícios básicos -- Lista Linear\n"
    << "[0] Sair\n"
    << "Opção: ";
    int opc; std::cin >> opc;
    switch (opc){
    case 1:{
        ListaLinear01 l;
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