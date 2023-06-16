#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    int num_filhos;
    int proximo;
} Aluno;

typedef struct {
    Aluno elementos[MAX_SIZE];
    int tamanho;
    int inicio;
    int livre;
} ListaLigada;

void criar_lista(ListaLigada *lista) {
    lista->tamanho = 0;
    lista->inicio = -1;
    lista->livre = 0;

    int i;
    for (i = 0; i < MAX_SIZE - 1; i++) {
        lista->elementos[i].proximo = i + 1;
    }

    lista->elementos[MAX_SIZE - 1].proximo = -1;
}

int esta_vazia(ListaLigada lista) {
    return lista.tamanho == 0;
}

int tamanho(ListaLigada lista) {
    return lista.tamanho;
}

int obter_nodo_livre(ListaLigada *lista) {
    int nodo_livre = lista->livre;
    lista->livre = lista->elementos[lista->livre].proximo;
    return nodo_livre;
}

void liberar_nodo(ListaLigada *lista, int nodo) {
    lista->elementos[nodo].proximo = lista->livre;
    lista->livre = nodo;
}

void inserir(ListaLigada *lista, int codigo, const char *nome, int idade, int num_filhos) {
    if (lista->livre != -1) {
        int novo_nodo = obter_nodo_livre(lista);
        Aluno *aluno = &lista->elementos[novo_nodo];
        aluno->codigo = codigo;
        strncpy(aluno->nome, nome, sizeof(aluno->nome));
        aluno->idade = idade;
        aluno->num_filhos = num_filhos;
        aluno->proximo = -1;

        if (esta_vazia(*lista)) {
            lista->inicio = novo_nodo;
        } else {
            int nodo_atual = lista->inicio;
            while (lista->elementos[nodo_atual].proximo != -1) {
                nodo_atual = lista->elementos[nodo_atual].proximo;
            }
            lista->elementos[nodo_atual].proximo = novo_nodo;
        }

        lista->tamanho++;
    }
}

void inserir_ordenado(ListaLigada *lista, int codigo, const char *nome, int idade, int num_filhos) {
    if (lista->livre != -1) {
        int novo_nodo = obter_nodo_livre(lista);
        Aluno *aluno = &lista->elementos[novo_nodo];
        aluno->codigo = codigo;
        strncpy(aluno->nome, nome, sizeof(aluno->nome));
        aluno->idade = idade;
        aluno->num_filhos = num_filhos;

        if (esta_vazia(*lista) || codigo < lista->elementos[lista->inicio].codigo) {
            aluno->proximo = lista->inicio;
            lista->inicio = novo_nodo;
        } else {
            int nodo_atual = lista->inicio;
            int nodo_anterior = -1;

            while (nodo_atual != -1 && codigo > lista->elementos[nodo_atual].codigo) {
                nodo_anterior = nodo_atual;
                nodo_atual = lista->elementos[nodo_atual].proximo;
            }

            aluno->proximo = nodo_atual;
            lista->elementos[nodo_anterior].proximo = novo_nodo;
        }

        lista->tamanho++;
    }
}

int buscar_sequencial(ListaLigada lista, int codigo) {
    int nodo_atual = lista.inicio;

    while (nodo_atual != -1) {
        if (lista.elementos[nodo_atual].codigo == codigo) {
            return nodo_atual;
        }
        nodo_atual = lista.elementos[nodo_atual].proximo;
    }

    return -1;
}

int busca_binaria(ListaLigada lista, int codigo) {
    printf("A busca binária não é aplicável a uma lista ligada estática.\n");
    return -1;
}

int excluir_pela_posicao(ListaLigada *lista, int posicao) {
    if (posicao >= 0 && posicao < lista->tamanho) {
        int nodo_atual = lista->inicio;
        int nodo_anterior = -1;

        while (posicao > 0) {
            nodo_anterior = nodo_atual;
            nodo_atual = lista->elementos[nodo_atual].proximo;
            posicao--;
        }

        if (nodo_anterior == -1) {
            lista->inicio = lista->elementos[nodo_atual].proximo;
        } else {
            lista->elementos[nodo_anterior].proximo = lista->elementos[nodo_atual].proximo;
        }

        liberar_nodo(lista, nodo_atual);
        lista->tamanho--;
        return 1;
    }

    return 0;
}

int excluir_pelo_valor(ListaLigada *lista, int codigo) {
    int nodo_atual = lista->inicio;
    int nodo_anterior = -1;

    while (nodo_atual != -1) {
        if (lista->elementos[nodo_atual].codigo == codigo) {
            if (nodo_anterior == -1) {
                lista->inicio = lista->elementos[nodo_atual].proximo;
            } else {
                lista->elementos[nodo_anterior].proximo = lista->elementos[nodo_atual].proximo;
            }

            liberar_nodo(lista, nodo_atual);
            lista->tamanho--;
            return 1;
        }

        nodo_anterior = nodo_atual;
        nodo_atual = lista->elementos[nodo_atual].proximo;
    }

    return 0;
}

void imprimir(ListaLigada lista) {
    int nodo_atual = lista.inicio;

    while (nodo_atual != -1) {
        Aluno aluno = lista.elementos[nodo_atual];
        printf("Código: %d, Nome: %s, Idade: %d, Número de filhos: %d\n", aluno.codigo, aluno.nome, aluno.idade, aluno.num_filhos);
        nodo_atual = aluno.proximo;
    }
}

int main() {
    ListaLigada lista;
    criar_lista(&lista);

    // Inserir elementos na lista
    inserir(&lista, 1, "João", 25, 0);
    inserir(&lista, 3, "Maria", 27, 1);
    inserir(&lista, 2, "Pedro", 22, 2);

    // Inserir um elemento na lista de forma ordenada
    inserir_ordenado(&lista, 4, "Ana", 30, 3);

    // Imprimir os elementos da lista
    printf("Elementos da lista:\n");
    imprimir(lista);

    return 0;
}
