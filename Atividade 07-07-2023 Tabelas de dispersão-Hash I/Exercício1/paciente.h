#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    int codigo;
    char nome[50];
    char cpf[12];
    int idade;
} Paciente;

#endif
