#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Prints a list of integers
 *
 * @list: The array
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *tmp;

	cur = *list;
	if (list)
	{
		for (; cur != NULL;)
		{
			while (cur->next && (cur->n > cur->next->n))
			{
				tmp = cur->next;
				cur->next = tmp->next;
				tmp->prev = cur->prev;

				if (cur->prev)
					cur->prev->next = tmp;

				if (tmp->next)
					tmp->next->prev = cur;

				cur->prev = tmp;
				tmp->next = cur;

				if (tmp->prev)
					cur = tmp->prev;
				else
					*list = tmp;

				print_list(*list);
			}
			cur = cur->next;
		}
	}
}
