#include <stdio.h>
#include <stdbool.h>

#define TAM_MAX 7

//PARTE HASH.JAVA
typedef struct {
    double item;
    bool ocupado;
} Hash;

typedef struct {
    Hash tab[TAM_MAX];
} HashLinear;

// Inicializa a tabela hash
void inicializaHash(HashLinear *h) {
    for (int i = 0; i < TAM_MAX; i++) {
        h->tab[i].ocupado = false;
    }
}

// HASHLINEAR.JAVA
int funcaoHash(double chave) {
    int v = (int)chave;
    return (v < 0 ? -v : v) % TAM_MAX;
}

// Verifica se a tabela está cheia
bool cheia(HashLinear *h) {
    int qtde = 0;
    for (int i = 0; i < TAM_MAX; i++) {
        if (h->tab[i].ocupado) {
            qtde++;
        }
    }
    return qtde == TAM_MAX;
}

// Insere um item na tabela hash
void insere(HashLinear *h, double item) {
    if (cheia(h)) {
        printf("\n-> ATENCAO: Tabela cheia\n");
        return;
    }

    int pos = funcaoHash(item);
    
    // Tratamento de colisão
    if (h->tab[pos].ocupado) {
        if (h->tab[pos].item == item) {
            printf("\n-> ATENCAO: Esse item ja foi cadastrado\n");
            return;
        }
        
        printf("-> Ocorreu uma colisao na posicao %d\n", pos);
        while (h->tab[pos].ocupado) {
            pos = (pos + 1) % TAM_MAX;
        }
    }

    h->tab[pos].item = item;
    h->tab[pos].ocupado = true;
    printf("-> Inserido HASH[%d]\n", pos);
}

// Busca um item na tabela hash
int busca(HashLinear *h, double chave) {
    int pos = funcaoHash(chave);
    int inicioBusca = pos;

    while (h->tab[pos].ocupado) {
        if (h->tab[pos].item == chave) {
            return pos;
        }
        pos = (pos + 1) % TAM_MAX;
        if (pos == inicioBusca) {
            break;
        }
    }
    return -1;
}

// Remove um item da tabela hash
void apaga(HashLinear *h, double chave) {
    int pos = busca(h, chave);
    if (pos != -1) {
        h->tab[pos].ocupado = false;
        printf("-> Dado HASH[%d] apagado\n", pos);
    } else {
        printf("Item nao encontrado\n");
    }
}

// Imprime a tabela hash
void imprime(HashLinear *h) {
    for (int i = 0; i < TAM_MAX; i++) {
        if (h->tab[i].ocupado) {
            printf("Hash[%d] = %.2f\n", i, h->tab[i].item);
        }
    }
}
//HASHTABLELINERAR.java
int main() {
    HashLinear tab;
    inicializaHash(&tab);
    double item;

    printf("\n*********************************************************************\n");
    printf("Tabela HASH com tratamento de colisoes Linear (7 itens reais - double)\n");
    printf("*********************************************************************\n");

    for (int i = 0; i < TAM_MAX; i++) {
        printf("\n\nInserindo elemento %d", i + 1);
        printf(" - Forneca valor real: ");
        scanf("%lf", &item);
        insere(&tab, item);
    }

    printf("\n\nBuscando campo\n>>> Forneca o item: ");
    scanf("%lf", &item);
    int pos = busca(&tab, item);
    if (pos != -1) {
        printf("Item encontrado na posicao %d\n", pos);
    } else {
        printf("Item nao encontrado\n");
    }

    printf("\n\nApagando campo\n>>> Forneca o item: ");
    scanf("%lf", &item);
    apaga(&tab, item);

    printf("\n\nImprimindo conteudo\n");
    imprime(&tab);

    return 0;
}

