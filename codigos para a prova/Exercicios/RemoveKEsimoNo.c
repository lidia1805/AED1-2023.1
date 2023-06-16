#include <stdio.h>
#include <stdlib.h>

// Função que remove o k-esimo no da lista encadeada

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

void inicializarLista(LinkedList* lista) {
    lista->head = NULL;
}

void inserirNo(LinkedList* lista, int dado) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->data = dado;
    novoNo->next = NULL;

    if (lista->head == NULL) {
        lista->head = novoNo;
    } else {
        Node* atual = lista->head;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novoNo;
    }
}

void imprimirLista(LinkedList lista) {
    Node* atual = lista.head;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

void removerKEsimoNo(LinkedList* lista, int k) {
    if (k <= 0 || lista->head == NULL) {
        return;
    }

    if (k == 1) {
        Node* temp = lista->head;
        lista->head = lista->head->next;
        free(temp);
        return;
    }

    Node* anterior = NULL;
    Node* atual = lista->head;
    int contador = 1;

    while (atual != NULL && contador < k) {
        anterior = atual;
        atual = atual->next;
        contador++;
    }

    if (atual == NULL) {
        return;
    }

    anterior->next = atual->next;
    free(atual);
}

int main() {
    LinkedList lista;
    inicializarLista(&lista);

    // Inserir elementos na lista
    inserirNo(&lista, 1);
    inserirNo(&lista, 2);
    inserirNo(&lista, 3);
    inserirNo(&lista, 4);
    inserirNo(&lista, 5);

    printf("Lista original: ");
    imprimirLista(lista);

    int k = 3;
    removerKEsimoNo(&lista, k);

    printf("Lista após remover o %do nó: ", k);
    imprimirLista(lista);}

    return 0;
}
