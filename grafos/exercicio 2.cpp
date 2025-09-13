#include <stdio.h>

#define MAX 100 // Número máximo de vértices

// Função para imprimir a matriz de adjacências
void imprimirMatrizAdjacencias(int matriz[MAX][MAX], int n) {
    printf("Matriz de adjacências:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para imprimir a lista de adjacências
void imprimirListaAdjacencias(int matriz[MAX][MAX], int n) {
    printf("Lista de adjacências:\n");
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

    printf("Digite o número de vértices (n): ");
    scanf("%d", &n);

    // Gerar a matriz de adjacências para o grafo completo K_n
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                matriz[i][j] = 1; // Todos os vértices estão conectados, exceto a si mesmos
            } else {
                matriz[i][j] = 0; // Diagonal principal é zero
            }
        }
    }

    // Imprimir a matriz de adjacências
    imprimirMatrizAdjacencias(matriz, n);

    // Imprimir a lista de adjacências
    imprimirListaAdjacencias(matriz, n);

    return 0;
}

