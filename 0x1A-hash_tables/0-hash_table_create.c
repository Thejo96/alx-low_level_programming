/*
 * File_Name: 0-hash_table_create.c
 * Created: 9th June, 2023
 * Author: David James Taiye (Official0mega)
 * Size_Of_File: Undefined
 * Project_Title: 0x1A-hash_tables
 * Status: Submitted.!
 */

#include "hash_tables.h"

/**
 * hash_table_create - A function that creates a Hash Table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table, or NULL if it fails
 */

hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *hash_table;
    unsigned long int hsh_tb;

    hash_table = malloc(sizeof(hash_table_t));
    if (hash_table == NULL)
        return (NULL);
    hash_table->size = size;
    hash_table->array = malloc(sizeof(hash_node_t *) * size); // Change this line
    if (hash_table->array == NULL)
    {
        free(hash_table);
        return (NULL);
    }
    for (hsh_tb = 0; hsh_tb < size; hsh_tb++)
        hash_table->array[hsh_tb] = NULL;
    return (hash_table);
}
