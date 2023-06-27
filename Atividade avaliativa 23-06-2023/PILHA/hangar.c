#include "hangar.h"
#include <stdio.h>
#include <stdlib.h>

void inicializaPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

int empilharAviao(Pilha* pilha, Aviao novo_aviao) {
    Elemento* novo_elemento = (Elemento*)malloc(sizeof(Elemento));
    if (novo_elemento == NULL) {
        return 0;
    }
    novo_elemento->aviao = novo_aviao;
    novo_elemento->proximo = pilha->topo;
    pilha->topo = novo_elemento;
    return 1;
}

int desempilharAviao(Pilha* pilha) {
    if (pilha->topo == NULL) {
        return 0;
    }
    Elemento* elemento_removido = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(elemento_removido);
    return 1;
}

int numeroDeAvioes(Pilha pilha) {
    int cont = 0;
    Elemento* atual = pilha.topo;
    while (atual != NULL) {
        cont++;
        atual = atual->proximo;
    }
    return cont;
}

void listarAvioes(Pilha pilha) {
    Elemento* atual = pilha.topo;
    if (atual == NULL) {
        printf("Nenhum avião no hangar.\n");
    } else {
        printf("Aviões no hangar:\n");
        while (atual != NULL) {
            printf("Nome: %s, Identificador: %d\n", atual->aviao.nome, atual->aviao.identificador);
            atual = atual->proximo;
        }
    }
}

void listarPrimeiroAviao(Pilha pilha) {
    if (pilha.topo != NULL) {
        printf("Primeiro avião no hangar:\n");
        printf("Nome: %s, Identificador: %d\n", pilha.topo->aviao.nome, pilha.topo->aviao.identificador);
    } else {
        printf("Nenhum avião no hangar.\n");
    }
}

int desempilharAviaoPorPosicao(Pilha* pilha, int posicao) {
    if (pilha->topo == NULL || posicao <= 0 || posicao > numeroDeAvioes(*pilha)) {
        return 0;
    }

    if (posicao == 1) {
        return desempilharAviao(pilha);
    }

    Elemento* elemento_anterior = pilha->topo;
    int i;
    for (i = 1; i < posicao - 1; i++) {
        elemento_anterior = elemento_anterior->proximo;
    }

    Elemento* elemento_removido = elemento_anterior->proximo;
    elemento_anterior->proximo = elemento_removido->proximo;
    free(elemento_removido);
    return 1;
}
