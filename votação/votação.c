#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> // Biblioteca para a fun��o isspace

// --- DEFINI��O DE ESTRUTURAS ---

typedef struct {
    int codigoTC;
    int alunoAutor; // Mantido para compatibilidade com o formato do tc.txt
    int professorOrientador; // Mantido para compatibilidade com o formato do tc.txt
    char titulo[100];
    int votos;
} TrabalhoConclusao;

typedef struct {
    char cpf[12];
    char nome[50];
    int votou;  // Usado apenas durante a execu��o para evitar voto duplo na mesma sess�o
    int votoTC; // Usado apenas durante a execu��o
} Eleitor;

// --- VARI�VEIS GLOBAIS ---

TrabalhoConclusao tcs[100];
Eleitor eleitores[100]; // Array 'comissao' renomeado para 'eleitores'
int qtdeTCs, qtdeEleitores;

// --- FUN��ES DE LEITURA E ESCRITA ---

// Fun��o auxiliar para limpar espa�os em branco
char *trim(char *str) {
    char *end;
    while(isspace((unsigned char)*str)) str++;
    if(*str == 0) return str;
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

void lerTCs() {
    FILE *file = fopen("tc.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo tc.txt\n");
        exit(1);
    }
    if (fscanf(file, "%d", &qtdeTCs) != 1) {
        qtdeTCs = 0;
        fclose(file);
        return;
    }
    fgetc(file);
    int i;
    for (i = 0; i < qtdeTCs; i++) {
        char buffer[256];
        if (fgets(buffer, sizeof(buffer), file) == NULL) break;
        sscanf(buffer, "%d %d %d", &tcs[i].codigoTC, &tcs[i].alunoAutor, &tcs[i].professorOrientador);
        char *inicio_titulo = strchr(buffer, '"');
        char *fim_titulo = strrchr(buffer, '"');
        if (inicio_titulo != NULL && fim_titulo != NULL && inicio_titulo != fim_titulo) {
            int len = fim_titulo - inicio_titulo - 1;
            strncpy(tcs[i].titulo, inicio_titulo + 1, len);
            tcs[i].titulo[len] = '\0';
            char *parte_votos = fim_titulo + 1;
            tcs[i].votos = atoi(trim(parte_votos));
        } else {
             strcpy(tcs[i].titulo, "TITULO INVALIDO");
             tcs[i].votos = 0;
        }
    }
    fclose(file);
}

// Fun��o 'lerComissao' renomeada e atualizada
void lerEleitores() {
    FILE *file = fopen("votos.txt", "r"); // Arquivo renomeado
    if (!file) {
        printf("Arquivo votos.txt n�o encontrado. Come�ando com zero eleitores.\n");
        qtdeEleitores = 0;
        return;
    }
    if (fscanf(file, "%d", &qtdeEleitores) != 1) {
        qtdeEleitores = 0;
        fclose(file);
        return;
    }
    fgetc(file);
    int i;
    for (i = 0; i < qtdeEleitores; i++) {
        fscanf(file, "%s", eleitores[i].cpf); // Usa o array 'eleitores'
        fgets(eleitores[i].nome, sizeof(eleitores[i].nome), file);
        eleitores[i].nome[strcspn(eleitores[i].nome, "\n\r")] = '\0';
        strcpy(eleitores[i].nome, trim(eleitores[i].nome));
        eleitores[i].votou = 0;
        eleitores[i].votoTC = -1;
    }
    fclose(file);
}

// Fun��o 'salvarComissao' renomeada e atualizada
void salvarEleitores() {
    FILE *file = fopen("votos.txt", "w"); // Arquivo renomeado
    if (!file) {
        printf("Erro ao salvar o arquivo votos.txt\n");
        return;
    }
    fprintf(file, "%d\n", qtdeEleitores);
    int i;
    for (i = 0; i < qtdeEleitores; i++) {
        fprintf(file, "%s %s\n", eleitores[i].cpf, eleitores[i].nome); // Usa o array 'eleitores'
    }
    fclose(file);
    printf("Dados dos eleitores salvos com sucesso em votos.txt!\n");
}

void salvarTCs() {
    FILE *file = fopen("tc.txt", "w");
    if (!file) {
        printf("Erro ao salvar o arquivo tc.txt\n");
        return;
    }
    fprintf(file, "%d\n", qtdeTCs);
    int i;
    for (i = 0; i < qtdeTCs; i++) {
        fprintf(file, "%d %d %d \"%s\" %d\n", tcs[i].codigoTC, tcs[i].alunoAutor, tcs[i].professorOrientador, tcs[i].titulo, tcs[i].votos);
    }
    fclose(file);
    printf("Dados dos TCs salvos com sucesso!\n");
}

// --- FUN��ES DE EXIBI��O ---

