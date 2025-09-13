#include <stdio.h>

#define MAX 100 // N�mero m�ximo de v�rtices

// Fun��o para imprimir a matriz completa
void imprimirMatriz(int matriz[MAX][MAX], int n) {
    printf("Matriz de adjacencias completa:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matriz[MAX][MAX] = {0}; // Inicializa a matriz com 0

    // Abre o arquivo para leitura
    FILE *arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // L� a dimens�o da matriz
    fscanf(arquivo, "%d", &n);

    // L� a matriz triangular inferior do arquivo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            fscanf(arquivo, "%d", &matriz[i][j]);
            // Preencher a parte sim�trica superior
            if (i != j) {
                matriz[j][i] = matriz[i][j];
            }
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Imprimir a matriz completa
    imprimirMatriz(matriz, n);

    return 0;
}

