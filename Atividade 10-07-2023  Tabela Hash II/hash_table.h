#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 11

typedef struct {
    int chave;
} Registro;

typedef struct {
    Registro* tabela[TABLE_SIZE];
} HashTable;

void hash_table_init(HashTable* table);
void hash_table_insert_linear(HashTable* table, int chave);
void hash_table_insert_quadratic(HashTable* table, int chave);
void hash_table_insert_double(HashTable* table, int chave);
void hash_table_print(HashTable* table);

#endif
