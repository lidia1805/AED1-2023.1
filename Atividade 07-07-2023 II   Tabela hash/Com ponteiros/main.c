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
    
    // Teste com array de ponteiros
    printf("\nTeste com array de ponteiros:\n");
    HashTable table2;
    hash_table_init(&table2);

    Paciente paciente3 = {3, "Carlos", "13579246801", 40};
    Paciente paciente4 = {4, "Ana", "24681357901", 28};

    hash_table_insert(&table2, &paciente3);
    hash_table_insert(&table2, &paciente4);

    int codigo2 = 3;
    Paciente* paciente_array2 = hash_table_search(&table2, codigo2);
    print_paciente(paciente_array2);

    hash_table_remove(&table2, codigo2);

    Paciente* paciente_removido_array2 = hash_table_search(&table2, codigo2);
    print_paciente(paciente_removido_array2);

    hash_table_destroy(&table2);

    return 0;
}
