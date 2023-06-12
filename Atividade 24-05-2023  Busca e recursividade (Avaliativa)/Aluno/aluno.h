#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    float coeficiente;
} ALUNO;

ALUNO criar_aluno(int codigo, const char* nome, int idade, float coeficiente);
void imprimir_aluno(ALUNO aluno);

#endif
