# 📘 Projetos em C e C++

Este repositório contém alguns projetos em linguagem **C++** que exploram diferentes estruturas de dados e algoritmos fundamentais feitos no quarto semestre da faculdade de Ciência da Computação.  

---

## 🚀 Projeto 1 - Manipulação de Heap em C

Este projeto demonstra a manipulação de uma estrutura de dados do tipo **Max-Heap** para encontrar os dois maiores elementos em um array.  
A implementação utiliza as funções **Sift** e **BuildHeap** para garantir a propriedade de Max-Heap, onde cada nó pai é sempre maior que seus filhos.  

### 🔹 Funcionalidades
- **Geração de Dados**: Cria um array preenchido com números inteiros aleatórios.  
- **Construção de Heap**: Converte o array em um Max-Heap com o algoritmo `BuildHeap`.  
- **Busca dos Maiores Elementos**: Identifica de forma eficiente os dois maiores valores no Heap.  

### ▶️ Como compilar e executar
```
gcc -o main main.c
./main
```
---


## 📂 Projeto 2 - Gerador de Subconjuntos em C

Este projeto implementa um algoritmo recursivo de backtracking para gerar e listar todos os subconjuntos de um conjunto de inteiros de 1 até n.
É uma ótima demonstração prática de recursão aplicada à combinatória.

### 🔹 Funcionalidades

Geração Recursiva: Explora todas as combinações possíveis de inclusão/exclusão de elementos.

Impressão Organizada: Exibe cada subconjunto de forma legível.

Contagem de Subconjuntos: Numera cada subconjunto gerado.

### 📌 Exemplo de execução
```
Entrada: n = 3

Saída:

1 subconjunto: 1 2 3
2 subconjunto: 1 2
3 subconjunto: 1 3
4 subconjunto: 1
5 subconjunto: 2 3
6 subconjunto: 2
7 subconjunto: 3
8 subconjunto:
```
### ▶️ Como compilar e executar
```
gcc -o main main.c
./main
```

----

## 🔑 Projeto 4 - Tabela Hash com Sondagem Linear em C

Este projeto apresenta a implementação de uma Tabela Hash utilizando sondagem linear para tratamento de colisões.
É uma estrutura de dados essencial para acesso rápido a informações.

### 🔹 Funcionalidades

Função Hash: Mapeia chaves para índices da tabela.

Sondagem Linear: Resolve colisões procurando a próxima posição livre.

Operações Básicas: Inserção, busca e remoção de elementos.

Tratamento de Colisões: Garante robustez na inserção mesmo em cenários de colisão.

### ▶️ Como compilar e executar
```
gcc -o main main.c
./main
```

---
## 📌 Observações

Cada projeto possui seu próprio arquivo main.c.

Para testar um projeto, substitua o conteúdo de main.c pelo respectivo código.

Todos os códigos foram compilados e testados com GCC.

## ✨ Autora

Projetos desenvolvidos por **Kathryn Azevedo** durante estudos de Estruturas de Dados em C.

