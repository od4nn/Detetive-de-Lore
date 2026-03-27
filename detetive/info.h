#ifndef INFO_H
#define INFO_H

/*A estrutura relacional (1:N) será:
O Pai (Obra): Nome da Série/Anime, Gênero, Status.

Os Filhos (Teorias): Episódio alvo, Teoria/Reflexão,
Status (Comprovada, Refutada, Em aberto).

O Banco de Dados: A estrutura que guarda o vetor dinâmico
de Obras. Desafios técnicos exigidos: Alocação dinâmica (realloc),
persistência em arquivo TXT, deleção de itens (Shift em vetores) e
liberação total de memória (free). */

#define TAMANHO_NOME_OBRA 150
#define TAMANHO_TIPO 40
#define TAMANHO_STATUS 30
#define TAMANHO_GENERO 40
#define TAMANHO_TEORIA 4000
#define TAMANHO_DATA 13

typedef struct {
    int episodio;
    int temporada;
    char teoria [TAMANHO_TEORIA];
    char status_teoria[TAMANHO_STATUS]; //comprovada, refutada, andamento...
    char data [TAMANHO_DATA]; // DD/MM/AAAA
}Teoria; //filho

typedef struct {
    char obra_nome[TAMANHO_NOME_OBRA];
    char tipo[TAMANHO_TIPO]; //anime, serie, manga...
    char status[TAMANHO_STATUS]; //andamento, concluido, cancelada...
    char genero[TAMANHO_GENERO]; //drama, acao, aventura...
    Teoria *teorias;
    int quant_teorias;
    int capacidade_teorias;
}Obra; //pai

typedef struct {
    Obra *obras;
    int quant_obras;
    int capacidade_obras;
}LoreDB; //avô


/*===Enum para Erros===*/
typedef enum {
    OK = 0, //Sucesso geral

    //ERROS:
    ERR_OBRA_PESQUISA_NAO_EXISTE = -2, //nao existe nada ainda
    ERR_OBRA_PESQUISA_NAO_ENCONTRADA = -1, //para a funcao buscar obra. como mexemos com indice tem que ser negativo
    ERR_FALTA_MEMORIA = 1, // Falha malloc/realloc
    ERR_LEITURA = 2, //Falha ao salvar dados
    ERR_OBRA_NAO_ENCONTRAD = 3,
}CodigosErro;

//funcoes
void inicializar_db(LoreDB *db);
int adicionar_obra(LoreDB *db, Obra obra_usuario);
void tratar_retorno (int codigo, char *msg_sucesso, char *msg_erro);
void limpar_buffer();
void menu();
int listar_obras(LoreDB *db);
int buscar_obras(LoreDB *db, char *nome_obra);
int adicionar_teoria(LoreDB *db, int indice, Teoria nova_teoria);
#endif