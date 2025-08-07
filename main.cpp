#include <iostream>
#include <string>

#include "include/ListaLinear.h"
#include "include/ListaOrdenada.h"

int main(){
    std::cout << "Escolha uma atividade\n"
    << "[1] Exercícios básicos -- Lista Linear\n"
    << "[2] Exercícios básicos -- Lista Linear\n"
    << "[0] Sair\n"
    << "Opção: ";
    int opc; std::cin >> opc;
    if(opc == 0) return 0;

    switch (opc){
    case 1:{
        ListaLinear l;
        while(true){
            std::cout << "Lista de 10 números inteiros\n"
            << "[1] - Inserir valor;\n"
            << "[2] - Impremir valores;\n"
            << "[3] - Remover valor;\n"
            << "[4] - Maior valor da lista;\n"
            << "[0] - Voltar;\n"
            << "Opção: ";
            int op; std::cin >> op;
            if(op == 0) break;
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
        ListaOrdernada l;
        while(true){
            std::cout << "Lista Ordernada feita de strings\n"
            << "[1] - Inserir valor;\n"
            << "[2] - Busca Sequencial;\n"
            << "[3] - Busca Sentinela;\n"
            << "[4] - Busca Binária;\n"
            << "[0] - Voltar;\n"
            << "Opção: ";
            int op; std::cin >> op;
            if(op == 0) break;
            std::string x;
            int n;
            switch (op)
            {
            case 1:
                std::cout << "Insira um valor (string): ";
                std::cin >> x;
                l.InserirValOrd(x);
                break;
            case 2:
                std::cout << "Digite a string que deseja procurar: ";
                std::cin >> x;
                n = l.BuscaSequencial(x); 
                if (n != -1){
                    std::cout << "O index do valor é: " << n << std::endl;
                }
                else std::cout << "Não há essa string na lista." << std::endl;
                break;
            
            case 3:
                std::cout << "Digite a string que deseja procurar: ";
                std::cin >> x;
                n = l.BuscaSentinela(x); 
                if (n != -1){
                    std::cout << "O index do valor é: " << n << std::endl;
                }
                else std::cout << "Não essa string na lista." << std::endl;
                break;
            case 4:
                std::cout << "Digite a string que deseja procurar: ";
                std::cin >> x;
                n = l.BuscaBinaria(x); 
                if (n != -1) std::cout << "O index do valor é: " << n << std::endl;
                else std::cout << "Não há essa string na lista." << std::endl;
                break;
            }
    }}
    return 0;
}}