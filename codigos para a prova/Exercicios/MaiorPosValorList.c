#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} ListaEstatica;

void criar_lista(ListaEstatica* lista) {
    lista->tamanho = 0;
}

int esta_vazia(ListaEstatica lista) {
    return lista.tamanho == 0;
}

int esta_cheia(ListaEstatica lista) {
    return lista.tamanho == MAX_SIZE;
}

void inserir(ListaEstatica* lista, int valor) {
    if (esta_cheia(*lista)) {
        printf("A lista está cheia. Não é possível inserir mais elementos.\n");
        return;
    }

    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

int buscar_maior_elemento(ListaEstatica lista, int* posicao, int* valor) {
    if (esta_vazia(lista)) {
        printf("A lista está vazia. Não há elementos para buscar.\n");
        return 0; // Retorna 0 para indicar falha na operação
    }

    int maior = lista.elementos[0];
    int pos = 0;

    for (int i = 1; i < lista.tamanho; i++) {
        if (lista.elementos[i] > maior) {
            maior = lista.elementos[i];
            pos = i;
        }
    }

    *posicao = pos;
    *valor = maior;

    return 1; // Retorna 1 para indicar sucesso na operação
}

int main() {
    ListaEstatica lista;
    criar_lista(&lista);

    // Inserir elementos na lista
    inserir(&lista, 15);
    inserir(&lista, 28);
    inserir(&lista, 9);
    inserir(&lista, 31);
    inserir(&lista, 2);

    int posicao, valor;
    int resultado = buscar_maior_elemento(lista, &posicao, &valor);

    if (resultado) {
        printf("Maior elemento encontrado:\n");
        printf("Posição: %d\n", posicao);
        printf("Valor: %d\n", valor);
    } else {
        printf("Não foi possível encontrar o maior elemento.\n");
    }

    return 0;
}

//uma função para buscar a posição e o valor do maior elemento em uma lista ligada estática de inteiros
