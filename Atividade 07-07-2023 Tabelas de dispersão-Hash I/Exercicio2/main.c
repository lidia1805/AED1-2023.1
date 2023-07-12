#include <stdio.h>
#include "hash_table.h"

int main() {
    HashTable table;
    hash_table_init(&table);

    Paciente paciente1 = {1, "João", "12345678901", 25};
    Paciente paciente2 = {2, "Maria", "98765432109", 32};

    hash_table_insert(&table, paciente1);
    hash_table_insert(&table, paciente2);

    int codigo = 1;
    Paciente* paciente = hash_table_search(&table, codigo);
    if (paciente != NULL) {
        printf("Paciente encontrado: Código=%d, Nome=%s, CPF=%s, Idade=%d\n",
               paciente->codigo, paciente->nome, paciente->cpf, paciente->idade);
    } else {
        printf("Paciente não encontrado.\n");
    }

    hash_table_remove(&table, codigo);

    hash_table_destroy(&table);

    return 0;
}
