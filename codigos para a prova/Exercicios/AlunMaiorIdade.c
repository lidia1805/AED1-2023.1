#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    int num_filhos;
} Aluno;

typedef struct {
    Aluno elementos[MAX_SIZE];
    int tamanho;
} ListaEstatica;

void criar_lista(ListaEstatica* lista) {
    lista->tamanho = 0;
}

int esta_vazia(ListaEstatica lista) {
    return lista.tamanho == 0;
}

int esta_cheia(ListaEstatica lista) {
    return lista.tamanho == MAX_SIZE;
}

void inserir(ListaEstatica* lista, Aluno aluno) {
    if (esta_cheia(*lista)) {
        printf("A lista está cheia. Não é possível inserir mais elementos.\n");
        return;
    }

    lista->elementos[lista->tamanho] = aluno;
    lista->tamanho++;
}

Aluno encontrar_aluno_maior_idade(ListaEstatica lista) {
    if (esta_vazia(lista)) {
        printf("A lista está vazia. Não há alunos para retornar.\n");
        Aluno aluno_vazio = {0, "", 0, 0};
        return aluno_vazio; // Retorna um aluno vazio (valores zerados) como indicação de erro
    }

    Aluno aluno_maior_idade = lista.elementos[0];

    for (int i = 1; i < lista.tamanho; i++) {
        if (lista.elementos[i].idade > aluno_maior_idade.idade) {
            aluno_maior_idade = lista.elementos[i];
        }
    }

    return aluno_maior_idade;
}

void imprimir_dados_aluno(Aluno aluno) {
    printf("Código: %d\n", aluno.codigo);
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Número de filhos: %d\n", aluno.num_filhos);
}

int main() {
    ListaEstatica lista;
    criar_lista(&lista);

    // Inserir alunos na lista
    Aluno aluno1 = {1, "Daniel", 21, 0};
    Aluno aluno2 = {2, "Suza", 19, 0};
    Aluno aluno3 = {3, "Danilo", 24, 1};
    Aluno aluno4 = {4, "Camila", 18, 0};
    Aluno aluno5 = {5, "Carlos", 22, 1};

    inserir(&lista, aluno1);
    inserir(&lista, aluno2);
    inserir(&lista, aluno3);
    inserir(&lista, aluno4);
    inserir(&lista, aluno5);

    // Encontrar o aluno com maior idade
    Aluno aluno_maior_idade = encontrar_aluno_maior_idade(lista);

    // Imprimir os dados do aluno com maior idade
    printf("Dados do aluno com maior idade:\n");
    imprimir_dados_aluno(aluno_maior_idade);

    return 0;
}
