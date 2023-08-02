#ifndef ARVORE_BIN_H

#include <stdio.h>
#include <stdlib.h>
#define ARVORE_BIN_H
#define true 1
#define false 0 

typedef int bool;

typedef struct aux{
	int valor;
	struct aux* esquerda;
	struct aux* direita;
}NO;

typedef struct {
	int quant;
	NO* raiz;
}ARVORE;

ARVORE* criaArvore();
NO* criaNo(int valor);
void insereNo(ARVORE* arv, NO* raiz, int valor);
void imprimeArvore(NO* raiz);
NO* buscaNo(NO* raiz, int valor);
void numeroDeNos(ARVORE* arv);
void preOrdem(NO* raiz);
void posOrdem(NO* raiz);
void inOrdem(NO* raiz);

#endif
