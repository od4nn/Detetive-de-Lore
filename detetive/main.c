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

            }
        }


    }while (opcao != 0);

    return 0;

}