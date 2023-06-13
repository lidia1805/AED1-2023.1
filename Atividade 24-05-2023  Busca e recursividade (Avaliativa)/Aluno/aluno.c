#include <stdio.h>
#include "aluno.h"

ALUNO criar_aluno(int codigo, const char* nome, int idade, float coeficiente) {
    ALUNO aluno;
    aluno.codigo = codigo;
    strcpy(aluno.nome, nome);
    aluno.idade = idade;
    aluno.coeficiente = coeficiente;
    return aluno;
}

void imprimir_aluno(ALUNO aluno) {
    printf("Código: %d\n", aluno.codigo);
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Coeficiente: %.2f\n", aluno.coeficiente);
}
