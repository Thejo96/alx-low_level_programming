#include "hash_tables.h"

/**
 * free_hash_table - Frees a hash table and its nodes.
 * @ht: The hash table to be freed.
 */
void free_hash_table(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *node, *temp;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node)
        {
            temp = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = temp;
        }
    }

    free(ht->array);
    free(ht);
}

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

    ht = malloc(sizeof(hash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(hash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    return (ht);
}
