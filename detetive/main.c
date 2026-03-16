#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"

int main()
{
    LoreDB database; //declara banco de dados
    inicializar_db(&database); // inicializa (limpa lixo de memoria dentro dele)

    printf("=== BEM VINDO AO DETETIVE DE LORE ===\n\n");
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);

        limpar_buffer();

        switch(opcao) {
            case 1: {
                Obra obra_temp; //var temporaria para preenchimento de dados

                printf("---ADICIONAR OBRA---\n");

                printf("\nInforme o nome da obra: ");
                fgets(obra_temp.obra_nome, TAMANHO_NOME_OBRA, stdin);

                printf("Informe o tipo de obra (anime/serie/manga...): ");
                fgets(obra_temp.tipo, TAMANHO_TIPO, stdin);

                printf("Informe o status da obra (andamento, concluido,"
                       " abandonado): ");
                fgets(obra_temp.status, TAMANHO_STATUS, stdin);

                printf("Informe o genero (acao, drama, comedia...): ");
                fgets(obra_temp.genero, TAMANHO_GENERO, stdin);

                tratar_retorno(adicionar_obra(&database, obra_temp),
                    "Obra adicionada", "adicionar obra");

                break;
            }
        }


    }while (opcao != 0);

    return 0;

}