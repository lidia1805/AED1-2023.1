#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
