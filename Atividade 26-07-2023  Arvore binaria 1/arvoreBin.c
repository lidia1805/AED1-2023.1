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
	if(raiz == NULL){
		NO* no = criaNo(valor);
		arv->raiz = no;
		arv->quant = arv->quant + 1;
		return;
	}
	if(raiz->valor > valor){
		
		if(raiz->esquerda != NULL){
			return insereNo(arv, raiz->esquerda, valor);
		}
		NO* no = criaNo(valor);
		raiz->esquerda = no;
		arv->quant = arv->quant + 1;
	}
	else if(raiz->valor <= valor){
		
		if(raiz->direita != NULL){
			return insereNo(arv, raiz->direita, valor);
		}
		NO* no = criaNo(valor);
		raiz->direita = no;
		arv->quant = arv->quant + 1;
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

void imprimeArvore(NO* raiz){
	if (raiz == NULL){
		printf("Arvore vazia");
		return;
	}
	 printf("Raiz: %d\n", raiz->valor);
    printf("=> Esquerda: %d\n", raiz->valor);
    imprimeArvore(raiz->esquerda);
    printf("=> Direita: %d\n", raiz->valor);
    imprimeArvore(raiz->direita);
}

void numeroDeNos(ARVORE* arv){
	if(arv->quant == 0){
		printf("Arvore vazia");
		return;
	}
	int numero = arv->quant;
	printf("\nNumero de elementos na árvore: %d\n", numero);
}

void preOrdem(NO* raiz){
	if(raiz == NULL) return;
	printf("\n%d", raiz->valor);
	preOrdem(raiz->esquerda);
	preOrdem(raiz->direita);
}

void posOrdem(NO* raiz){
	if(raiz == NULL) return;
	posOrdem(raiz->esquerda);
	posOrdem(raiz->direita);
	printf("\n%d", raiz->valor);
}

void inOrdem(NO* raiz){
	if(raiz == NULL) return;
	inOrdem(raiz->esquerda);
	printf("\n%d", raiz->valor);
	inOrdem(raiz->direita);
}
