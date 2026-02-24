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
#define TAMANHO_NOME_EPISODIO 150
#define TAMANHO_TEORIA 4000
#define TAMANHO_DATA 13

typedef struct {
    char episodio[TAMANHO_NOME_EPISODIO];
    char teoria [TAMANHO_TEORIA];
    char status_teoria[TAMANHO_STATUS]; //comprovada, refutada, andamento...
    char data [TAMANHO_DATA]; // DD/MM/AAAA
}Teoria;

typedef struct {
    char obra_nome[TAMANHO_NOME_OBRA];
    char tipo[TAMANHO_TIPO]; //anime, serie, manga...
    char status[TAMANHO_STATUS]; //andamento, concluido, cancelada...
    char genero[TAMANHO_GENERO]; //drama, acao, aventura...
    Teoria *teorias;
    int quant_teoria;
}Obra;



#endif