#ifndef AVL_TREE_H
#define AVL_TREE_H

// Definição do tipo do nó da árvore AVL
typedef struct Node {
    int key;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó na árvore AVL
Node* createNode(int key);

// Função para inserir um valor na árvore AVL
Node* insert(Node* root, int key);

// Função para realizar uma rotação simples à esquerda
Node* leftRotate(Node* x);

// Função para realizar uma rotação simples à direita
Node* rightRotate(Node* y);

// Função para obter a altura de um nó (ou nulo, caso seja uma árvore vazia)
int getHeight(Node* node);

// Função para obter o fator de balanceamento de um nó (ou nulo, caso seja uma árvore vazia)
int getBalanceFactor(Node* node);

// Função para encontrar o nó com a menor chave na árvore (necessária para remoção)
Node* findMinNode(Node* node);

// Função para remover um valor da árvore AVL
Node* deleteNode(Node* root, int key);

// Função para imprimir a árvore AVL em ordem
void inorderTraversal(Node* root);

// Função para liberar a memória ocupada pela árvore AVL
void freeTree(Node* root);

#endif // AVL_TREE_H
