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



## Projeto 5 🗳️ Sistema de Votação para TCCs em C

Este projeto é um sistema de votação via terminal, desenvolvido em linguagem C, projetado para simular a eleição dos melhores Trabalhos de Conclusão de Curso (TCC). A principal característica do sistema é a manipulação e persistência de dados através de arquivos de texto (.txt), permitindo que os votos e os eleitores sejam salvos entre as execuções do programa.

### 🔹 Funcionalidades
- Votação por CPF: O voto é registrado através do CPF do eleitor, que deve conter 11 dígitos.
- Cadastro Dinâmico de Eleitores: Se um CPF válido ainda não estiver cadastrado no sistema, o programa solicita o nome do eleitor e o adiciona à base de dados.
- Prevenção de Votos Duplos: O sistema impede que um mesmo CPF vote mais de uma vez durante a mesma sessão de uso.
- Persistência de Dados: Todas as alterações, como novos eleitores e a contagem de votos, são salvas nos arquivos .txt ao final da execução.
- Ranking em Tempo Real: Exibe uma lista ordenada dos TCCs mais votados.
- Listagem de Dados: Permite visualizar os TCCs concorrentes e a lista de eleitores já cadastrados.

### ⚙️ Como Funciona
O programa opera com base em dois arquivos de dados principais:

↬ tc.txt: Contém a lista de trabalhos concorrentes e sua contagem de votos.
↬ votos.txt: Armazena os dados dos eleitores (CPF e nome) que já participaram da votação.

Ao iniciar, o sistema carrega os dados desses arquivos para a memória. Durante a execução, toda a manipulação (como adicionar um voto ou um novo eleitor) ocorre em memória. Ao escolher a opção "Sair", o programa reescreve os arquivos tc.txt e votos.txt, garantindo que os dados atualizados sejam persistidos para a próxima execução.

### 📌 Exemplo de execução
```
4
1 201 101 "Estudo sobre Inteligência Artificial" 5
2 202 102 "Simulação de Software Quântico" 8
3 203 103 "Análise de Banco de Dados NoSQL" 2
4 204 104 "Desenvolvimento de Hardware Embarcado" 11
```
votos.txt
A primeira linha contém o número total de eleitores cadastrados.

As linhas seguintes contêm os dados de cada eleitor no formato:
CPF Nome Sobrenome

Exemplo:
```
3
12345678901 Nome Exemplo Um
98765432109 Outro Exemplo Silva
11122233344 Eleitor Teste
```
### ▶️ Como compilar e executar 

Clone o repositório ou baixe os arquivos.

Abra o terminal na pasta onde os arquivos estão localizados.

Compile o código-fonte. Supondo que o arquivo se chame main.c, use o seguinte comando:

````
gcc -o votacao main.c
````

---
## 📌 Observações

Cada projeto possui seu próprio arquivo main.c.

Para testar um projeto, substitua o conteúdo de main.c pelo respectivo código.

Todos os códigos foram compilados e testados com GCC.



## ✨ Autora

Projetos desenvolvidos por **Kathryn Azevedo** durante estudos de Estruturas de Dados em C.

