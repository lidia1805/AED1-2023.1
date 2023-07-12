#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

void hash_table_init(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->data[i] = NULL;
    }
}

int hash(int codigo) {
    return codigo % TABLE_SIZE;
}

void hash_table_insert(HashTable* table, Paciente paciente) {
    int index = hash(paciente.codigo);

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->paciente = paciente;
    new_node->next = NULL;

    if (table->data[index] == NULL) {
        table->data[index] = new_node;
    } else {
        Node* current = table->data[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

Paciente* hash_table_search(HashTable* table, int codigo) {
    int index = hash(codigo);

    Node* current = table->data[index];
    while (current != NULL) {
        if (current->paciente.codigo == codigo) {
            return &(current->paciente);
        }
        current = current->next;
    }
    return NULL;
}

void hash_table_remove(HashTable* table, int codigo) {
    int index = hash(codigo);

    Node* current = table->data[index];
    Node* previous = NULL;

    while (current != NULL) {
        if (current->paciente.codigo == codigo) {
            if (previous == NULL) {
                table->data[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void hash_table_destroy(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table->data[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
        table->data[i] = NULL;
    }
}
