#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int valor;
    int proximo;
} Nodo;

typedef struct {
    Nodo elementos[MAX_SIZE];
    int tamanho;
    int inicio;
    int livre;
} ListaLigada;

void criar_lista(ListaLigada *lista) {
    lista->tamanho = 0;
    lista->inicio = -1;
    lista->livre = 0;

    int i;
    for (i = 0; i < MAX_SIZE - 1; i++) {
        lista->elementos[i].proximo = i + 1;
    }

    lista->elementos[MAX_SIZE - 1].proximo = -1;
}

int esta_vazia(ListaLigada lista) {
    return lista.tamanho == 0;
}

int tamanho(ListaLigada lista) {
    return lista.tamanho;
}

int obter_nodo_livre(ListaLigada *lista) {
    int nodo_livre = lista->livre;
    lista->livre = lista->elementos[lista->livre].proximo;
    return nodo_livre;
}

void liberar_nodo(ListaLigada *lista, int nodo) {
    lista->elementos[nodo].proximo = lista->livre;
    lista->livre = nodo;
}

void inserir(ListaLigada *lista, int elemento) {
    if (lista->livre != -1) {
        int novo_nodo = obter_nodo_livre(lista);
        lista->elementos[novo_nodo].valor = elemento;
        lista->elementos[novo_nodo].proximo = -1;

        if (esta_vazia(*lista)) {
            lista->inicio = novo_nodo;
        } else {
            int nodo_atual = lista->inicio;
            while (lista->elementos[nodo_atual].proximo != -1) {
                nodo_atual = lista->elementos[nodo_atual].proximo;
            }
            lista->elementos[nodo_atual].proximo = novo_nodo;
        }

        lista->tamanho++;
    }
}

void inserir_ordenado(ListaLigada *lista, int elemento) {
    if (lista->livre != -1) {
        int novo_nodo = obter_nodo_livre(lista);
        lista->elementos[novo_nodo].valor = elemento;

        if (esta_vazia(*lista) || elemento < lista->elementos[lista->inicio].valor) {
            lista->elementos[novo_nodo].proximo = lista->inicio;
            lista->inicio = novo_nodo;
        } else {
            int nodo_atual = lista->inicio;
            int nodo_anterior = -1;

            while (nodo_atual != -1 && elemento > lista->elementos[nodo_atual].valor) {
                nodo_anterior = nodo_atual;
                nodo_atual = lista->elementos[nodo_atual].proximo;
            }

            lista->elementos[novo_nodo].proximo = nodo_atual;
            lista->elementos[nodo_anterior].proximo = novo_nodo;
        }

        lista->tamanho++;
    }
}

int buscar_sequencial(ListaLigada lista, int elemento) {
    int nodo_atual = lista.inicio;

    while (nodo_atual != -1) {
        if (lista.elementos[nodo_atual].valor == elemento) {
            return nodo_atual;
        }
        nodo_atual = lista.elementos[nodo_atual].proximo;
    }

    return -1;
}

int busca_binaria(ListaLigada lista, int elemento) {
    printf("A busca binária não é aplicável a uma lista ligada estática.\n");
    return -1;
}

int excluir_pela_posicao(ListaLigada *lista, int posicao) {
    if (posicao >= 0 && posicao < lista->tamanho) {
        int nodo_atual = lista->inicio;
        int nodo_anterior = -1;

        while (posicao > 0) {
            nodo_anterior = nodo_atual;
            nodo_atual = lista->elementos[nodo_atual].proximo;
            posicao--;
        }

        if (nodo_anterior == -1) {
            lista->inicio = lista->elementos[nodo_atual].proximo;
        } else {
            lista->elementos[nodo_anterior].proximo = lista->elementos[nodo_atual].proximo;
        }

        liberar_nodo(lista, nodo_atual);
        lista->tamanho--;
        return 1;
    }

    return 0;
}

int excluir_pelo_valor(ListaLigada *lista, int elemento) {
    int nodo_atual = lista->inicio;
    int nodo_anterior = -1;

    while (nodo_atual != -1) {
        if (lista->elementos[nodo_atual].valor == elemento) {
            if (nodo_anterior == -1) {
                lista->inicio = lista->elementos[nodo_atual].proximo;
            } else {
                lista->elementos[nodo_anterior].proximo = lista->elementos[nodo_atual].proximo;
            }

            liberar_nodo(lista, nodo_atual);
            lista->tamanho--;
            return 1;
        }

        nodo_anterior = nodo_atual;
        nodo_atual = lista->elementos[nodo_atual].proximo;
    }

    return 0;
}

void imprimir(ListaLigada lista) {
    int nodo_atual = lista.inicio;

    while (nodo_atual != -1) {
        printf("%d ", lista.elementos[nodo_atual].valor);
        nodo_atual = lista.elementos[nodo_atual].proximo;
    }

    printf("\n");
}

int main() {
    ListaLigada lista;
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
