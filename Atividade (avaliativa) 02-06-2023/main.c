#include "lista_alunos.h"
#include <stdio.h>

int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    Aluno aluno1 = {123, "Joao", 20};
    Aluno aluno2 = {456, "Maria", 22};
    Aluno aluno3 = {789, "Pedro", 19};

    inserirElemento(&lista, aluno1);
    inserirElemento(&lista, aluno2);
    inserirElemento(&lista, aluno3);

    exibirLista(&lista);

    return 0;
}
