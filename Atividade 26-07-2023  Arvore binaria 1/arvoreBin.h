#define ARVORE_BIN_H
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0 

typedef int bool;

typedef struct aux{
	int valor;
	aux* esquerda;
	aux* direita;
}NO;

typedef struct {
	int quant;
	NO* raiz;
}ARVORE;

ARVORE* criaArvore();
NO* criaNo(int valor);
void insereNo(ARVORE* arv, NO* raiz, int valor);
