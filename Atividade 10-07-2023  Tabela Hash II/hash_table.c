#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

void hash_table_init(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->tabela[i] = NULL;
    }
}

int hash_linear(int chave, int i) {
    return (chave + i) % TABLE_SIZE;
}

int hash_quadratic(int chave, int i) {
    return (chave + i * i) % TABLE_SIZE;
}

int hash_double(int chave, int i) {
    int h1 = chave % TABLE_SIZE;
    int h2 = 7 - (chave % 7);
    return (h1 + i * h2) % TABLE_SIZE;
}

void hash_table_insert_linear(HashTable* table, int chave) {
    int i = 0;
    while (i < TABLE_SIZE) {
        int index = hash_linear(chave, i);
        if (table->tabela[index] == NULL) {
            Registro* new_registro = (Registro*)malloc(sizeof(Registro));
            new_registro->chave = chave;
            table->tabela[index] = new_registro;
            return;
        }
        i++;
    }
    printf("Não foi possível inserir a chave %d (sobrecarga).\n", chave);
}

void hash_table_insert_quadratic(HashTable* table, int chave) {
    int i = 0;
    while (i < TABLE_SIZE) {
        int index = hash_quadratic(chave, i);
        if (table->tabela[index] == NULL) {
            Registro* new_registro = (Registro*)malloc(sizeof(Registro));
            new_registro->chave = chave;
            table->tabela[index] = new_registro;
            return;
        }
        i++;
    }
    printf("Não foi possível inserir a chave %d (sobrecarga).\n", chave);
}

void hash_table_insert_double(HashTable* table, int chave) {
    int i = 0;
    while (i < TABLE_SIZE) {
        int index = hash_double(chave, i);
        if (table->tabela[index] == NULL) {
            Registro* new_registro = (Registro*)malloc(sizeof(Registro));
            new_registro->chave = chave;
            table->tabela[index] = new_registro;
            return;
        }
        i++;
    }
    printf("Não foi possível inserir a chave %d (sobrecarga).\n", chave);
}

void hash_table_print(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->tabela[i] != NULL) {
            printf("[%d]: %d\n", i, table->tabela[i]->chave);
        } else {
            printf("[%d]: NULL\n", i);
        }
    }
}
