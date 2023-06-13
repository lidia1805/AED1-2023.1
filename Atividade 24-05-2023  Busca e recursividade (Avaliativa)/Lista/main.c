#include <stdio.h>
#include "lista.h"

int main() {
 
    LISTA lista = criar_lista(5);
    inserir_elemento(&lista, 10);
    inserir_elemento(&lista, 20);
    inserir_elemento(&lista, 30);
    inserir_elemento(&lista, 40);
    inserir_elemento(&lista, 50);
    imprimir_lista(lista);
    int posicao = buscar_sequencial(lista, 30);
    if (posicao != -1) {
        printf("Elemento 30 encontrado na posição %d\n", posicao);
    } else {
        printf("Elemento 30 não encontrado\n");
    }
    int maior = buscar_maior_elemento(lista);
    printf("Maior elemento da lista: %d\n", maior);
    int soma = soma_elementos_iterativa(lista);
    printf("Soma dos elementos da lista: %d\n", soma);
    liberar_lista(&lista);
}
