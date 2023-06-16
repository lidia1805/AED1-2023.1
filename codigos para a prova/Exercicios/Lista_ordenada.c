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

int estaOrdenada(LinkedList lista, int ordem) {
    if (lista.head == NULL || lista.head->next == NULL) {
        return 1; // Lista vazia ou com apenas um elemento está sempre ordenada
    }

    Node* atual = lista.head;
    while (atual->next != NULL) {
        if ((ordem == 1 && atual->data > atual->next->data) || (ordem == -1 && atual->data < atual->next->data)) {
            return 0; // Lista não está ordenada
        }
        atual = atual->next;
    }

    return 1; // Lista está ordenada
}

int main() {
    LinkedList lista;
    inicializarLista(&lista);

    // Inserir elementos na lista
    inserirNo(&lista, 15);
    inserirNo(&lista, 28);
    inserirNo(&lista, 9);
    inserirNo(&lista, 31);
    inserirNo(&lista, 2);

    int ordem = -1; // Define a ordem como decrescente

    if (estaOrdenada(lista, ordem)) {
        if (ordem == 1) {
            printf("A lista está ordenada em ordem crescente.\n");
        } else {
            printf("A lista está ordenada em ordem decrescente.\n");
        }
    } else {
        printf("A lista não está ordenada.\n");
    }

    return 0;
}

//função para verificar se uma lista ligada está ordenada em ordem crescente ou decrescente
