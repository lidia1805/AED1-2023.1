#include <stdio.h>
#include "hash_table.h"

int main() {
    HashTable table_linear, table_quadratic, table_double;
    hash_table_init(&table_linear);
    hash_table_init(&table_quadratic);
    hash_table_init(&table_double);

    int chaves[] = {365, 112, 180, 213, 13, 27};
    int num_chaves = sizeof(chaves) / sizeof(chaves[0]);

    printf("Inserção com sondagem linear:\n");
    for (int i = 0; i < num_chaves; i++) {
        hash_table_insert_linear(&table_linear, chaves[i]);
    }
    hash_table_print(&table_linear);

    printf("\nInserção com sondagem quadrática:\n");
    for (int i = 0; i < num_chaves; i++) {
        hash_table_insert_quadratic(&table_quadratic, chaves[i]);
    }
    hash_table_print(&table_quadratic);

    printf("\nInserção com hash duplo:\n");
    for (int i = 0; i < num_chaves; i++) {
        hash_table_insert_double(&table_double, chaves[i]);
    }
    hash_table_print(&table_double);

    return 0;
}
