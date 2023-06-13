#include "lista_alunos.h"
#include <stdio.h>

void inicializarLista(ListaAlunos* lista) {
    lista->quantidade = 0;
}

void liberarLista(ListaAlunos* lista) {
    lista->quantidade = 0;
}

int quantidadeElementos(ListaAlunos* lista) {
    return lista->quantidade;
}

int listaCheia(ListaAlunos* lista) {
    return lista->quantidade == MAX_ALUNOS;
}

int listaVazia(ListaAlunos* lista) {
    return lista->quantidade == 0;
}

void exibirLista(ListaAlunos* lista) {
    for (int i = 0; i < lista->quantidade; i++) {
        printf("Matricula: %d\n", lista->elementos[i].matricula);
        printf("Nome: %s\n", lista->elementos[i].nome);
        printf("Idade: %d\n", lista->elementos[i].idade);
        printf("\n");
    }
}

void inserirElemento(ListaAlunos* lista, Aluno aluno) {
    if (lista->quantidade == 0) {
        lista->elementos[0] = aluno;
        lista->quantidade++;
        return;
    }

    int posicao = 0;
    while (posicao < lista->quantidade && aluno.matricula > lista->elementos[posicao].matricula) {
        posicao++;
    }

    for (int i = lista->quantidade - 1; i >= posicao; i--) {
        lista->elementos[i + 1] = lista->elementos[i];
    }

    lista->elementos[posicao] = aluno;
    lista->quantidade++;
}

void excluirElemento(ListaAlunos* lista, int matricula) {
    if (lista->quantidade == 0) {
        return;
    }

    int posicao = 0;
    while (posicao < lista->quantidade && matricula != lista->elementos[posicao].matricula) {
        posicao++;
    }

    if (posicao == lista->quantidade) {
        return;
    }

    for (int i = posicao; i < lista->quantidade - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }

    lista->quantidade--;
}

void alterarMatricula(ListaAlunos* lista, int matricula, int novaMatricula) {
    if (lista->quantidade == 0) {
        return;
    }

    int posicao = 0;
    while (posicao < lista->quantidade && matricula != lista->elementos[posicao].matricula) {
        posicao++;
    }

    if (posicao == lista->quantidade) {
        return;
    }

    lista->elementos[posicao].matricula = novaMatricula;
}
