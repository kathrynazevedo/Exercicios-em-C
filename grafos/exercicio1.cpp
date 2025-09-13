#include <stdio.h>
#include <stdbool.h>

#define MAX 50 // N�mero m�ximo de v�rtices

// Fun��o para imprimir as arestas do grafo
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

// Fun��o para verificar se o grafo � um d�grafo ou n�o
bool isDigrafo(int matriz[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                return true; // � um d�grafo
            }
        }
    }
    return false; // � um grafo n�o-direcionado
}

// Fun��o para calcular o grau de cada v�rtice
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

// Fun��o de DFS para verificar a conex�o e ciclicidade
void DFS(int matriz[MAX][MAX], int n, int v, bool visitado[]) {
    visitado[v] = true;
    for (int i = 0; i < n; i++) {
        if (matriz[v][i] == 1 && !visitado[i]) {
            DFS(matriz, n, i, visitado);
        }
    }
}

// Verifica se o grafo � conexo
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

// Fun��o para imprimir a lista de adjac�ncias
void imprimirListaAdjacencias(int matriz[MAX][MAX], int n) {
    printf("Lista de adjacencias:\n");
    for (int i = 0; i < n; i++) {
        printf("V�rtice %d:", i);
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

    printf("Digite o n�mero de vertices: ");
    scanf("%d", &n);

    printf("Digite a matriz de adjacencias (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // a) Imprimir as arestas
    imprimirArestas(matriz, n);

    // b) Verificar se � d�grafo ou grafo n�o-direcionado
    if (isDigrafo(matriz, n)) {
        printf("O grafo � um digrafo.\n");
    } else {
        printf("O grafo � nao direcionado.\n");
    }

    // c) Calcular o grau de cada v�rtice
    calcularGrau(matriz, n, isDigrafo(matriz, n));

    // d) Verificar se o grafo � conexo ou desconexo
    if (isConexo(matriz, n)) {
        printf("O grafo eh conexo.\n");
    } else {
        printf("O grafo eh desconexo.\n");
    }

    // f) Imprimir a lista de adjac�ncias
    imprimirListaAdjacencias(matriz, n);

    return 0;
}

