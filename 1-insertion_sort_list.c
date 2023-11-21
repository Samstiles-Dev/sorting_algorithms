#include "sort.h"

/**
 * insertion_sort_list - Execute insertion sort on a linked list.
 * @list: first node of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *_current, *swap, *_prv;

	if (!list || !*list)
		return;

	_current = *list;
	while ((_current = _current->next))
	{
		swap = _current;
		while (swap->prev && swap->n < swap->prev->n)
		{
			_prv = swap->prev;
			if (swap->next)
				swap->next->prev = _prv;
			if (_prv->prev)
				_prv->prev->next = swap;
			else
				*list = swap;
			_prv->next = swap->next;
			swap->prev = _prv->prev;
			swap->next = _prv;
			_prv->prev = swap;

			print_list(*list);
		}
	}
}
