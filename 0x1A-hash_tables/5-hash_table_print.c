/*
 * File_Name: 5-hash_table_print.c
 * Created: 8th June, 2023
 * Author: David James Taiye (Official0mega)
 * Size_Of_File: Undefined
 * Project_Title: 0x1A-hash_tables
 * Status: Submitted.!
 */

#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - A funtion that prints a hash table
 * @ht: The hash table to print
 *
 * Return: Always 0. (Success)
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned int index;
	hash_node_t *node;
	int check = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		for (node = ht->array[index]; node != NULL; node = node->next)
		{
			if (check != 0)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			check = 1;
		}
	}
	printf("}\n");
}
