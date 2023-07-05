#include <stdio.h>
#include "deque.h"

int main() {
    Deque deque;
    inicializarDeque(&deque);

    inserirInicio(&deque, "João", 1);
    inserirInicio(&deque, "Maria", 2);
    inserirInicio(&deque, "Pedro", 3);
    // Insira os outros nomes dos alunos conforme necessário

    int posicao;
    char ordem;

    printf("Digite a posição inicial: ");
    scanf("%d", &posicao);

    printf("Digite a ordem (d para direta, i para inversa): ");
    scanf(" %c", &ordem);

    exibe(&deque, posicao, ordem);

    return 0;
}
