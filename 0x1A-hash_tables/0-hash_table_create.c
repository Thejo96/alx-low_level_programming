#include "hash_tables.h"
#include <stdio.h> // Include for error messages

/**
 * hash_table_create - creates a hash table
 * @size: size of the hash table
 *
 * Return: pointer to hash table, or NULL on failure
 */

hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *table;

    if (size == 0)
    {
        fprintf(stderr, "Error: Hash table size cannot be zero.\n");
        return (NULL);
    }

    table = calloc(1, sizeof(hash_table_t));
    if (table == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory for hash table.\n");
        return (NULL);
    }

    table->size = size;
    table->array = calloc(size, sizeof(hash_node_t *));
    if (table->array == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory for array in hash table.\n");
        free(table); // Clean up previously allocated memory
        return (NULL);
    }

    return (table);
}
