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
            printf("Falha ao salvar dados de clientes.\n");
        }
        case ERR_CLIENTE_NAO_ENCONTRADO: {
            printf("Falha ao encontrar id de cliente.");
        }
        default: {
            printf("Erro desconhecido.");
        }
    }
}

void limpar_buffer() {
    while (getchar() != '\n');
}