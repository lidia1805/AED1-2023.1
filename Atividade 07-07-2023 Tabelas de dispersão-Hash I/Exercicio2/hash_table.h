#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "paciente.h"

#define TABLE_SIZE 100

typedef struct Node {
    Paciente paciente;
    struct Node* next;
} Node;

typedef struct {
    Node* data[TABLE_SIZE];
} HashTable;

void hash_table_init(HashTable* table);
void hash_table_insert(HashTable* table, Paciente paciente);
Paciente* hash_table_search(HashTable* table, int codigo);
void hash_table_remove(HashTable* table, int codigo);
void hash_table_destroy(HashTable* table);

#endif
