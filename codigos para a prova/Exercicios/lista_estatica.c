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

int encontrar_maior_elemento(ListaEstatica lista) {
    if (esta_vazia(lista)) {
        printf("A lista está vazia. Não há elementos para retornar.\n");
        return -1; // Valor sentinela indicando erro
    }

    int maior = lista.elementos[0];

    for (int i = 1; i < lista.tamanho; i++) {
        if (lista.elementos[i] > maior) {
            maior = lista.elementos[i];
        }
    }

    return maior;
}

int excluir_maior_elemento(ListaEstatica* lista) {
    if (esta_vazia(*lista)) {
        printf("A lista está vazia. Não há elementos para excluir.\n");
        return -1; // Valor sentinela indicando erro
    }

    int maior = encontrar_maior_elemento(*lista);

    int posicao_maior = 0;
    for (int i = 1; i < lista->tamanho; i++) {
        if (lista->elementos[i] == maior) {
            posicao_maior = i;
            break;
        }
    }

    for (int i = posicao_maior; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }

    lista->tamanho--;

    return maior;
}

void imprimir(ListaEstatica lista) {
    printf("Elementos da lista: ");
    for (int i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.elementos[i]);
    }
    printf("\n");
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

    // Excluir e retornar o maior elemento da lista
    int maior_elemento = excluir_maior_elemento(&lista);
    printf("Maior elemento: %d\n", maior_elemento);

    // Imprimir a lista após a exclusão
    imprimir(lista);

    return 0;
}
