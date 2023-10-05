#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    printf("%p\n", (void *)ht);

    // Perform operations with the hash table here

    // Don't forget to free the hash table when you're done
    if (ht != NULL)
    {
        free(ht->array);
        free(ht);
    }

    return (EXIT_SUCCESS);
}
