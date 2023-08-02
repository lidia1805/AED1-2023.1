#include "arvoreBin.h"
#include <stdio.h>

int main(){
	printf("ola");
	
	ARVORE* arvore = criaArvore();
	
	insereNo(arvore, arvore->raiz, 24);
	insereNo(arvore, arvore->raiz, 10);
	insereNo(arvore, arvore->raiz, 32);
	insereNo(arvore, arvore->raiz, 5);
	insereNo(arvore, arvore->raiz, 12);
	insereNo(arvore, arvore->raiz, 29);
	insereNo(arvore, arvore->raiz, 35);
	imprimeArvore(arvore->raiz);
	
	numeroDeNos(arvore);
	
	NO* noBuscado = (NO*) malloc(sizeof(NO));
	noBuscado = buscaNo(arvore->raiz, 5);
	
	printf("\n---IMPRIMINDO PREORDEM---\n");
	preOrdem(arvore->raiz);
	
	printf("\n---IMPRIMINDO INORDEM---\n");
	inOrdem(arvore->raiz);
	
	printf("\n---IMPRIMINDO POSORDEM---\n");
	posOrdem(arvore->raiz);
	
	return 0;
}
