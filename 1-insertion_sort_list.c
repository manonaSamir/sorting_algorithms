#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Prints a list of integers
 *
 * @list: The array
 */

void insertion_sort_list(listint_t **list)
{
	int i;
	listint_t *cur, *ptr, *tmp;

	cur = *list;
	if (cur->next == NULL)
		return;
	cur = cur->next;
	for (i = 0; cur != NULL;)
	{
		ptr = cur;
		tmp = cur->prev;
		cur = cur->next;
		for (; tmp != NULL && tmp->n > ptr->n; i++)
			tmp = tmp->prev;

		if (i)
		{
			ptr->prev->next = ptr->next;
			if (ptr->next != NULL)
				ptr->next->prev = ptr->prev;

			if (tmp == NULL)
			{
				tmp = *list;
				ptr->prev = NULL;
				ptr->next = tmp;
				ptr->next->prev = ptr;
				*list = ptr;
			}
			else
			{
				tmp = tmp->next;
				tmp->prev->next = ptr;
				ptr->prev = tmp->prev;
				tmp->prev = ptr;
				ptr->next = tmp;
			}
		}
		print_list(*list);
	}
}
