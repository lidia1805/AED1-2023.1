#include "Aviao.h"

int main() {
    FILA* fila;
    inicializaFila(&fila);

    int opcao;
    do {
        printf("\n----- Controle de Decolagem de Aviões -----\n");
        printf("1. Listar o número de aviões aguardando na fila de decolagem\n");
        printf("2. Autorizar a decolagem do primeiro avião da fila\n");
        printf("3. Adicionar um avião à fila de espera\n");
        printf("4. Listar todos os aviões na fila de espera\n");
        printf("5. Listar as características do primeiro avião da fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int numAvioes = numeroDeAvioes(fila);
                printf("Número de aviões aguardando na fila de decolagem: %d\n", numAvioes);
                break;
            }
            case 2: {
                autorizarDecolagem(&fila);
                break;
            }
            case 3: {
                AVIAO* novoAviao;
                printf("Informe o nome do avião: ");
                scanf("%s", &novoAviao->nome);
                printf("Informe o identificador do avião: ");
                scanf("%d", &novoAviao->num_id);
                if (inserirAviao(&fila, novoAviao)) {
                    printf("Avião adicionado à fila de espera com sucesso.\n");
                } else {
                    printf("Erro ao adicionar avião à fila de espera.\n");
                }
                break;
            }
            case 4: {
                listarAvioes(fila);
                break;
            }
            case 5: {
                listarPrimeiroAviao(fila);
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