void exibirTCs() {
    printf("\n--- Lista de Trabalhos de Conclus�o ---\n");
    int i;
    for (i = 0; i < qtdeTCs; i++) {
        printf("C�digo: %d | T�tulo: %s | Votos: %d\n", tcs[i].codigoTC, tcs[i].titulo, tcs[i].votos);
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

// Fun��o 'exibirComissao' renomeada e atualizada
void exibirEleitores() {
    printf("\n--- Lista de Eleitores Registrados ---\n");
    int i;
    for (i = 0; i < qtdeEleitores; i++) {
        printf("CPF: %s | Nome: %s | Votou nesta sess�o: %s\n", eleitores[i].cpf, eleitores[i].nome, eleitores[i].votou ? "Sim" : "N�o");
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

// --- L�GICA PRINCIPAL ---

void realizarVotacao() {
    char cpf[12];
    int voto;
    int eleitorIndex = -1;

    printf("Digite o CPF do eleitor (apenas n�meros): ");
    scanf("%s", cpf);
    getchar();

    if (strlen(cpf) != 11) {
        printf("CPF inv�lido. Deve conter 11 d�gitos.\n");
        return;
    }

    int i;
    for (i = 0; i < qtdeEleitores; i++) {
        if (strcmp(eleitores[i].cpf, cpf) == 0) { // Usa o array 'eleitores'
            eleitorIndex = i;
            break;
        }
    }

    if (eleitorIndex != -1 && eleitores[eleitorIndex].votou == 1) { // Usa o array 'eleitores'
        printf("Este CPF j� votou nesta sess�o.\n");
        return;
    }

    if (eleitorIndex == -1) {
        if (qtdeEleitores >= 100) {
            printf("Sistema de eleitores cheio.\n");
            return;
        }
        printf("CPF n�o cadastrado. Registrando como novo eleitor...\n");
        eleitorIndex = qtdeEleitores;
        strcpy(eleitores[eleitorIndex].cpf, cpf); // Usa o array 'eleitores'
        printf("Digite o nome do novo eleitor: ");
        fgets(eleitores[eleitorIndex].nome, 50, stdin);
        eleitores[eleitorIndex].nome[strcspn(eleitores[eleitorIndex].nome, "\n\r")] = '\0';
        eleitores[eleitorIndex].votou = 0;
        eleitores[eleitorIndex].votoTC = -1;
        qtdeEleitores++;
    }

    printf("Eleitor '%s' apto para votar.\n", eleitores[eleitorIndex].nome); // Usa o array 'eleitores'
    exibirTCs();
    printf("Digite o c�digo do TC para votar: ");
    scanf("%d", &voto);
    getchar();

    int tcValido = 0;
    int j;
    for (j = 0; j < qtdeTCs; j++) {
        if (tcs[j].codigoTC == voto) {
            tcValido = 1;
            break;
        }
    }

    if (tcValido) {
        eleitores[eleitorIndex].votou = 1; // Usa o array 'eleitores'
        eleitores[eleitorIndex].votoTC = voto;
        tcs[j].votos++;
        printf("Voto registrado com sucesso!\n");
    } else {
        printf("C�digo de TC inv�lido.\n");
    }
}

void exibirRanking() {
    printf("\n--- Ranking dos TCs (Ordenado por votos) ---\n");
    TrabalhoConclusao tempTCs[100];
    memcpy(tempTCs, tcs, sizeof(TrabalhoConclusao) * qtdeTCs);

    int i, j;
    for (i = 0; i < qtdeTCs - 1; i++) {
        for (j = i + 1; j < qtdeTCs; j++) {
            if (tempTCs[i].votos < tempTCs[j].votos) {
                TrabalhoConclusao temp = tempTCs[i];
                tempTCs[i] = tempTCs[j];
                tempTCs[j] = temp;
            }
        }
    }

    for (i = 0; i < qtdeTCs; i++) {
        printf("%d� Lugar: %s (C�digo: %d) - Votos: %d\n", i + 1, tempTCs[i].titulo, tempTCs[i].codigoTC, tempTCs[i].votos);
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Fun��es de leitura de aluno e professor removidas
    lerTCs();
    lerEleitores(); // Fun��o renomeada

    int opcao;
    do {
        printf("\n--- Sistema de Vota��o de TCCs ---\n");
        printf("1 - Votar\n");
        printf("2 - Ver Resultado Parcial (Ranking)\n");
        printf("3 - Listar TCCs Concorrentes\n");
        printf("4 - Listar Eleitores Registrados\n");
        printf("5 - Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                realizarVotacao();
                break;
            case 2:
                exibirRanking();
                break;
            case 3:
                exibirTCs();
                break;
            case 4:
                exibirEleitores(); // Fun��o renomeada
                break;
            case 5:
                printf("Salvando dados antes de sair...\n");
                salvarTCs();
                salvarEleitores(); // Fun��o renomeada
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida.\n");
        }
    } while (opcao != 5);

    printf("Programa encerrado.\n");
    return 0;
}
