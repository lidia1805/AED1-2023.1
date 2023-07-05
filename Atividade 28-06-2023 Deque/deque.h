#ifndef DEQUE_H
#define DEQUE_H

#define MAX_NOME 50
#define MAX_ALUNOS 40

typedef struct {
    char nome[MAX_NOME];
    int posicao;
} Aluno;

typedef struct {
    Aluno alunos[MAX_ALUNOS];
    int inicio;
    int fim;
} Deque;

void inicializarDeque(Deque* deque);
int dequeVazio(Deque* deque);
int dequeCheio(Deque* deque);
void inserirInicio(Deque* deque, char* nome, int posicao);
void exibe(Deque* deque, int posicao, char ordem);

#endif
