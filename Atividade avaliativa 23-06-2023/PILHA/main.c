#include "hangar.h"
#include <stdio.h>

int main() {
    Pilha hangar;
    inicializaPilha(&hangar);

    int opcao;
    do {
        printf("\n----- Controle de Aviões no Hangar -----\n");
        printf("1. Listar o número de aviões aguardando no hangar\n");
        printf("2. Tirar um avião do hangar\n");
        printf("3. Adicionar um avião no hangar\n");
        printf("4. Listar todos os aviões que estão no hangar\n");
        printf("5. Listar as características do primeiro avião do hangar\n");
        printf("6. Tirar um avião do hangar pela posição\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int numAvioes = numeroDeAvioes(hangar);
                printf("Número de aviões aguardando no hangar: %d\n", numAvioes);
                break;
            }
            case 2: {
                if (desempilharAviao(&hangar)) {
                    printf("Avião removido do hangar com sucesso.\n");
                } else {
                    printf("Nenhum avião no hangar para remover.\n");
                }
                break;
            }
            case 3: {
                Aviao novoAviao;
                printf("Informe o nome do avião: ");
                scanf("%s", novoAviao.nome);
                printf("Informe o identificador do avião: ");
                scanf("%d", &novoAviao.identificador);
                if (empilharAviao(&hangar, novoAviao)) {
                    printf("Avião adicionado ao hangar com sucesso.\n");
                } else {
                    printf("Erro ao adicionar avião ao hangar.\n");
                }
                break;
            }
            case 4: {
                listarAvioes(hangar);
                break;
            }
            case 5: {
                listarPrimeiroAviao(hangar);
                break;
            }
            case 6: {
                int posicao;
                printf("Informe a posição do avião que deseja remover: ");
                scanf("%d", &posicao);
                if (desempilharAviaoPorPosicao(&hangar, posicao)) {
                    printf("Avião removido do hangar com sucesso.\n");
                } else {
                    printf("Posição inválida ou nenhum avião no hangar.\n");
                }
                break;
            }
            case 0: {
                printf("Encerrando o programa.\n");
                break;
            }
            default: {
                printf("Opção inválida. Tente novamente.\n");
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}
