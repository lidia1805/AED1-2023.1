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

void hash_table_insert(HashTable* table, Paciente* paciente) {
    int index = hash(paciente->codigo);
    table->data[index] = paciente;
}

Paciente* hash_table_search(HashTable* table, int codigo) {
    int index = hash(codigo);
    return table->data[index];
}

void hash_table_remove(HashTable* table, int codigo) {
    int index = hash(codigo);
    table->data[index] = NULL;
}

void hash_table_destroy(HashTable* table) {
    // Liberar a memória dos pacientes individualmente
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->data[i] != NULL) {
            free(table->data[i]);
            table->data[i] = NULL;
        }
    }
}
