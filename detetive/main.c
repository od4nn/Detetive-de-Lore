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
            case 1:{
                Obra obra_temp; //var temporaria para preenchimento de dados
                printf("---ADICIONAR OBRA---\n");

                printf("\nInforme o nome da obra: ");
                fgets(obra_temp.obra_nome, TAMANHO_NOME_OBRA, stdin);
                obra_temp.obra_nome[strcspn(obra_temp.obra_nome, "\n")] = '\0'; //tirando o /n e substituindo pelo terminador nulo

                printf("Informe o tipo de obra (anime/serie/manga...): ");
                fgets(obra_temp.tipo, TAMANHO_TIPO, stdin);
                obra_temp.tipo[strcspn(obra_temp.tipo, "\n")] = '\0';

                printf("Informe o status da obra (andamento, concluido,"
                       " abandonado): ");
                fgets(obra_temp.status, TAMANHO_STATUS, stdin);
                obra_temp.status[strcspn(obra_temp.status, "\n")] = '\0';

                printf("Informe o genero (acao, drama, comedia...): ");
                fgets(obra_temp.genero, TAMANHO_GENERO, stdin);
                obra_temp.genero[strcspn(obra_temp.genero, "\n")] = '\0';

                tratar_retorno(adicionar_obra(&database, obra_temp),
                    "Obra adicionada", "adicionar obra");
                break;
            }

            case 2: {
                if(listar_obras(&database) == ERR_OBRA_NAO_ENCONTRAD) {
                    printf("Erro: Crie uma obra primeiro!\n\n");
                    break;
                    //erro feedback
                }
                break;
            }

            case 3: {

            }
            case 0: {
                printf("Encerrando o programa...\n");
                break;
            }

            default: {
                printf("Erro: informe uma opcao valida! (1,2,3,0)\n");
            }
        }

    }while (opcao != 0);

    return 0;

}