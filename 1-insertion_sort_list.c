#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - the Insertion sort
 * @list: Double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *curr = NULL;
	listint_t *key = NULL;
	listint_t *prev = NULL;

	curr = (*list)->next;

	while (curr != NULL)
	{
		key = curr;
		prev = curr->prev;

		while (prev != NULL && prev->n > key->n)
		{
			if (key->next != NULL)
				key->next->prev = prev;
			prev->next = key->next;
			key->prev = prev->prev;
			if (prev->prev != NULL)
				prev->prev->next = key;
			key->next = prev;
			prev->prev = key;

			if (key->prev == NULL)
				*list = key;

			print_list(*list);
			prev = key->prev;
		}

		curr = curr->next;
	}
}
