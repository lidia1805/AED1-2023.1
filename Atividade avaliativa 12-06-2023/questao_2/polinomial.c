#include "polinomial.h"
#include <stdio.h>
#include <stdlib.h>

//Questão A
Node* criar_no(int coeficiente, int expoente) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    novo_no->coeficiente = coeficiente;
    novo_no->expoente = expoente;
    novo_no->proximo = NULL;
    return novo_no;
}

Node* inserir_polinomio(int coeficiente, int expoente, Node* lista) {
    Node* novo_no = criar_no(coeficiente, expoente);

    if (lista == NULL) {
        return novo_no;
    }

    Node* anterior = NULL;
    Node* atual = lista;
    while (atual != NULL && atual->expoente > expoente) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        novo_no->proximo = lista;
        return novo_no;
    } else {
        anterior->proximo = novo_no;
        novo_no->proximo = atual;
        return lista;
    }
}

//Questao B
Node* somar_polinomios(Node* P1, Node* P2) {
    Node* resultado = NULL;
    Node* p1_atual = P1;
    Node* p2_atual = P2;

    while (p1_atual != NULL && p2_atual != NULL) {
        if (p1_atual->expoente > p2_atual->expoente) {
            resultado = inserir_polinomio(p1_atual->coeficiente, p1_atual->expoente, resultado);
            p1_atual = p1_atual->proximo;
        } else if (p1_atual->expoente < p2_atual->expoente) {
            resultado = inserir_polinomio(p2_atual->coeficiente, p2_atual->expoente, resultado);
            p2_atual = p2_atual->proximo;
        } else {
            int coeficiente_soma = p1_atual->coeficiente + p2_atual->coeficiente;
            if (coeficiente_soma != 0) {
                resultado = inserir_polinomio(coeficiente_soma, p1_atual->expoente, resultado);
            }
            p1_atual = p1_atual->proximo;
            p2_atual = p2_atual->proximo;
        }
    }

    while (p1_atual != NULL) {
        resultado = inserir_polinomio(p1_atual->coeficiente, p1_atual->expoente, resultado);
        p1_atual = p1_atual->proximo;
    }

    while (p2_atual != NULL) {
        resultado = inserir_polinomio(p2_atual->coeficiente, p2_atual->expoente, resultado);
        p2_atual = p2_atual->proximo;
    }

    return resultado;
}

//Questão C
void imprimir_polinomio(Node* lista) {
    if (lista == NULL) {
        printf("0\n");
        return;
    }

    while (lista != NULL) {
        printf("%dx^%d ", lista->coeficiente, lista->expoente);
        lista = lista->proximo;
        if (lista != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

void liberar_polinomio(Node* lista) {
    Node* atual = lista;
    while (atual != NULL) {
        Node* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}
