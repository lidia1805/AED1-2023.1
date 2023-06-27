#ifndef HANGAR_H
#define HANGAR_H

#define MAX_NOME_AVIAO 100

typedef struct Aviao {
    char nome[MAX_NOME_AVIAO];
    int identificador;
} Aviao;

typedef struct Elemento {
    Aviao aviao;
    struct Elemento* proximo;
} Elemento;

typedef struct Pilha {
    Elemento* topo;
} Pilha;

void inicializaPilha(Pilha* pilha);
int empilharAviao(Pilha* pilha, Aviao novo_aviao);
int desempilharAviao(Pilha* pilha);
int numeroDeAvioes(Pilha pilha);
void listarAvioes(Pilha pilha);
void listarPrimeiroAviao(Pilha pilha);
int desempilharAviaoPorPosicao(Pilha* pilha, int posicao);

#endif  
