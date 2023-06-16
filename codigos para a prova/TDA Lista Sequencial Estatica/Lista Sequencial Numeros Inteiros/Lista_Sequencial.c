#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} ListaLinear;

void criar_lista(ListaLinear *lista) {
    lista->tamanho = 0;
}

int esta_vazia(ListaLinear lista) {
    return lista.tamanho == 0;
}

int tamanho(ListaLinear lista) {
    return lista.tamanho;
}

void inserir(ListaLinear *lista, int elemento) {
    if (lista->tamanho < MAX_SIZE) {
        lista->elementos[lista->tamanho] = elemento;
        lista->tamanho++;
    }
}

void inserir_ordenado(ListaLinear *lista, int elemento) {
    int i, posicao;
    posicao = 0;

    while (posicao < lista->tamanho && lista->elementos[posicao] < elemento) {
        posicao++;
    }

    for (i = lista->tamanho; i > posicao; i--) {
        lista->elementos[i] = lista->elementos[i - 1];
    }

    lista->elementos[posicao] = elemento;
    lista->tamanho++;
}

int buscar_sequencial(ListaLinear lista, int elemento) {
    int i;

    for (i = 0; i < lista.tamanho; i++) {
        if (lista.elementos[i] == elemento) {
            return i;
        }
    }

    return -1;
}

int busca_binaria(ListaLinear lista, int elemento) {
    int inicio, fim, meio;
    inicio = 0;
    fim = lista.tamanho - 1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (lista.elementos[meio] == elemento) {
            return meio;
        } else if (lista.elementos[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int excluir_pela_posicao(ListaLinear *lista, int posicao) {
    int i;

    if (posicao < 0 || posicao >= lista->tamanho) {
        return 0;
    }

    for (i = posicao; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }

    lista->tamanho--;
    return 1;
}

int excluir_pelo_valor(ListaLinear *lista, int elemento) {
    int posicao = buscar_sequencial(*lista, elemento);

    if (posicao != -1) {
        return excluir_pela_posicao(lista, posicao);
    }

    return 0;
}

void imprimir(ListaLinear lista) {
    int i;

    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.elementos[i]);
    }

    printf("\n");
}

int main() {
    ListaLinear lista;
    criar_lista(&lista);

    // Inserir elementos na lista
    inserir(&lista, 10);
    inserir(&lista, 5);
    inserir(&lista, 20);

    // Inserir um elemento na lista de forma ordenada
    inserir_ordenado(&lista, 15);

    // Imprimir os elementos da lista
    imprimir(lista);

    return 0;
}
