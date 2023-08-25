#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct NoArvore {
    char dado;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;

typedef struct {
    NoArvore* raiz;
} ArvoreBinaria;

ArvoreBinaria* criarArvoreBinaria();
void destruirArvore(NoArvore* no);
void destruirArvoreBinaria(ArvoreBinaria* arvore);
NoArvore* criarNo(char dado);
void inserirElemento(ArvoreBinaria* arvore, char dado);
void imprimirInfixa(NoArvore* no);
void imprimirPosfixa(NoArvore* no);
void imprimirPrefixa(NoArvore* no);
void avaliarExpressao(NoArvore* no, Pilha* pilha);

#endif
