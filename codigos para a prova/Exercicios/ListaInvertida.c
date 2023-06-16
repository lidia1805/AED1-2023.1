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

void imprimirLista(LinkedList lista) {
    Node* atual = lista.head;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

void inverterLista(LinkedList* L1, LinkedList* L2) {
    Node* atual = L1->head;
    while (atual != NULL) {
        Node* novoNo = (Node*)malloc(sizeof(Node));
        novoNo->data = atual->data;
        novoNo->next = L2->head;
        L2->head = novoNo;
        atual = atual->next;
    }
}

int main() {
    LinkedList L1;
    LinkedList L2;
    inicializarLista(&L1);
    inicializarLista(&L2);

    // Inserir elementos na lista L1
    inserirNo(&L1, 1);
    inserirNo(&L1, 2);
    inserirNo(&L1, 3);
    inserirNo(&L1, 4);
    inserirNo(&L1, 5);

    printf("Lista L1 original: ");
    imprimirLista(L1);

    inverterLista(&L1, &L2);

    printf("Lista L2 invertida: ");
    imprimirLista(L2);

    return 0;
}
