#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <#include <stdio.h>
#include "arvore_binaria.h"
#include "pilha.h"

int main() {
    ArvoreBinaria* arvore = criarArvoreBinaria();
    Pilha* pilha = criarPilha(100); // Ajuste a capacidade conforme necessário

    // Inserindo elementos na árvore
    inserirElemento(arvore, '*');
    inserirElemento(arvore, 'a');
    inserirElemento(arvore, '/');
    inserirElemento(arvore, '-');
    inserirElemento(arvore, 'b');
    inserirElemento(arvore, 'c');
    inserirElemento(arvore, 'd');

    // Imprimindo expressões em diferentes notações
    printf("Expressão em notação infixa: ");
    imprimirInfixa(arvore->raiz);
    printf("\n");

    printf("Expressão em notação posfixa: ");
    imprimirPosfixa(arvore->raiz);
    printf("\n");

    printf("Expressão em notação prefixa: ");
    imprimirPrefixa(arvore->raiz);
    printf("\n");

    // Avaliando expressão aritmética
    avaliarExpressao(arvore->raiz, pilha);
    int resultado = topo(pilha) - '0'; // Convertendo char para int
    printf("Resultado da expressão: %d\n", resultado);

    // Liberando memória
    destruirArvoreBinaria(arvore);
    destruirPilha(pilha);

    return 0;
}
string.h>

int main() {
    // Testando a inserção de elementos na árvore binária
    Node* root = NULL;
    insert(&root, '2');
    insert(&root, '4');
    insert(&root, '1');
    insert(&root, '0');
    insert(&root, '3');
    insert(&root, '2');
    insert(&root, '9');
    insert(&root, '3');
    insert(&root, '5');

    // Imprimindo a árvore em diferentes ordens
    printf("Infixa: ");
    inorderTraversal(root);
    printf("\n");

    printf("Posfixa: ");
    postorderTraversal(root);
    printf("\n");

    printf("Prefixa: ");
    preorderTraversal(root);
    printf("\n");

    // Convertendo uma expressão infixa para a árvore binária
    char expression[] = "a*((b-c)/d)";
    Node* rootFromInfix = infixToBinaryTree(expression);

    // Calculando o valor da expressão aritmética
    int result = evaluateExpression(rootFromInfix);
    printf("Resultado: %d\n", result);

    // Liberando a memória alocada para as árvores
    freeTree(root);
    freeTree(rootFromInfix);

    return 0;
}
