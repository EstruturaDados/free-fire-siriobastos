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