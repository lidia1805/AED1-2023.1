#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

LISTA criar_lista(int quantidade) {
    LISTA lista;
    lista.vetor = (int*)malloc(quantidade * sizeof(int));
    lista.quantidade = quantidade;
    return lista;
}

void liberar_lista(LISTA* lista) {
    free(lista->vetor);
    lista->quantidade = 0;
}

void inserir_elemento(LISTA* lista, int elemento) {
    lista->vetor[lista->quantidade] = elemento;
    lista->quantidade++;
}

void inserir_elemento_ordenado(LISTA* lista, int elemento) {
    int i = lista->quantidade - 1;
    while (i >= 0 && lista->vetor[i] > elemento) {
        lista->vetor[i + 1] = lista->vetor[i];
        i--;
    }
    lista->vetor[i + 1] = elemento;
    lista->quantidade++;
}

void imprimir_lista(LISTA lista) {
    int i;
    for (i = 0; i < lista.quantidade; i++) {
        printf("%d ", lista.vetor[i]);
    }
    printf("\n");
}

int buscar_sequencial(LISTA lista, int elemento) {
    int i;
    for (i = 0; i < lista.quantidade; i++) {
        if (lista.vetor[i] == elemento) {
            return i;
        }
    }
    return -1;
}

int buscar_sequencial_ordenado(LISTA lista, int elemento) {
    int i;
    for (i = 0; i < lista.quantidade; i++) {
        if (lista.vetor[i] == elemento) {
            return i;
        } else if (lista.vetor[i] > elemento) {
            return -1;
        }
    }
    return -1;
}

int busca_binaria_iterativa(LISTA lista, int elemento) {
    int inicio = 0;
    int fim = lista.quantidade - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista.vetor[meio] == elemento) {
            return meio;
        } else if (lista.vetor[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int busca_binaria_recursiva(LISTA lista, int elemento, int inicio, int fim) {
    if (inicio > fim) {
        return -1;
    }
    int meio = (inicio + fim) / 2;
    if (lista.vetor[meio] == elemento) {
        return meio;
    } else if (lista.vetor[meio] < elemento) {
        return busca_binaria_recursiva(lista, elemento, meio + 1, fim);
    } else {
        return busca_binaria_recursiva(lista, elemento, inicio, meio - 1);
    }
}

void imprimir_lista_recursiva(LISTA lista, int indice) {
    if (indice >= lista.quantidade) {
        printf("\n");
        return;
    }
    printf("%d ", lista.vetor[indice]);
    imprimir_lista_recursiva(lista, indice + 1);
}

int buscar_maior_elemento(LISTA lista) {
    int i;
    int maior = lista.vetor[0];
    for (i = 1; i < lista.quantidade; i++) {
        if (lista.vetor[i] > maior) {
            maior = lista.vetor[i];
        }
    }
    return maior;
}

int buscar_maior_elemento_recursivo(LISTA lista, int indice) {
    if (indice == lista.quantidade - 1) {
        return lista.vetor[indice];
    }
    int proximo_maior = buscar_maior_elemento_recursivo(lista, indice + 1);
    if (lista.vetor[indice] > proximo_maior) {
        return lista.vetor[indice];
    } else {
        return proximo_maior;
    }
}

int buscar_menor_elemento(LISTA lista) {
    int i;
    int menor = lista.vetor[0];
    for (i = 1; i < lista.quantidade; i++) {
        if (lista.vetor[i] < menor) {
            menor = lista.vetor[i];
        }
    }
    return menor;
}

int buscar_menor_elemento_recursivo(LISTA lista, int indice) {
    if (indice == lista.quantidade - 1) {
        return lista.vetor[indice];
    }
    int proximo_menor = buscar_menor_elemento_recursivo(lista, indice + 1);
    if (lista.vetor[indice] < proximo_menor) {
        return lista.vetor[indice];
    } else {
        return proximo_menor;
    }
}

int soma_elementos_iterativa(LISTA lista) {
    int i;
    int soma = 0;
    for (i = 0; i < lista.quantidade; i++) {
        soma += lista.vetor[i];
    }
    return soma;
}

int soma_elementos_recursiva(LISTA lista, int indice) {
    if (indice == lista.quantidade) {
        return 0;
    }
    return lista.vetor[indice] + soma_elementos_recursiva(lista, indice + 1);
}

int produto_elementos_iterativa(LISTA lista) {
    int i;
    int produto = 1;
    for (i = 0; i < lista.quantidade; i++) {
        produto *= lista.vetor[i];
    }
    return produto;
}

int produto_elementos_recursiva(LISTA lista, int indice) {
    if (indice == lista.quantidade) {
        return 1;
    }
    return lista.vetor[indice] * produto_elementos_recursiva(lista, indice + 1);
}
