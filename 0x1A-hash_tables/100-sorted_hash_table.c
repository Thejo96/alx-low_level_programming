/*
 * File_Name: 100-sorted_hash_table.c
 * Created: 8th June, 2023
 * Author: David James Taiye (Official0mega)
 * Size_Of_File: Undefined
 * Project_Title: 0x1A-hash_tables
 * Status: Submitted.!
 */

#include "hash_tables.h"

/**
 * shash_table_create - A function that creates a new sorted hashtable
 * @size: The maximum number of top-level items in the hash table.
 *
 * Return: A pointer to the newly created sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int index;

	if (size <= 0)
		return (NULL);
	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	ht->array = malloc(sizeof(shash_node_t) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (index = 0; index < size; index++)
	{
		ht->array[index] = NULL;
	}
	return (ht);
}


/**
 * shash_table_set - A function that Adds an element to...
 * ...a given sorted hash table...
 * @ht: The sorted hash table that will contain the element.
 * @key: The key of the element to add.
 * @value: The value of the element to add.
 *
 * Return: 1 if the addition was successful, otherwise 0.
*/

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *check, *new_node;
	unsigned long int index;

	if (ht == NULL || strcmp(key, "") == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	check = ht->array[index];
	while (check != NULL)
	{
		if (strcmp(check->key, key) == 0)
		{
			free(check->value);
			check->value = strdup(value);
			if (check->value == NULL)
				return (0);
			return (1);
		}
		check = check->next;
	}
	new_node = create_sht_node(key, value);
	if (new_node == NULL)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	new_node->snext = NULL;
	new_node->sprev = NULL;
	return (add_sht_node(ht, new_node));
}

/**
 * create_sht_node - makes new sht node
 * @key: key
 * @value: value
 *
 * Return: pointer to new node or NULL if failure
 */

shash_node_t *create_sht_node(const char *key, const char *value)
{
	shash_node_t *new_node;

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (NULL);
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	new_node->next = new_node->snext = new_node->sprev = NULL;
	return (new_node);
}

/**
 * add_sht_node - adds node to sorted hash table
 * @ht: hash table
 * @node: node to add
 *
 * Return: 1 if successful, 0 otherwise
 */

int add_sht_node(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *check;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return (1);
	}
	check = ht->shead;
	while (check != NULL)
	{
		if (strcmp(node->key, check->key) < 0)
		{
			node->snext = check;
			node->sprev = check->sprev;
			check->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				ht->shead = node;
			return (1);
		}
		check = check->snext;
	}

	node->sprev = ht->stail;
	ht->stail->snext = node;
	ht->stail = node;
	return (1);
}


/**
 * shash_table_get - Retrieves the value of element with a given key in a...
 * ....sorted hash table.i..
 * @ht: The sorted hash table to search.
 * @key: The element's key.
 *
 * Return: The value of the element associated with the given key, otheriwse 0
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *check;
	unsigned long int index;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	check = ht->array[index];
	while (check != NULL)
	{
		if (strcmp(check->key, key) == 0)
			return (check->value);
		check = check->next;
	}
	return (NULL);
}

/**
 * shash_table_print - A function that Prints the element of a sorted hashtable
 * @ht: A pointer to the hash table
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *check;
	int first_check = 0;

	if (ht == NULL)
		return;
	printf("{");
	for (check = ht->shead; check != NULL; check = check->snext)
	{
		if (first_check == 0)
			first_check = 1;
		else
			printf(", ");
		printf("'%s': '%s'", check->key, check->value);
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the elements of a sorted hash table in revers
 * @ht: A pointer to the hash table
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *reverse;
	int first_check = 0;

	if (ht == NULL)
		return;
	printf("{");
	for (reverse = ht->stail; reverse != NULL; reverse = reverse->sprev)
	{
		if (first_check == 0)
			first_check = 1;
		else
			printf(", ");
		printf("'%s': '%s'", reverse->key, reverse->value);
	}
	printf("}\n");

}

/**
 * shash_table_delete - A function that Deletes hash table and it's elements.
 * @ht: A pointer to the hash table
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *check, *temp;
	unsigned int index;

	if (ht == NULL)
		return;
	for (index = 0; index < ht->size; index++)
	{
		check = ht->array[index];
		while (check != NULL)
		{
			temp = check->next;
			free(check->value);
			free(check->key);
			free(check);
			check = temp;
		}
	}
	free(ht->array);
	free(ht);
}

