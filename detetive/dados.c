#include <stdio.h>
#include <stdlib.h>
#include "info.h"

void inicializar_db (LoreDB *db) {
    db->obras = NULL;
    db->quant_obras = 0;
    db->capacidade_obras = 0;
}

void adicionar_obra(LoreDB *db) {
    Obra *temp = NULL;

    if (db->quant_obras == db->capacidade_obras) {
        if (db->capacidade_obras == 0) {
            temp = realloc(temp, sizeof(Obra));
            if (temp == NULL) {

            }
        }
    }
}

