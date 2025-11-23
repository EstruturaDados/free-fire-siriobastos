#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// ----------------------------------------------------------
// STRUCT Item – representa cada item do inventário
// ----------------------------------------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// ----------------------------------------------------------
// Função para inserir um item no inventário
// ----------------------------------------------------------
void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\n=== Cadastro de Item ===\n");

    printf("Nome do item: ");
    scanf("%s", mochila[*total].nome);

    printf("Tipo do item (arma, municao, cura...): ");
    scanf("%s", mochila[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    (*total)++;
    printf("\nItem adicionado com sucesso!\n");
}

// ----------------------------------------------------------
// Função para remover um item da mochila (busca pelo nome)
// ----------------------------------------------------------
void removerItem(Item mochila[], int *total) {
    if (*total == 0) {
        printf("\nA mochila está vazia! Não há itens para remover.\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item que deseja remover: ");
    scanf("%s", nomeRemover);

    int encontrado = -1;

    // Busca sequencial pelo item
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\nItem não encontrado!\n");
        return;
    }

    // Remoção deslocando os itens à esquerda
    for (int i = encontrado; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*total)--;
    printf("\nItem removido com sucesso!\n");
}

// ----------------------------------------------------------
// Função para listar todos os itens da mochila
// ----------------------------------------------------------
void listarItens(Item mochila[], int total) {
    printf("\n=== Itens na Mochila ===\n");

    if (total == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}

// ----------------------------------------------------------
// Função de busca sequencial por nome
// ----------------------------------------------------------
void buscarItem(Item mochila[], int total) {
    char nomeBuscado[30];

    printf("\nDigite o nome do item para buscar: ");
    scanf("%s", nomeBuscado);

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBuscado) == 0) {
            printf("\n=== Item Encontrado ===\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("\nItem não encontrado.\n");
}

// ----------------------------------------------------------
// Função principal
// ----------------------------------------------------------
int main() {
    Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n========================================\n");
        printf("        SISTEMA DE INVENTÁRIO\n");
        printf("========================================\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &totalItens);
                listarItens(mochila, totalItens);
                break;
            case 2:
                removerItem(mochila, &totalItens);
                listarItens(mochila, totalItens);
                break;
            case 3:
                listarItens(mochila, totalItens);
                break;
            case 4:
                buscarItem(mochila, totalItens);
                break;
            case 0:
                printf("\nEncerrando sistema...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// ===============================================================
// ======================== STRUCTS ===============================
// ===============================================================

// Item usado em ambas as estruturas
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Nó da lista encadeada
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// ===============================================================
// CONTADORES DE COMPARAÇÕES PARA ANÁLISE EMPÍRICA
// ===============================================================
int comparacoesSequencial = 0;
int comparacoesBinaria = 0;

// ===============================================================
// =================== FUNÇÕES DO VETOR ===========================
// ===============================================================

// Inserção no vetor
void inserirItemVetor(Item vetor[], int *total) {
    if (*total >= MAX) {
        printf("\nMochila cheia!\n");
        return;
    }

    printf("\n=== Inserir Item (Vetor) ===\n");
    printf("Nome: ");
    scanf("%s", vetor[*total].nome);
    printf("Tipo: ");
    scanf("%s", vetor[*total].tipo);
    printf("Quantidade: ");
    scanf("%d", &vetor[*total].quantidade);

    (*total)++;
    printf("Item inserido com sucesso!\n");
}

// Remoção no vetor
void removerItemVetor(Item vetor[], int *total) {
    if (*total == 0) {
        printf("\nMochila vazia!\n");
        return;
    }

    char nomeBusca[30];
    printf("\nNome do item para remover: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < *total; i++) {
        if (strcmp(vetor[i].nome, nomeBusca) == 0) {
            for (int j = i; j < *total - 1; j++) {
                vetor[j] = vetor[j + 1];
            }
            (*total)--;
            printf("Item removido!\n");
            return;
        }
    }

    printf("Item não encontrado.\n");
}

// Listagem no vetor
void listarVetor(Item vetor[], int total) {
    printf("\n=== Itens no Vetor ===\n");
    if (total == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", vetor[i].nome);
        printf("Tipo: %s\n", vetor[i].tipo);
        printf("Quantidade: %d\n", vetor[i].quantidade);
    }
}

// Busca sequencial no vetor
int buscarSequencialVetor(Item vetor[], int total, char nome[]) {
    comparacoesSequencial = 0;

    for (int i = 0; i < total; i++) {
        comparacoesSequencial++;
        if (strcmp(vetor[i].nome, nome) == 0)
            return i;
    }
    return -1;
}

// Ordenação (Bubble Sort)
void ordenarVetor(Item vetor[], int total) {
    Item temp;

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (strcmp(vetor[j].nome, vetor[j + 1].nome) > 0) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    printf("\nVetor ordenado com sucesso!\n");
}

// Busca binária
int buscarBinariaVetor(Item vetor[], int total, char nome[]) {
    int ini = 0, fim = total - 1, meio;
    comparacoesBinaria = 0;

    while (ini <= fim) {
        meio = (ini + fim) / 2;
        comparacoesBinaria++;

        int cmp = strcmp(nome, vetor[meio].nome);

        if (cmp == 0)
            return meio;
        else if (cmp > 0)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

// ===============================================================
// ================= FUNÇÕES DA LISTA ENCADEADA ==================
// ===============================================================

// Inserir na lista
void inserirItemLista(No **lista) {
    No *novo = (No*)malloc(sizeof(No));

    printf("\n=== Inserir Item (Lista) ===\n");
    printf("Nome: ");
    scanf("%s", novo->dados.nome);
    printf("Tipo: ");
    scanf("%s", novo->dados.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    novo->proximo = *lista;
    *lista = novo;

    printf("Item inserido!\n");
}

// Remover da lista
void removerItemLista(No **lista) {
    if (*lista == NULL) {
        printf("\nLista vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nNome do item para remover: ");
    scanf("%s", nomeBusca);

    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nomeBusca) == 0) {
            if (anterior == NULL) 
                *lista = atual->proximo;
            else 
                anterior->proximo = atual->proximo;

            free(atual);
            printf("Item removido!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Item não encontrado.\n");
}

// Listagem na lista
void listarLista(No* lista) {
    printf("\n=== Itens na Lista Encadeada ===\n");
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    while (lista != NULL) {
        printf("\nNome: %s\n", lista->dados.nome);
        printf("Tipo: %s\n", lista->dados.tipo);
        printf("Quantidade: %d\n", lista->dados.quantidade);
        lista = lista->proximo;
    }
}

// Busca sequencial na lista
int buscarSequencialLista(No *lista, char nome[]) {
    comparacoesSequencial = 0;

    while (lista != NULL) {
        comparacoesSequencial++;
        if (strcmp(lista->dados.nome, nome) == 0)
            return 1;
        lista = lista->proximo;
    }
    return 0;
}

// ===============================================================
// ===================== FUNÇÃO PRINCIPAL ========================
// ===============================================================
int main() {
    Item vetor[MAX];
    int total = 0;

    No *lista = NULL;

    int opc, estrutura;
    char nomeBusca[30];

    do {
        printf("\n==============================\n");
        printf("     SISTEMA DE MOCHILA\n");
        printf("==============================\n");
        printf("1 - Usar VETOR\n");
        printf("2 - Usar LISTA ENCADEADA\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &estrutura);

        if (estrutura == 0) break;

        printf("\n1 - Inserir\n2 - Remover\n3 - Listar\n4 - Buscar Sequencial\n5 - Ordenar (Vetor)\n6 - Buscar Binária (Vetor)\n0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opc);

        switch (estrutura) {

            // ---------------- VETOR -------------------
            case 1:
                switch (opc) {
                case 1: inserirItemVetor(vetor, &total); break;
                case 2: removerItemVetor(vetor, &total); break;
                case 3: listarVetor(vetor, total); break;

                case 4:
                    printf("\nBuscar nome: ");
                    scanf("%s", nomeBusca);
                    buscarSequencialVetor(vetor, total, nomeBusca);
                    printf("Comparações (sequencial): %d\n", comparacoesSequencial);
                    break;

                case 5:
                    ordenarVetor(vetor, total);
                    break;

                case 6:
                    printf("\nBuscar (binária) nome: ");
                    scanf("%s", nomeBusca);
                    buscarBinariaVetor(vetor, total, nomeBusca);
                    printf("Comparações (binária): %d\n", comparacoesBinaria);
                    break;
                }
                break;

            // ---------------- LISTA --------------------
            case 2:
                switch (opc) {
                case 1: inserirItemLista(&lista); break;
                case 2: removerItemLista(&lista); break;
                case 3: listarLista(lista); break;

                case 4:
                    printf("\nBuscar nome: ");
                    scanf("%s", nomeBusca);
                    buscarSequencialLista(lista, nomeBusca);
                    printf("Comparações (sequencial): %d\n", comparacoesSequencial);
                    break;

                default: break;
                }
                break;
        }

    } while (estrutura != 0);

    printf("\nEncerrando sistema...\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20

// ============================================================
// ======================= STRUCT =============================
// ============================================================
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// ============================================================
// ================= CONTADORES GLOBAIS ========================
// ============================================================
long long comparacoes;

// ============================================================
// ========== FUNÇÃO GENÉRICA DE MEDIÇÃO DE TEMPO =============
// ============================================================
double medirTempo(void (*algoritmo)(Componente[], int), Componente vet[], int n) {
    clock_t inicio, fim;
    inicio = clock();
    algoritmo(vet, n);
    fim = clock();

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// ============================================================
// ==================== BUBBLE SORT (NOME) ====================
// ============================================================
void bubbleSortNome(Componente vet[], int n) {
    comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comparacoes++;
            if (strcmp(vet[j].nome, vet[j + 1].nome) > 0) {
                Componente temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

// ============================================================
// ================ INSERTION SORT (TIPO) ======================
// ============================================================
void insertionSortTipo(Componente vet[], int n) {
    comparacoes = 0;
    for (int i = 1; i < n; i++) {
        Componente atual = vet[i];
        int j = i - 1;

        while (j >= 0) {
            comparacoes++;
            if (strcmp(vet[j].tipo, atual.tipo) > 0) {
                vet[j + 1] = vet[j];
                j--;
            } else break;
        }
        vet[j + 1] = atual;
    }
}

// ============================================================
// ============== SELECTION SORT (PRIORIDADE) =================
// ============================================================
void selectionSortPrioridade(Componente vet[], int n) {
    comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (vet[j].prioridade < vet[menor].prioridade) {
                menor = j;
            }
        }

        // troca
        if (menor != i) {
            Componente temp = vet[i];
            vet[i] = vet[menor];
            vet[menor] = temp;
        }
    }
}

// ============================================================
// ======================= BUSCA BINÁRIA ======================
// ============================================================
int buscaBinariaPorNome(Componente vet[], int n, char nome[]) {
    int ini = 0, fim = n - 1, meio;

    while (ini <= fim) {
        meio = (ini + fim) / 2;

        int cmp = strcmp(nome, vet[meio].nome);

        if (cmp == 0)
            return meio;
        else if (cmp > 0)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

// ============================================================
// ======================= EXIBIÇÃO ===========================
// ============================================================
void mostrarComponentes(Componente vet[], int n) {
    printf("\n===== COMPONENTES ATUAIS =====\n");
    for (int i = 0; i < n; i++) {
        printf("\nComponente %d:\n", i + 1);
        printf("Nome: %s\n", vet[i].nome);
        printf("Tipo: %s\n", vet[i].tipo);
        printf("Prioridade: %d\n", vet[i].prioridade);
    }
}

// ============================================================
// ========================== MAIN ============================
// ============================================================
int main() {
    Componente componentes[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n==============================\n");
        printf("   SISTEMA DA TORRE DE FUGA   \n");
        printf("==============================");
        printf("\n1 - Cadastrar componente");
        printf("\n2 - Ordenar por NOME (Bubble Sort)");
        printf("\n3 - Ordenar por TIPO (Insertion Sort)");
        printf("\n4 - Ordenar por PRIORIDADE (Selection Sort)");
        printf("\n5 - Busca Binária por Nome");
        printf("\n6 - Mostrar componentes");
        printf("\n0 - Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);
        getchar(); // remover o \n

        if (opcao == 1) {
            if (total >= MAX) {
                printf("Limite máximo de componentes atingido!\n");
                continue;
            }
            printf("\nNome do componente: ");
            fgets(componentes[total].nome, 30, stdin);
            componentes[total].nome[strcspn(componentes[total].nome, "\n")] = '\0';

            printf("Tipo: ");
            fgets(componentes[total].tipo, 20, stdin);
            componentes[total].tipo[strcspn(componentes[total].tipo, "\n")] = '\0';

            printf("Prioridade (1 a 10): ");
            scanf("%d", &componentes[total].prioridade);
            getchar();

            total++;
            printf("Componente cadastrado!\n");
        }
        else if (opcao == 2) {
            double tempo = medirTempo(bubbleSortNome, componentes, total);
            printf("\nOrdenado por NOME!\nComparações: %lld\nTempo: %.6f s\n", comparacoes, tempo);
        }
        else if (opcao == 3) {
            double tempo = medirTempo(insertionSortTipo, componentes, total);
            printf("\nOrdenado por TIPO!\nComparações: %lld\nTempo: %.6f s\n", comparacoes, tempo);
        }
        else if (opcao == 4) {
            double tempo = medirTempo(selectionSortPrioridade, componentes, total);
            printf("\nOrdenado por PRIORIDADE!\nComparações: %lld\nTempo: %.6f s\n", comparacoes, tempo);
        }
        else if (opcao == 5) {
            if (total == 0) {
                printf("\nNenhum componente disponível.\n");
                continue;
            }

            char chave[30];
            printf("\nDigite o nome do componente-chave: ");
            fgets(chave, 30, stdin);
            chave[strcspn(chave, "\n")] = '\0';

            int pos = buscaBinariaPorNome(componentes, total, chave);

            if (pos >= 0) {
                printf("\n*** COMPONENTE ENCONTRADO! ***\n");
                printf("Nome: %s | Tipo: %s | Prioridade: %d\n",
                       componentes[pos].nome, componentes[pos].tipo, componentes[pos].prioridade);
                printf("A montagem da torre pode prosseguir!\n");
            } else {
                printf("\nComponente não encontrado. A torre não pode ser ativada!\n");
            }
        }
        else if (opcao == 6) {
            mostrarComponentes(componentes, total);
        }

    } while (opcao != 0);

    printf("\nSaindo do sistema...\n");
    return 0;
}