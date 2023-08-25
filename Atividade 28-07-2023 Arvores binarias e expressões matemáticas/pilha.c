#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criarPilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha) {
        pilha->capacidade = capacidade;
        pilha->array = (char*)malloc(capacidade * sizeof(char));
        pilha->topo = -1;
    }
    return pilha;
}

void destruirPilha(Pilha* pilha) {
    if (pilha) {
        free(pilha->array);
        free(pilha);
    }
}

void empilhar(Pilha* pilha, char dado) {
    if (pilha && pilha->topo < pilha->capacidade - 1) {
        pilha->array[++pilha->topo] = dado;
    }
}

char desempilhar(Pilha* pilha) {
    if (pilha && pilha->topo >= 0) {
        return pilha->array[pilha->topo--];
    }
    return '\0'; 
}

char topo(Pilha* pilha) {
    if (pilha && pilha->topo >= 0) {
        return pilha->array[pilha->topo];
    }
    return '\0'; /
}

int estaVazia(Pilha* pilha) {
    if (pilha) {
        return pilha->topo == -1;
    }
    return 1; 
}
