#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: If an error occurs - NULL.
 *         else - a pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *ht;
    unsigned long int i;

    if (size == 0)
        return (NULL);

    ht = malloc(sizeof(hash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(hash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht); // Free allocated memory in case of an error
        return (NULL);
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    return (ht);
}
