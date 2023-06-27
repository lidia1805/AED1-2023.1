#ifndef AVIAO_H
#define AVIAO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[20];
	int num_id;
}AVIAO;

typedef struct aux{
	AVIAO aviao;
	struct aux* proximo;
} ELEMENTO;

typedef struct {
	ELEMENTO* inicio;
	ELEMENTO* fim;
}FILA;

void inicializaFila(FILA* fila);
int inserirAviao(FILA* fila, AVIAO* novo_aviao);
int numeroDeAvioes(FILA* fila);
void autorizarDecolagem(FILA* fila);
void listarPrimeiroAviao(FILA* fila);

#endif
