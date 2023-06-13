#include <stdio.h>
#include "aluno.h"

int main() {
    
    ALUNO aluno1 = criar_aluno(1, "João", 20, 8.5);
    ALUNO aluno2 = criar_aluno(2, "Maria", 22, 9.0);
    imprimir_aluno(aluno1);
    printf("\n");
    imprimir_aluno(aluno2); 
    
    return 0;
}
