#include "arvoreBin.h"

ARVORE* criaArvore(){
	ARVORE* arv = (ARVORE*) malloc(sizeof(ARVORE));
	arv->quant = 0;
	arv->raiz = NULL;
	return arv;
}

NO* criaNo(int valor){
	NO* no = (NO*) malloc(sizeof(NO));
	no->valor = valor;
	no->direita = NULL;
	no->esquerda = NULL;
	return no;
}

void insereNo(ARVORE* arv, NO* raiz, int valor){
	if(raiz == NUL){
		NO* no = criaNo(valor);
		arv->raiz = no;
		arv->quant++;
	}
	if(raiz->valor > valor){
		
		if(raiz->esquerda != NULL){
			return insereNo(arv, raiz->esquerda, valor);
		}
		NO* no = criaNo(valor);
		raiz->esquerda = no;
		arv->quant++;
	}
	else if(raiz->direita <= valor){
		
		if(raiz->direita != NULL){
			return insereNo(arv, raiz->direita, valor);
		}
		NO* no = criaNo(valor);
		raiz->direita = no;
		arv->quant++;
	}
}

NO* buscaNo(NO* raiz, int valor){
	if(raiz == NULL) return NULL;
	
	if(raiz->valor == valor){
		return raiz;
	}
	if(raiz->valor > valor){
		return buscaNo(raiz->esquerda, valor);
	}
	return buscaNo(raiz->direita, valor); 
	
}


