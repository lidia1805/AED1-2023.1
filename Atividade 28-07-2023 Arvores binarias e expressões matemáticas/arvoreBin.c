#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Estrutura de um nó da árvore binária
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó da árvore
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore binária
void insert(Node** root, char data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if ((*root)->left == NULL) {
        insert(&((*root)->left), data);
    } else if ((*root)->right == NULL) {
        insert(&((*root)->right), data);
    } else {
        // Se ambos os filhos estiverem ocupados, insere no filho esquerdo recursivamente
        insert(&((*root)->left), data);
    }
}

// Função para percorrer a árvore em ordem (infixa)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

// Função para percorrer a árvore em pós-ordem (posfixa)
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%c ", root->data);
    }
}

// Função para percorrer a árvore em pré-ordem (prefixa)
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Função para converter uma expressão infixa em uma árvore binária
Node* infixToBinaryTree(char* expression) {
    // Implementar a conversão usando uma pilha (opcional)
}

// Função para calcular o valor da expressão aritmética representada por uma árvore
int evaluateExpression(Node* root) {
    // Implementar o cálculo usando uma pilha ou fila (opcional)
}

// Função para liberar a memória alocada para a árvore
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

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
