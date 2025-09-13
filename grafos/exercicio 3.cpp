#include <stdio.h>

#define MAX 100 // N�mero m�ximo de v�rtices

// Fun��o para imprimir as arestas e seus pesos
void imprimirArestas(int matriz[MAX][MAX], int n) {
    printf("Arestas do grafo com seus pesos:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Percorre apenas a metade superior da matriz para evitar repeti��o
            if (matriz[i][j] != 0) {
                printf("(%d, %d) - Peso: %d\n", i, j, matriz[i][j]);
            }
        }
    }
}

int main() {
    int n;
    int matriz[MAX][MAX];

    printf("Digite o numero de vertices: ");
    scanf("%d", &n);
    
    printf("OBS: Nao esqueca do espacamento a cada numero \n \n");
    printf("Digite a matriz de adjac�ncias ponderada (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir as arestas e seus pesos
    imprimirArestas(matriz, n);

    return 0;
}


