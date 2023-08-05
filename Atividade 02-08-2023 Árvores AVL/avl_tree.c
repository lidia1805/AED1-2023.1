#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

// Função para criar um novo nó na árvore AVL
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para obter a altura de um nó (ou nulo, caso seja uma árvore vazia)
int getHeight(Node* node) {
    return (node == NULL) ? 0 : node->height;
}

// Função para calcular o fator de balanceamento de um nó (ou nulo, caso seja uma árvore vazia)
int getBalanceFactor(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Função para realizar uma rotação simples à direita
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realizar rotação
    x->right = y;
    y->left = T2;

    // Atualizar alturas
    y->height = 1 + fmax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + fmax(getHeight(x->left), getHeight(x->right));

    return x;
}

// Função para realizar uma rotação simples à esquerda
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realizar rotação
    y->left = x;
    x->right = T2;

    // Atualizar alturas
    x->height = 1 + fmax(getHeight(x->left), getHeight(x->right));
    y->height = 1 + fmax(getHeight(y->left), getHeight(y->right));

    return y;
}

// Função para inserir um valor na árvore AVL
Node* insert(Node* root, int key) {
    // Passo 1: Inserir na árvore BST
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // Não permitir chaves duplicadas

    // Passo 2: Atualizar a altura do nó pai
    root->height = 1 + fmax(getHeight(root->left), getHeight(root->right));

    // Passo 3: Obter o fator de balanceamento deste nó
    int balance = getBalanceFactor(root);

    // Passo 4: Verificar os casos de desbalanceamento e realizar as rotações necessárias

    // Caso LL: rotação simples à direita
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Caso RR: rotação simples à esquerda
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Caso LR: rotação dupla à direita-esquerda
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Caso RL: rotação dupla à esquerda-direita
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Função para encontrar o nó com a menor chave na árvore (necessária para remoção)
Node* findMinNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Função para remover um valor da árvore AVL
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            Node* temp = findMinNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    // Atualizar a altura do nó pai
    root->height = 1 + fmax(getHeight(root->left), getHeight(root->right));

    // Obter o fator de balanceamento deste nó
    int balance = getBalanceFactor(root);

    // Verificar os casos de desbalanceamento e realizar as rotações necessárias

    // Caso LL: rotação simples à direita
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Caso RR: rotação simples à esquerda
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Caso LR: rotação dupla à direita-esquerda
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Caso RL: rotação dupla à esquerda-direita
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Função para imprimir a árvore AVL em ordem
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Função para liberar a memória ocupada pela árvore AVL
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
