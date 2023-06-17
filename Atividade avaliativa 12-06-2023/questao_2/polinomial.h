#ifndef POLINOMIAL_H
#define POLINOMIAL_H

typedef struct Node {
    int coeficiente;
    int expoente;
    struct Node* proximo;
} Node;

Node* criar_no(int coeficiente, int expoente);
Node* inserir_polinomio(int coeficiente, int expoente, Node* lista);
Node* somar_polinomios(Node* P1, Node* P2);
void imprimir_polinomio(Node* lista);
void liberar_polinomio(Node* lista);

#endif 
