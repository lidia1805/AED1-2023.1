#include <stdio.h>
#include "avl_tree.h"

int main() {
    Node* root = NULL;
    int values[] = {1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserindo os valores na árvore AVL:\n");
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
        printf("%d ", values[i]);
    }

    printf("\n\nÁrvore AVL em ordem:\n");
    inorderTraversal(root);
    printf("\n");

    // Testando a remoção de alguns valores
    int value_to_remove = 5;
    root = deleteNode(root, value_to_remove);
    printf("\nRemovendo o valor %d:\n", value_to_remove);
    inorderTraversal(root);
    printf("\n");

    // Liberar a memória da árvore AVL
    freeTree(root);
    root = NULL;

    return 0;
}
