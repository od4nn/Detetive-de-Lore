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
                }
                printf("\nCaso queira saber as informacoes detalhadas dessa"
                       " obra digite o 4 no menu e informe o nome da obra.\n");
                break;
            }

            case 3: {
                char NOME_OBRA_TEMP[TAMANHO_NOME_OBRA];
                Teoria NOVA_TEORIA;

                printf("\nEm qual obra voce deseja adicionar a teoria? ");
                fgets(NOME_OBRA_TEMP, TAMANHO_NOME_OBRA, stdin);
                NOME_OBRA_TEMP[strcspn(NOME_OBRA_TEMP, "\n")] = '\0';

                int indice = buscar_obras(&database, NOME_OBRA_TEMP); //busca obra

                //verifica se foi atribuido o indice corretamente
                if (indice == ERR_OBRA_PESQUISA_NAO_EXISTE) {
                    printf("\nErro: Crie uma obra antes!\n");
                    break;
                }
                if (indice == ERR_OBRA_PESQUISA_NAO_ENCONTRADA) {
                    printf("\nErro: Obra nao encontrada!\nCertifique se de ter "
                           "criado a obra ou se digitou o nome corretamente. Letras"
                           " maisculas, minusculas e espacos importam!\n");
                    break;
                }

                printf("\n--- Obra encontrada! Preencha as informacoes... ---\n");

                printf("Informe o episodio (somente numeros): ");
                scanf("%d", &NOVA_TEORIA.episodio);
                limpar_buffer();

                printf("Informe a temporada (somente numeros): ");
                scanf("%d", &NOVA_TEORIA.temporada);
                limpar_buffer();

                printf("Guarde a sua teoria (limite de caracteres = 4000): ");
                fgets(NOVA_TEORIA.teoria, TAMANHO_TEORIA, stdin);
                NOVA_TEORIA.teoria[strcspn(NOVA_TEORIA.teoria, "\n")] = '\0';

                printf("Status da teoria (comprovada, refutada, andamento): ");
                fgets(NOVA_TEORIA.status_teoria, TAMANHO_TEORIA, stdin);
                NOVA_TEORIA.status_teoria[strcspn(NOVA_TEORIA.status_teoria, "\n")] = '\0';

                printf("Data da teoria (formato = DD/MM/AAAA): ");
                fgets(NOVA_TEORIA.data, TAMANHO_DATA, stdin);
                NOVA_TEORIA.data[strcspn(NOVA_TEORIA.data, "\n")] = '\0';

                tratar_retorno(adicionar_teoria(&database, indice, NOVA_TEORIA),
                    "Teoria adicionada!", "adicionar teoria");

                break;
            }

            case 4: {
                char NOME_OBRA_TEMP[TAMANHO_NOME_OBRA];
                printf("\nInforme o nome da obra que deseja inspecionar: ");
                fgets(NOME_OBRA_TEMP, TAMANHO_NOME_OBRA, stdin);
                NOME_OBRA_TEMP[strcspn(NOME_OBRA_TEMP, "\n")] = '\0';

                int indice = buscar_obras(&database, NOME_OBRA_TEMP); //busca obra

                //verifica se foi atribuido o indice corretamente
                if (indice == ERR_OBRA_PESQUISA_NAO_EXISTE) {
                    printf("\nErro: Crie uma obra antes!\n");
                    break;
                }
                if (indice == ERR_OBRA_PESQUISA_NAO_ENCONTRADA) {
                    printf("\nErro: Obra nao encontrada!\nCertifique se de ter "
                           "criado a obra ou se digitou o nome corretamente. Letras"
                           "maisculas, minusculas e espacos importam!\n");
                    break;
                }

                printf("Obra %s encontrada!", database.obras[indice].obra_nome);

                detalhar_obra(&database, indice);

                break;
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