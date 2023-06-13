#ifndef TURMA_H
#define TURMA_H

#include "aluno.h"

typedef struct {
    ALUNO* alunos;
    int quantidade;
} TURMA;

TURMA criar_turma(int quantidade);
void liberar_turma(TURMA* turma);
void inserir_aluno(TURMA* turma, ALUNO aluno);
void buscar_aluno_sequencial(TURMA turma, int codigo);
void buscar_aluno_binaria(TURMA turma, int codigo);
void imprimir_turma(TURMA turma);

#endif
