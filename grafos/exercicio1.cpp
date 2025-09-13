#include <stdio.h>
#include <stdbool.h>

#define MAX 50 // Número máximo de vértices

// Função para imprimir as arestas do grafo
void imprimirArestas(int matriz[MAX][MAX], int n) {
    printf("Arestas do grafo:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == 1) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }
}

// Função para verificar se o grafo é um dígrafo ou não
bool isDigrafo(int matriz[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                return true; // É um dígrafo
            }
        }
    }
    return false; // É um grafo não-direcionado
}

// Função para calcular o grau de cada vértice
void calcularGrau(int matriz[MAX][MAX], int n, bool digrafo) {
    printf("Grau de cada vertice:\n");
    for (int i = 0; i < n; i++) {
        int grau = 0;
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == 1) {
                grau++;
            }
        }
        printf("Vertice %d: %d\n", i, grau);
    }
}

// Função de DFS para verificar a conexão e ciclicidade
void DFS(int matriz[MAX][MAX], int n, int v, bool visitado[]) {
    visitado[v] = true;
    for (int i = 0; i < n; i++) {
        if (matriz[v][i] == 1 && !visitado[i]) {
            DFS(matriz, n, i, visitado);
        }
    }
}

// Verifica se o grafo é conexo
bool isConexo(int matriz[MAX][MAX], int n) {
    bool visitado[MAX] = {false};
    DFS(matriz, n, 0, visitado);

    for (int i = 0; i < n; i++) {
        if (!visitado[i]) {
            return false;
        }
    }
    return true;
}

// Função para imprimir a lista de adjacências
void imprimirListaAdjacencias(int matriz[MAX][MAX], int n) {
    printf("Lista de adjacencias:\n");
    for (int i = 0; i < n; i++) {
        printf("Vértice %d:", i);
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == 1) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matriz[MAX][MAX];

    printf("Digite o número de vertices: ");
    scanf("%d", &n);

    printf("Digite a matriz de adjacencias (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // a) Imprimir as arestas
    imprimirArestas(matriz, n);

    // b) Verificar se é dígrafo ou grafo não-direcionado
    if (isDigrafo(matriz, n)) {
        printf("O grafo é um digrafo.\n");
    } else {
        printf("O grafo é nao direcionado.\n");
    }

    // c) Calcular o grau de cada vértice
    calcularGrau(matriz, n, isDigrafo(matriz, n));

    // d) Verificar se o grafo é conexo ou desconexo
    if (isConexo(matriz, n)) {
        printf("O grafo eh conexo.\n");
    } else {
        printf("O grafo eh desconexo.\n");
    }

    // f) Imprimir a lista de adjacências
    imprimirListaAdjacencias(matriz, n);

    return 0;
}

