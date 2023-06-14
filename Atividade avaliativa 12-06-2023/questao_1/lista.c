#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializarLista(Lista* lista) {
    lista->head = NULL;
    lista->tail = NULL;
}

void inserirNoInicio(Lista* lista, int valor) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->data = valor;
    novoNode->prev = NULL;
    
    if (lista->head == NULL) {
        novoNode->next = NULL;
        lista->tail = novoNode;
    } else {
        novoNode->next = lista->head;
        lista->head->prev = novoNode;
    }
    
    lista->head = novoNode;
}

void removerNoInicio(Lista* lista) {
    if (lista->head == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    
    Node* nodeRemovido = lista->head;
    
    if (lista->head == lista->tail) {
        lista->head = NULL;
        lista->tail = NULL;
    } else {
        lista->head = lista->head->next;
        lista->head->prev = NULL;
    }
    
    free(nodeRemovido);
}

void imprimirLista(Lista* lista) {
    Node* current = lista->head;
    
    printf("Lista: ");
    
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");
}
