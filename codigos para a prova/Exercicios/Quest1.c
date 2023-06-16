#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100

typedef struct Aluno {
    int codigo;
    char nome[50];
    int idade;
    int num_filhos;
} Aluno;

typedef struct {
    Aluno alunos[MAX_ALUNOS];
    int tamanho;
} ListaLigada;

void criar_lista(ListaLigada* lista) {
    lista->tamanho = 0;
}

int esta_vazia(ListaLigada lista) {
    return lista.tamanho == 0;
}

int esta_cheia(ListaLigada lista) {
    return lista.tamanho == MAX_ALUNOS;
}

int verificar_duplicidade(ListaLigada lista, Aluno aluno) {
    for (int i = 0; i < lista.tamanho; i++) {
        if (lista.alunos[i].codigo == aluno.codigo &&
            strcmp(lista.alunos[i].nome, aluno.nome) == 0 &&
            lista.alunos[i].idade == aluno.idade &&
            lista.alunos[i].num_filhos == aluno.num_filhos) {
            return 1;
        }
    }
    return 0;
}

void inserir(ListaLigada* lista, Aluno aluno) {
    if (esta_cheia(*lista)) {
        printf("A lista está cheia. Não é possível inserir mais alunos.\n");
        return;
    }

    if (verificar_duplicidade(*lista, aluno)) {
        printf("O aluno já está duplicado na lista. Não é possível inserir.\n");
        return;
    }

    lista->alunos[lista->tamanho] = aluno;
    lista->tamanho++;
}

void imprimir(ListaLigada lista) {
    for (int i = 0; i < lista.tamanho; i++) {
        printf("Código: %d, Nome: %s, Idade: %d, Número de Filhos: %d\n",
               lista.alunos[i].codigo, lista.alunos[i].nome, lista.alunos[i].idade, lista.alunos[i].num_filhos);
    }
}

int main() {
    ListaLigada lista;
    criar_lista(&lista);

    Aluno aluno1 = {1, "Alice", 20, 0};
    Aluno aluno2 = {2, "Bob", 22, 1};
    Aluno aluno3 = {3, "Charlie", 19, 2};

    inserir(&lista, aluno1);
    inserir(&lista, aluno2);
    inserir(&lista, aluno3);

    // Inserir um aluno duplicado
    Aluno alunoDuplicado = {1, "Alice", 20, 0};
    inserir(&lista, alunoDuplicado);

    // Imprimir os elementos da lista
    printf("Elementos da lista:\n");
    imprimir(lista);

    return 0;
}


// strlen --> Tamanho da String
//strcpy --> Copiar uma string
// strcat --> Concatenar duas strings
// strcmp --> Comparar duas strings
