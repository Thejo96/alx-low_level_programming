/*
 * File_Name: 3-hash_table_set.c
 * Created: 8th June, 2023
 * Author: David James Taiye (Official0mega)
 * Size_Of_File: Undefined
 * Project_Title: 0x1A-hash_tables
 * Status: Submitted.!
 */

#include "hash_tables.h"

/**
 * hash_table_set - Function that Adds an element to the Hash Table
 * @ht: The hash table to add/update the key/value pair
 * @key: The key to add/update
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *temp;
	unsigned long int index;

	if (ht == NULL || key == NULL || strlen(key) == 0 || strcmp(key, "")
	== 0 || value == NULL || ht->size == 0 || ht->array == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (temp = ht->array[index]; temp != NULL; temp = temp->next)
	{
		if (strcmp(temp->key, key) == 0)
		{
			if (strcmp(temp->value, value) != 0)
			{
				free(temp->value);
				temp->value = strdup(value);
				if (temp->value == NULL)
					return (0);
			}
			return (1);
		}
	}
	new_node = create_ht_node(key, value);
	if (new_node == NULL)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}


/**
 * create_ht_node - Function that creates a Hash Table node
 * @key: The key to add/value
 * @value: The value associated witht the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
hash_node_t *create_ht_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t *));
	if (new_node == NULL)
		return (NULL);
	new_node->key = strdup(key);
	if (new_node->key == NULL)
		return (NULL);
	new_node->value = strdup(value);
	if (new_node->value == NULL)
		return (NULL);
	return (new_node);
}

