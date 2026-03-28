#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"
#include <ctype.h>

void inicializar_db (LoreDB *db) {
    db->obras = NULL;
    db->quant_obras = 0;
    db->capacidade_obras = 0;
}

int adicionar_obra(LoreDB *db, Obra obra_usuario){
    Obra *temp = NULL;

    if (db->quant_obras == db->capacidade_obras) {

        int nova_capacidade = (db->capacidade_obras == 0) ? 2 : (db->capacidade_obras * 2);
            temp = realloc(db->obras, sizeof(Obra) * nova_capacidade);

            if (temp == NULL) {
                return ERR_FALTA_MEMORIA;
            }

            db->obras = temp;
            db->capacidade_obras = nova_capacidade;
    }

    int i = db->quant_obras;

    db->obras[i] = obra_usuario; //copiando dados do main para a struct

    db->obras[i].teorias = NULL; //zerando teorias
    //zerando capacidade e quant
    db->obras[i].quant_teorias = 0;
    db->obras[i].capacidade_teorias = 0;

    db->quant_obras++; //incrementa uma obra

    return OK;
}

int listar_obras(LoreDB *db) {

    if (db->quant_obras == 0) {
        return ERR_OBRA_NAO_ENCONTRAD;
    }

    for (int i = 0; i < db->quant_obras; i++) {
        /* no futuro colocar apenas o nome de todas as obras, e entao assim que o
         * usuario desejar qual ver, mostrar as outras informações como tipo e genero
         * e ai todas as teorias dela, evita poluição. */

        printf("\n--OBRA N.%d--", i+1);
        printf("\nNome: %s\n", db->obras[i].obra_nome);
    }
    return OK;
}

int buscar_obras(LoreDB *db, char *nome_obra) {

    if (db->quant_obras == 0) {
        return ERR_OBRA_PESQUISA_NAO_EXISTE;
    }

    for (int i = 0; i < db->quant_obras; i++) {
        if(strcmp(nome_obra, db->obras[i].obra_nome) == 0) {
            return i;
        }
    }
    // se nao achou a obra ate aqui
    return ERR_OBRA_PESQUISA_NAO_ENCONTRADA;
}

int adicionar_teoria(LoreDB *db, int indice, Teoria nova_teoria) {
    Teoria *temp = NULL;

    if (db->obras[indice].quant_teorias == db->obras[indice].capacidade_teorias) {

        int nova_capacidade = (db->obras[indice].capacidade_teorias == 0) ? 2 :
        (db->obras[indice].capacidade_teorias * 2);     /* se for zero (ainda nao existe
        cria dois espaços se nao dobra o que ja existe) */

        temp = realloc(db->obras[indice].teorias, sizeof(Teoria) * nova_capacidade);

        if (temp == NULL) {
            return ERR_FALTA_MEMORIA;
        }

        db->obras[indice].teorias = temp;
        db->obras[indice].capacidade_teorias = nova_capacidade;
    }

    int i = db->obras[indice].quant_teorias;

    db->obras[indice].teorias[i] = nova_teoria; //indice diz qual obra deve ser, i diz qual teoria é

    db->obras[indice].quant_teorias++;

    return OK;
}

void detalhar_obra(LoreDB *db, int indice) {
    char resposta;

    printf("\nInformacoes da obra:\n");
    printf("\nTipo: %s", db->obras[indice].tipo);
    printf("\nStatus: %s", db->obras[indice].status);
    printf("\nGenero: %s", db->obras[indice].genero);
    printf("\nTeorias feitas: %d\n", db->obras[indice].quant_teorias);

    printf("\nDigite 's' para sim | Digite 'n' para nao: ");
    do {
        printf("\nDeseja ver as teorias dessa obra? ");
        scanf("%c", &resposta);
        limpar_buffer();

        resposta = tolower(resposta);
    }while (resposta != 's' && resposta != 'n');

    if (resposta == 's') {
        for (int i = 0; i < db->obras[indice].quant_teorias; i++) {
            printf("\n---Teorias da obra %s ---\n", db->obras[indice].obra_nome);

            printf("\nTeoria %d:", i+1);
            printf("\n%s", db->obras[indice].teorias[i].teoria);

            printf("\nEpisodio: %d | Temporada: %d", db->obras[indice]
            .teorias[i].episodio, db->obras[indice].teorias[i].temporada);

            printf("\nStatus da teoria: %s",
                db->obras[indice].teorias[i].status_teoria);

            printf("\nData: %s\n",db->obras[indice].teorias[i].data);
        }
    }

    else if (resposta == 'n') {
        printf("\nVoltando para o menu...\n");
    }
}