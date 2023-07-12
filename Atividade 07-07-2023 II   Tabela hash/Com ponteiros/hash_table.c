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

    if (table->data[index] == NULL || table->data[index]->disponivel) {
        HashEntry* new_entry = (HashEntry*)malloc(sizeof(HashEntry));
        new_entry->disponivel = 0;
        new_entry->paciente = paciente;
        table->data[index] = new_entry;
    } else {
        table->data[index]->paciente = paciente;
        table->data[index]->disponivel = 0;
    }
}

Paciente* hash_table_search(HashTable* table, int codigo) {
    int index = hash(codigo);

    if (table->data[index] != NULL && !table->data[index]->disponivel &&
        table->data[index]->paciente->codigo == codigo) {
        return table->data[index]->paciente;
    }
    return NULL;
}

void hash_table_remove(HashTable* table, int codigo) {
    int index = hash(codigo);

    if (table->data[index] != NULL && !table->data[index]->disponivel &&
        table->data[index]->paciente->codigo == codigo) {
        table->data[index]->disponivel = 1;
    }
}

void hash_table_destroy(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->data[i] != NULL) {
            free(table->data[i]);
            table->data[i] = NULL;
        }
    }
}
