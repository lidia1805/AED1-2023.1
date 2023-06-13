#include <stdio.h>
#include <stdlib.h>
#include "turma.h"

TURMA criar_turma(int quantidade) {
    TURMA turma;
    turma.alunos = (ALUNO*)malloc(quantidade * sizeof(ALUNO));
    turma.quantidade = quantidade;
    return turma;
}

void liberar_turma(TURMA* turma) {
    free(turma->alunos);
    turma->quantidade = 0;
}

void inserir_aluno(TURMA* turma, ALUNO aluno) {
    turma->alunos[turma->quantidade] = aluno;
    turma->quantidade++;
}

void buscar_aluno_sequencial(TURMA turma, int codigo) {
    int i;
    for (i = 0; i < turma.quantidade; i++) {
        if (turma.alunos[i].codigo == codigo) {
            imprimir_aluno(turma.alunos[i]);
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}

void buscar_aluno_binaria_recursiva(TURMA turma, int codigo, int inicio, int fim) {
    if (inicio > fim) {
        printf("Aluno não encontrado.\n");
        return;
    }
    int meio = (inicio + fim) / 2;
    if (turma.alunos[meio].codigo == codigo) {
        imprimir_aluno(turma.alunos[meio]);
    } else if (turma.alunos[meio].codigo < codigo) {
        buscar_aluno_binaria_recursiva(turma, codigo, meio + 1, fim);
    } else {
        buscar_aluno_binaria_recursiva(turma, codigo, inicio, meio - 1);
    }
}

void buscar_aluno_binaria(TURMA turma, int codigo) {
    buscar_aluno_binaria_recursiva(turma, codigo, 0, turma.quantidade - 1);
}

void imprimir_turma(TURMA turma) {
    int i;
    for (i = 0; i < turma.quantidade; i++) {
        imprimir_aluno(turma.alunos[i]);
        printf("\n");
    }
}
