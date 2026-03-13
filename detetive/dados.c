#include <stdio.h>
#include <stdlib.h>
#include "info.h"

void inicializar_db (LoreDB *db) {
    db->obras = NULL;
    db->quant_obras = 0;
    db->capacidade_obras = 0;
}

int adicionar_obra(LoreDB *db) {
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

}

