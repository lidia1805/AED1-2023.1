#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* proximo;
} Nodo;

typedef struct {
    Nodo* inicio;
    int tamanho;
} ListaLigada;

void criar_lista(ListaLigada* lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int esta_vazia(ListaLigada lista) {
    return lista.inicio == NULL;
}

int tamanho(ListaLigada lista) {
    return lista.tamanho;
}

Nodo* criar_nodo(int valor) {
    Nodo* novo_nodo = (Nodo*)malloc(sizeof(Nodo));
    novo_nodo->valor = valor;
    novo_nodo->proximo = NULL;
    return novo_nodo;
}

void inserir(ListaLigada* lista, int valor) {
    Nodo* novo_nodo = criar_nodo(valor);

    if (esta_vazia(*lista)) {
        lista->inicio = novo_nodo;
    } else {
        Nodo* nodo_atual = lista->inicio;
        while (nodo_atual->proximo != NULL) {
            nodo_atual = nodo_atual->proximo;
        }
        nodo_atual->proximo = novo_nodo;
    }

    lista->tamanho++;
}

void inserir_ordenado(ListaLigada* lista, int valor) {
    Nodo* novo_nodo = criar_nodo(valor);

    if (esta_vazia(*lista) || valor < lista->inicio->valor) {
        novo_nodo->proximo = lista->inicio;
        lista->inicio = novo_nodo;
    } else {
        Nodo* nodo_atual = lista->inicio;
        Nodo* nodo_anterior = NULL;

        while (nodo_atual != NULL && valor > nodo_atual->valor) {
            nodo_anterior = nodo_atual;
            nodo_atual = nodo_atual->proximo;
        }

        novo_nodo->proximo = nodo_atual;
        nodo_anterior->proximo = novo_nodo;
    }

    lista->tamanho++;
}

int buscar_sequencial(ListaLigada lista, int valor) {
    Nodo* nodo_atual = lista.inicio;
    int posicao = 0;

    while (nodo_atual != NULL) {
        if (nodo_atual->valor == valor) {
            return posicao;
        }
        nodo_atual = nodo_atual->proximo;
        posicao++;
    }

    return -1;
}

int busca_binaria(ListaLigada lista, int valor) {
    printf("A busca binária não é aplicável a uma lista ligada dinâmica.\n");
    return -1;
}

int excluir_pela_posicao(ListaLigada* lista, int posicao) {
    if (posicao >= 0 && posicao < lista->tamanho) {
        Nodo* nodo_atual = lista->inicio;
        Nodo* nodo_anterior = NULL;
        int i = 0;

        while (i < posicao) {
            nodo_anterior = nodo_atual;
            nodo_atual = nodo_atual->proximo;
            i++;
        }

        if (nodo_anterior == NULL) {
            lista->inicio = nodo_atual->proximo;
        } else {
            nodo_anterior->proximo = nodo_atual->proximo;
        }

        free(nodo_atual);
        lista->tamanho--;
        return 1;
    }

    return 0;
}

int excluir_pelo_valor(ListaLigada* lista, int valor) {
    Nodo* nodo_atual = lista->inicio;
    Nodo* nodo_anterior = NULL;

    while (nodo_atual != NULL) {
        if (nodo_atual->valor == valor) {
            if (nodo_anterior == NULL) {
                lista->inicio = nodo_atual->proximo;
            } else {
                nodo_anterior->proximo = nodo_atual->proximo;
            }

            free(nodo_atual);
            lista->tamanho--;
            return 1;
        }

        nodo_anterior = nodo_atual;
        nodo_atual = nodo_atual->proximo;
    }

    return 0;
}

void imprimir(ListaLigada lista) {
    Nodo* nodo_atual = lista.inicio;

    while (nodo_atual != NULL) {
        printf("%d ", nodo_atual->valor);
        nodo_atual = nodo_atual->proximo;
    }
    printf("\n");
}

void liberar_lista(ListaLigada* lista) {
    Nodo* nodo_atual = lista->inicio;

    while (nodo_atual != NULL) {
        Nodo* nodo_temp = nodo_atual;
        nodo_atual = nodo_atual->proximo;
        free(nodo_temp);
    }

    lista->inicio = NULL;
    lista->tamanho = 0;
}

int main() {
    ListaLigada lista;
    criar_lista(&lista);

    // Inserir elementos na lista sem importar a ordem
    inserir(&lista, 4);
    inserir(&lista, 2);
    inserir(&lista, 6);
    inserir(&lista, 1);
    inserir(&lista, 3);

    // Inserir um elemento na lista de forma ordenada
    inserir_ordenado(&lista, 5);

    // Imprimir os elementos da lista
    printf("Elementos da lista: ");
    imprimir(lista);

    // Retornar a quantidade de elementos na lista
    printf("Quantidade de elementos na lista: %d\n", tamanho(lista));

    // Buscar um elemento sequencialmente na lista
    int posicao = buscar_sequencial(lista, 3);
    if (posicao != -1) {
        printf("Elemento 3 encontrado na posição %d\n", posicao);
    } else {
        printf("Elemento 3 não encontrado na lista\n");
    }

    // Buscar um elemento usando busca binária
    int posicao_binaria = busca_binaria(lista, 4);
