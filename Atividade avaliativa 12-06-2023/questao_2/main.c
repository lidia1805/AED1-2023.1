#include <stdio.h>
#include "polinomial.h"

int main() {
    Node* P1 = NULL;
    Node* P2 = NULL;
    Node* S = NULL;

    int n, coeficiente, expoente;

    printf("Quantos termos possui o primeiro polinômio? ");
    scanf("%d", &n);

    printf("Digite os coeficientes e expoentes do primeiro polinômio:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeficiente, &expoente);
        P1 = inserir_polinomio(coeficiente, expoente, P1);
    }

    printf("Quantos termos possui o segundo polinômio? ");
    scanf("%d", &n);

    printf("Digite os coeficientes e expoentes do segundo polinômio:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeficiente, &expoente);
        P2 = inserir_polinomio(coeficiente, expoente, P2);
    }

    S = somar_polinomios(P1, P2);

    printf("A soma dos polinômios é: ");
    imprimir_polinomio(S);

    liberar_polinomio(P1);
    liberar_polinomio(P2);
    liberar_polinomio(S);

    return 0;
}
