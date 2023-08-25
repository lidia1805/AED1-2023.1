#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"
#include "pilha.h"

ArvoreBinaria* criarArvoreBinaria() {
    ArvoreBinaria* arvore = (ArvoreBinaria*)malloc(sizeof(ArvoreBinaria));
    if (arvore) {
        arvore->raiz = NULL;
    }
    return arvore;
}

void destruirArvore(NoArvore* no) {
    if (no) {
        destruirArvore(no->esquerda);
        destruirArvore(no->direita);
        free(no);
    }
}

void destruirArvoreBinaria(ArvoreBinaria* arvore) {
    if (arvore) {
        destruirArvore(arvore->raiz);
        free(arvore);
    }
}

NoArvore* criarNo(char dado) {
    NoArvore* novoNo = (NoArvore*)malloc(sizeof(NoArvore));
    if (novoNo) {
        novoNo->dado = dado;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

void inserirElemento(ArvoreBinaria* arvore, char dado) {
    if (!arvore->raiz) {
        arvore->raiz = criarNo(dado);
        return;
    }

    NoArvore* atual = arvore->raiz;
    while (1) {
        if (dado < atual->dado) {
            if (atual->esquerda) {
                atual = atual->esquerda;
            } else {
                atual->esquerda = criarNo(dado);
                break;
            }
        } else if (dado > atual->dado) {
            if (atual->direita) {
                atual = atual->direita;
            } else {
                atual->direita = criarNo(dado);
                break;
            }
        } 
    }
}


void imprimirInfixa(NoArvore* no) {
    if (no) {
        imprimirInfixa(no->esquerda);
        printf("%c ", no->dado);
        imprimirInfixa(no->direita);
    }
}

void imprimirPosfixa(NoArvore* no) {
    if (no) {
        imprimirPosfixa(no->esquerda);
        imprimirPosfixa(no->direita);
        printf("%c ", no->dado);
    }
}

void imprimirPrefixa(NoArvore* no) {
    if (no) {
        printf("%c ", no->dado);
        imprimirPrefixa(no->esquerda);
        imprimirPrefixa(no->direita);
    }
}

void avaliarExpressao(NoArvore* no, Pilha* pilha) {
    if (no) {
        if (isdigit(no->dado)) {
            empilhar(pilha, no->dado);
        } else {
            avaliarExpressao(no->esquerda, pilha);
            avaliarExpressao(no->direita, pilha);
            int operando2 = desempilhar(pilha) - '0'; // Convertendo char para int
            int operando1 = desempilhar(pilha) - '0';
            int resultado;

            switch (no->dado) {
                case '+':
                    resultado = operando1 + operando2;
                    break;
                case '-':
                    resultado = operando1 - operando2;
                    break;
                case '*':
                    resultado = operando1 * operando2;
                    break;
                case '/':
                    resultado = operando1 / operando2;
                    break;
            }

            char resultadoChar = resultado + '0'; // Convertendo int para char
            empilhar(pilha, resultadoChar);
        }
    }
}

