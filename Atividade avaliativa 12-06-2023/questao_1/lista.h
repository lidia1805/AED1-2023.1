#ifndef LISTA_H
#define LISTA_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Lista;

void inicializarLista(Lista* lista);
void inserirNoInicio(Lista* lista, int valor);
void removerNoInicio(Lista* lista);
void imprimirLista(Lista* lista);

#endif
