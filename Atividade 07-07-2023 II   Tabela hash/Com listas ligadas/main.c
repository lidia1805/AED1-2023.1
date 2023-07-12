#include <stdio.h>
#include "hash_table.h"

void print_paciente(Paciente* paciente) {
    if (paciente != NULL) {
        printf("Paciente encontrado: Código=%d, Nome=%s, CPF=%s, Idade=%d\n",
               paciente->codigo, paciente->nome, paciente->cpf, paciente->idade);
    } else {
        printf("Paciente não encontrado.\n");
    }
}

int main() {
    // Teste com lista ligada
    printf("Teste com lista ligada:\n");
    HashTable table1;
    hash_table_init(&table1);

    Paciente paciente1 = {1, "João", "12345678901", 25};
    Paciente paciente2 = {2, "Maria", "98765432109", 32};

    hash_table_insert(&table1, paciente1);
    hash_table_insert(&table1, paciente2);

    int codigo1 = 1;
    Paciente* paciente_lista1 = hash_table_search(&table1, codigo1);
    print_paciente(paciente_lista1);

    hash_table_remove(&table1, codigo1);

    Paciente* paciente_removido_lista1 = hash_table_search(&table1, codigo1);
    print_paciente(paciente_removido_lista1);

    hash_table_destroy(&table1);

    return 0;
}
