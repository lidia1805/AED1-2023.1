#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    int codigo;
    char nome[50];
    int idade;
    int num_filhos;
    struct Aluno* proximo;
} Aluno;

typedef struct {
    Aluno* inicio;
    int tamanho;
} ListaLigada;

void criar_lista(ListaLigada* lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int esta_vazia(ListaLigada lista) {
    return lista.inicio == NULL;
}

int tamanho(ListaLigada lista) {
    return lista.tamanho;
}

Aluno* criar_aluno(int codigo, const char* nome, int idade, int num_filhos) {
    Aluno* novo_aluno = (Aluno*)malloc(sizeof(Aluno));
    novo_aluno->codigo = codigo;
    strcpy(novo_aluno->nome, nome);
    novo_aluno->idade = idade;
    novo_aluno->num_filhos = num_filhos;
    novo_aluno->proximo = NULL;
    return novo_aluno;
}

void inserir(ListaLigada* lista, int codigo, const char* nome, int idade, int num_filhos) {
    Aluno* novo_aluno = criar_aluno(codigo, nome, idade, num_filhos);

    if (esta_vazia(*lista)) {
        lista->inicio = novo_aluno;
    } else {
        Aluno* aluno_atual = lista->inicio;
        while (aluno_atual->proximo != NULL) {
            aluno_atual = aluno_atual->proximo;
        }
        aluno_atual->proximo = novo_aluno;
    }

    lista->tamanho++;
}

void inserir_ordenado(ListaLigada* lista, int codigo, const char* nome, int idade, int num_filhos) {
    Aluno* novo_aluno = criar_aluno(codigo, nome, idade, num_filhos);

    if (esta_vazia(*lista) || codigo < lista->inicio->codigo) {
        novo_aluno->proximo = lista->inicio;
        lista->inicio = novo_aluno;
    } else {
        Aluno* aluno_atual = lista->inicio;
        Aluno* aluno_anterior = NULL;

        while (aluno_atual != NULL && codigo > aluno_atual->codigo) {
            aluno_anterior = aluno_atual;
            aluno_atual = aluno_atual->proximo;
        }

        novo_aluno->proximo = aluno_atual;
        aluno_anterior->proximo = novo_aluno;
    }

    lista->tamanho++;
}

int buscar_sequencial(ListaLigada lista, int codigo) {
    Aluno* aluno_atual = lista.inicio;
    int posicao = 0;

    while (aluno_atual != NULL) {
        if (aluno_atual->codigo == codigo) {
            return posicao;
        }
        aluno_atual = aluno_atual->proximo;
        posicao++;
    }

    return -1;
}

int busca_binaria(ListaLigada lista, int codigo) {
    printf("A busca binária não é aplicável a uma lista ligada dinâmica.\n");
    return -1;
}

int excluir_pela_posicao(ListaLigada* lista, int posicao) {
    if (posicao >= 0 && posicao < lista->tamanho) {
        Aluno* aluno_atual = lista->inicio;
        Aluno* aluno_anterior = NULL;
        int i = 0;

        while (i < posicao) {
            aluno_anterior = aluno_atual;
            aluno_atual = aluno_atual->proximo;
            i++;
        }

        if (aluno_anterior == NULL) {
            lista->inicio = aluno_atual->proximo;
        } else {
            aluno_anterior->proximo = aluno_atual->proximo;
        }

        free(aluno_atual);
        lista->tamanho--;
        return 1;
    }

    return 0;
}

int excluir_pelo_codigo(ListaLigada* lista, int codigo) {
    Aluno* aluno_atual = lista->inicio;
    Aluno* aluno_anterior = NULL;

    while (aluno_atual != NULL) {
        if (aluno_atual->codigo == codigo) {
            if (aluno_anterior == NULL) {
                lista->inicio = aluno_atual->proximo;
            } else {
                aluno_anterior->proximo = aluno_atual->proximo;
            }

            free(aluno_atual);
            lista->tamanho--;
            return 1;
        }

        aluno_anterior = aluno_atual;
        aluno_atual = aluno_atual->proximo;
    }

    return 0;
}

void imprimir(ListaLigada lista) {
    Aluno* aluno_atual = lista.inicio;

    while (aluno_atual != NULL) {
        printf("Código: %d, Nome: %s, Idade: %d, Número de Filhos: %d\n", aluno_atual->codigo, aluno_atual->nome, aluno_atual->idade, aluno_atual->num_filhos);
        aluno_atual = aluno_atual->proximo;
    }
}

void liberar_lista(ListaLigada* lista) {
    Aluno* aluno_atual = lista->inicio;

    while (aluno_atual != NULL) {
        Aluno* aluno_temp = aluno_atual;
        aluno_atual = aluno_atual->proximo;
        free(aluno_temp);
    }

    lista->inicio = NULL;
    lista->tamanho = 0;
}

int main() {
    ListaLigada lista;
    criar_lista(&lista);

    // Inserir elementos na lista sem importar a ordem
    inserir(&lista, 1, "Alice", 20, 0);
    inserir(&lista, 3, "Bob", 22, 1);
    inserir(&lista, 2, "Charlie", 19, 2);

    // Inserir um elemento na lista de forma ordenada
    inserir_ordenado(&lista, 4, "David", 21, 1);

    // Imprimir os elementos da lista
    printf("Elementos da lista:\n");
    imprimir(lista);

    // Retornar a quantidade de elementos na lista
    printf("Quantidade de elementos na lista: %d\n", tamanho(lista));

    // Buscar um elemento sequencialmente na lista
    int posicao = buscar_sequencial(lista, 2);
    if (posicao != -1) {
        printf("Elemento encontrado na posição %d\n", posicao);
    } else {
        printf("Elemento não encontrado na lista\n");
    }

    // Buscar um elemento usando busca binária
    int posicao_binaria = busca_binaria(lista, 3);
    if (posicao_binaria != -1) {
        printf("Elemento encontrado na posição %d\n", posicao_binaria);
    } else {
        printf("Elemento não encontrado na lista\n");
    }

    // Excluir um elemento da lista pelo código
    excluir_pelo_codigo(&lista, 2);

    // Imprimir os elementos da lista após a exclusão
    printf("Elementos da lista após a exclusão:\n");
    imprimir(lista);

    liberar_lista(&lista);

    return 0;
}
