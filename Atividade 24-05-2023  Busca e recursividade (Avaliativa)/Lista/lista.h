#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int* vetor;
    int quantidade;
} LISTA;

LISTA criar_lista(int quantidade);
void liberar_lista(LISTA* lista);
void inserir_elemento(LISTA* lista, int elemento);
void inserir_elemento_ordenado(LISTA* lista, int elemento);
void imprimir_lista(LISTA lista);
int buscar_sequencial(LISTA lista, int elemento);
int buscar_sequencial_ordenado(LISTA lista, int elemento);
int busca_binaria_iterativa(LISTA lista, int elemento);
int busca_binaria_recursiva(LISTA lista, int elemento, int inicio, int fim);
void imprimir_lista_recursiva(LISTA lista, int indice);
int buscar_maior_elemento(LISTA lista);
int buscar_maior_elemento_recursivo(LISTA lista, int indice);
int buscar_menor_elemento(LISTA lista);
int buscar_menor_elemento_recursivo(LISTA lista, int indice);
int soma_elementos_iterativa(LISTA lista);
int soma_elementos_recursiva(LISTA lista, int indice);
int produto_elementos_iterativa(LISTA lista);
int produto_elementos_recursiva(LISTA lista, int indice);

#endif
