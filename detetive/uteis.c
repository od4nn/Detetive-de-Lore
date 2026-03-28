#include <stdio.h>
#include "info.h"

/*Funcoes uteis para usar durante o programa*/

void tratar_retorno (int codigo, char *msg_sucesso, char *msg_erro) {
    if (codigo == OK) {
        printf("\nSucesso: %s\n", msg_sucesso);
        return;
    }

    printf("\nErro: erro ao %s. ", msg_erro);

    switch (codigo) {
        case ERR_FALTA_MEMORIA: {
            printf("Memoria RAM insuficiente.\n");
            break;
        }
        case ERR_LEITURA: {
            printf("Falha ao salvar dados.\n");
            break;
        }
        case ERR_OBRA_NAO_ENCONTRAD: {
            printf("Falha ao encontrar obra.\n");
            break;
        }
        case ERR_OBRA_PESQUISA_NAO_ENCONTRADA: {
            printf("Falha ao encontrar obra.");
            break;
        }
        case ERR_OBRA_PESQUISA_NAO_EXISTE: {
            printf("Crie uma obra primeiro!");
            break;
        }
        default: {
            printf("Erro desconhecido.\n");
        }
    }
}

void limpar_buffer() {
    while (getchar() != '\n');
}

void menu() {
        printf("\n--- Menu ---\n");
        printf("1. Adicionar Obra\n");
        printf("2. Listar Obras\n");
        printf("3. Adicionar Teoria\n");
        printf("0. Encerrar programa\n");
        printf("\nEscolha uma opcao: ");
}