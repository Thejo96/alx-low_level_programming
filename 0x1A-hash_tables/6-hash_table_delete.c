/*
 * File_Name: 6-hash_table_delete.c
 * Created: 8th June, 2023
 * Author: David James Taiye (Official0mega)
 * Size_Of_File: Undefined
 * Project_Title: 0x1A-hash_tables
 * Status: Submitted.!
 */

#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_delete - A funtion that Deletes a hash table
 * @ht: The hash table to delete
 *
 * Return: Always 0. (Success)
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp;
	unsigned long int del;
	hash_node_t *node;

	if (ht == NULL || ht->size == 0 || ht->array == NULL)
		return;

	for (del = 0; del < ht->size; del++)
	{
		for (node = ht->array[del]; node != NULL; node = temp)
		{
			temp = node->next;
			free(node->key);
			free(node->value);
			free(node);
		}
	}
	free(ht->array);
	free(ht);
}
