#include "Aviao.h"

void inicializaFila(FILA* fila){
	fila->inicio = NULL;
	fila->fim = NULL;
}

int inserirAviao(FILA* fila, AVIAO* novo_aviao){
   ELEMENTO* i;
   i = (ELEMENTO *) malloc(sizeof(ELEMENTO));
   if (i==NULL){
   	return 0;
   }
   
   i->proximo = NULL;
   if (fila->inicio == NULL){
   	fila->inicio = i;
   }
   else{
   	fila->fim->proximo = i;
   }
   fila->fim = i;
   return 1;
}

int numeroDeAvioes(FILA* fila){
	int cont = 0;
	ELEMENTO* atual = fila->inicio;
	if (fila->inicio == NULL){
		return 0;
	}
	while(atual != NULL){
		cont++;
		atual = atual->proximo;
	}
	printf("Número de aviões aguardando na fila de decolagem: %d\n", cont);
	
	return 1;
}

void autorizarDecolagem(FILA* fila) {
    if (fila->inicio != NULL) {
        ELEMENTO* atual = fila->inicio;
        printf("O avião %s com identificador %d está autorizado a decolar.\n", atual->aviao.nome, atual->aviao.num_id);

        fila->inicio = atual->proximo;
        free(atual);

        if (fila->inicio == NULL) {
            fila->fim = NULL;
        }
    }
}

void listarAvioes(FILA* fila) {
    ELEMENTO* atual = fila->inicio;
    if (atual == NULL) {
        printf("Nenhum avião na fila de espera.\n");
    } else {
        printf("Aviões na fila de espera:\n");
        while (atual != NULL) {
            printf("Nome: %s, Identificador: %d\n", atual->aviao.nome, atual->aviao.num_id);
            atual = atual->proximo;
        }
    }
}

void listarPrimeiroAviao(FILA* fila) {
    if (fila->inicio != NULL) {
        ELEMENTO* atual = fila->inicio;
        printf("Primeiro avião na fila de espera:\n");
        printf("Nome: %s, Identificador: %d\n", atual->aviao.nome, atual->aviao.num_id);
    } else {
        printf("Nenhum avião na fila de espera.\n");
    }
}
