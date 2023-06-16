#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} ListaSequencial;

void criar_lista(ListaSequencial* lista) {
    lista->tamanho = 0;
}

int esta_cheia(ListaSequencial lista) {
    return lista.tamanho == MAX_SIZE;
}

void inserir_ordenado(ListaSequencial* lista, int valor) {
    if (esta_cheia(*lista)) {
        printf("A lista está cheia. Não é possível inserir mais elementos.\n");
        return;
    }

    int posicao_insercao = 0;
    while (posicao_insercao < lista->tamanho && valor > lista->elementos[posicao_insercao]) {
        posicao_insercao++;
    }

    for (int i = lista->tamanho - 1; i >= posicao_insercao; i--) {
        lista->elementos[i + 1] = lista->elementos[i];
    }

    lista->elementos[posicao_insercao] = valor;
    lista->tamanho++;
}

int contar_ocorrencias(ListaSequencial lista, int valor) {
    int ocorrencias = 0;

    for (int i = 0; i < lista.tamanho; i++) {
        if (lista.elementos[i] == valor) {
            ocorrencias++;
        }
    }

    return ocorrencias;
}

void imprimir(ListaSequencial lista) {
    printf("Elementos da lista: ");
    for (int i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.elementos[i]);
    }
    printf("\n");
}

int main() {
    ListaSequencial lista;
    criar_lista(&lista);

    // Inserir elementos de forma ordenada permitindo duplicados
    inserir_ordenado(&lista, 3);
    inserir_ordenado(&lista, 1);
    inserir_ordenado(&lista, 2);
    inserir_ordenado(&lista, 2);
    inserir_ordenado(&lista, 3);

    // Imprimir os elementos da lista
    imprimir(lista);

    // Contar o número de ocorrências de um valor na lista
    int valor = 2;
    int ocorrencias = contar_ocorrencias(lista, valor);
    printf("O valor %d ocorre %d vez(es) na lista.\n", valor, ocorrencias);

    return 0;
}
