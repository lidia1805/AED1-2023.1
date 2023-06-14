#include <stdio.h>
#include "lista.h"

int main() {
    Lista listaL, listaK;
    int valor;
    
    inicializarLista(&listaL);
    inicializarLista(&listaK);
    
    printf("Insira os elementos da lista L (insira -1 para parar):\n");
    
    while (1) {
        scanf("%d", &valor);
        
        if (valor == -1) {
            break;
        }
        
        inserirNoInicio(&listaL, valor);
    }
    
    printf("Lista L desordenada: ");
    imprimirLista(&listaL);
    
    while (listaL.head != NULL) {
        Node* maxNode = listaL.head;
        Node* current = listaL.head->next;
        
        while (current != NULL) {
            if (current->data > maxNode->data) {
                maxNode = current;
            }
            
            current = current->next;
        }
        
        inserirNoInicio(&listaK, maxNode->data);
        removerNoInicio(&listaL);
    }
    
    printf("Lista K ordenada: ");
    imprimirLista(&listaK);
    
    return 0;
}
