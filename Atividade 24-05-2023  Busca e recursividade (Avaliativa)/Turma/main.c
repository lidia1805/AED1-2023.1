#include <stdio.h>
#include "turma.h"

int main() {
   
    TURMA turma = criar_turma(2);
    inserir_aluno(&turma, aluno1);
    inserir_aluno(&turma, aluno2);
    imprimir_turma(turma);
    buscar_aluno_sequencial(turma, 2);
    buscar_aluno_binaria(turma, 2);
    liberar_turma(&turma);

    return 0;
}
