#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - the Insertion sort
 * @list: Double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		while (current->prev && current->prev->n > current->n)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = current->next;
	}
}
