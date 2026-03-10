#include <stdio.h>
#include <stdlib.h>
#include "info.h"

void inicializar_db (LoreDB *db) {
    db->obras = NULL;
    db->quant_obras = 0;
    db->capacidade_obras = 0;
}

