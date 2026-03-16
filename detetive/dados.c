#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"

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

