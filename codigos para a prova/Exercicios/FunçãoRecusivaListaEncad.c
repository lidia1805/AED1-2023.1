#include <stdio.h>
#include <stdlib.h>

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

void imprimirListaRecursiva(Node* no) {
    if (no == NULL) {
        return;
    }

    printf("%d ", no->data);
    imprimirListaRecursiva(no->next);
}

void imprimirLista(LinkedList lista) {
    imprimirListaRecursiva(lista.head);
    printf("\n");
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

    printf("Lista: ");
    imprimirLista(lista);

    return 0;
}
