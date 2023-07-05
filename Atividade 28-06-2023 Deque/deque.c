#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

void inicializarDeque(Deque* deque) {
    deque->inicio = 0;
    deque->fim = -1;
}

int dequeVazio(Deque* deque) {
    return (deque->fim < deque->inicio);
}

int dequeCheio(Deque* deque) {
    return (deque->fim - deque->inicio + 1 == MAX_ALUNOS);
}

void inserirInicio(Deque* deque, char* nome, int posicao) {
    if (dequeCheio(deque)) {
        printf("O deque está cheio.\n");
        return;
    }

    Aluno novoAluno;
    strcpy(novoAluno.nome, nome);
    novoAluno.posicao = posicao;

    deque->inicio--;

    if (deque->inicio < 0)
        deque->inicio = MAX_ALUNOS - 1;

    deque->alunos[deque->inicio] = novoAluno;
}

void exibe(Deque* deque, int posicao, char ordem) {
    if (dequeVazio(deque)) {
        printf("O deque está vazio.\n");
        return;
    }

    if (posicao < 1 || posicao > MAX_ALUNOS) {
        printf("Posição inválida.\n");
        return;
    }

    printf("Alunos:\n");

    int i;
    if (ordem == 'd') {
        for (i = posicao - 1; i < deque->fim; i++) {
            Aluno aluno = deque->alunos[i % MAX_ALUNOS];
            printf("%s\n", aluno.nome);
        }
    } else if (ordem == 'i') {
        for (i = posicao - 1; i >= deque->inicio; i--) {
            Aluno aluno = deque->alunos[i % MAX_ALUNOS];
            printf("%s\n", aluno.nome);
        }
    } else {
        printf("Ordem inválida.\n");
    }
}
