#include <stdio.h>

#define MAX 100 // N�mero m�ximo de v�rtices

// Fun��o para imprimir a matriz de adjac�ncias
void imprimirMatrizAdjacencias(int matriz[MAX][MAX], int n) {
    printf("Matriz de adjac�ncias:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Fun��o para imprimir a lista de adjac�ncias
void imprimirListaAdjacencias(int matriz[MAX][MAX], int n) {
    printf("Lista de adjac�ncias:\n");
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

    printf("Digite o n�mero de v�rtices (n): ");
    scanf("%d", &n);

    // Gerar a matriz de adjac�ncias para o grafo completo K_n
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                matriz[i][j] = 1; // Todos os v�rtices est�o conectados, exceto a si mesmos
            } else {
                matriz[i][j] = 0; // Diagonal principal � zero
            }
        }
    }

    // Imprimir a matriz de adjac�ncias
    imprimirMatrizAdjacencias(matriz, n);

    // Imprimir a lista de adjac�ncias
    imprimirListaAdjacencias(matriz, n);

    return 0;
}

