# Estruturas de Dados Básicas em C++

Este projeto foi criado para demonstrar e consolidar meu conhecimento sobre estruturas de dados utilizando C++. O objetivo principal é servir como um repositório pessoal de estudo, facilitando revisões, testes e manipulações dos conceitos fundamentais de listas e métodos de busca.

## Sobre o Projeto

- **Uso pessoal:** Este repositório é voltado para estudo e prática individual.
- **Organização:** O código está dividido em módulos para facilitar a manutenção e o entendimento.
- **Estruturas implementadas:** Listas lineares, listas ordenadas e listas ligadas.

## Estrutura de Pastas

```
estrutura_de_dados_basica/
├── include/         # Arquivos de cabeçalho (.h)
├── src/             # Arquivos de implementação (.cpp)
├── .vscode/         # Configurações do VS Code
├── README.md        # Este arquivo
```

## Funcionalidades

- **Lista Linear de inteiros**
  - Inserção manual
  - Impressão dos valores
  - Remoção de valores
  - Busca do maior valor

- **Lista Ordenada de strings**
  - Inserção automática em ordem crescente
  - Busca sequencial
  - Busca sentinela
  - Busca binária

- **Lista Ligada**
  - Inserção ordenada
  - Exclusão de elementos
  - Exibição da lista
  - Busca sequencial ordenada

## Como Compilar e Executar

1. Clone o repositório:
   ```bash
   git clone https://github.com/Rikatoki/estrutura_de_dados_basica.git
   cd estrutura_de_dados_basica
   ```
2. Compile usando o comando abaixo (Linux):
   ```bash
   g++ -std=c++17 -Iinclude src/main.cpp src/ListaLinear.cpp src/ListaOrdenada.cpp src/ListaLigada.cpp -o programa
   ```
3. Execute o programa:
   ```bash
   ./programa
   ```

> **Observação:** O projeto foi desenvolvido e testado com o compilador g++ no Linux.

## Observações Finais

Este projeto é de uso pessoal e está em constante evolução conforme avanço nos estudos. Sinta-se à vontade para explorar, modificar e adaptar conforme sua necessidade de aprendizado.