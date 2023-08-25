#ifndef PILHA_H
#define PILHA_H

typedef struct {
    char* array;
    int capacidade;
    int topo;
} Pilha;

Pilha* criarPilha(int capacidade);
void destruirPilha(Pilha* pilha);
void empilhar(Pilha* pilha, char dado);
char desempilhar(Pilha* pilha);
char topo(Pilha* pilha);
int estaVazia(Pilha* pilha);

#endif
