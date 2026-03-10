#include <stdio.h>
#include <stdlib.h>
#include "info.h"

int main()
{
    LoreDB database; //declara banco de dados
    inicializar_db(&database); // inicializa (limpa lixo de memoria dentro dele)
    return 0;
}