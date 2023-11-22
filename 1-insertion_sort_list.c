#include "sort.h"
#include <stddef.h>


/**
 * exchange_nodes - exchange 2 nodes
 * @h: ptr to the head of the doubly-linked list
 * @a: ptr to the first node to echange
 * @b: The second node to exchaneg
 */
void exchange_nodes(listint_t **h, listint_t **a, listint_t *b)
{
	(*a)->next = b->next;
	if (b->next != NULL)
		b->next->prev = *a;
	b->prev = (*a)->prev;
	b->next = *a;
	if ((*a)->prev != NULL)
		(*a)->prev->next = b;
	else
		*h = b;
	(*a)->prev = b;
	*a = b->prev;
}

/**
 * insertion_sort_list - arange a doubly linked list of ints
 *   using the insertion sort algorithm
 * @list: A ptr to the head of a doubly-linked list of ints
 *
 * guide: Prints list after operation
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iteration, *inserer, *temporaire;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iteration = (*list)->next; iteration != NULL; iteration = temporaire)
	{
		temporaire = iteration->next;
		inserer = iteration->prev;
		while (inserer != NULL && iteration->n < inserer->n)
		{
			exchange_nodes(list, &inserer, iteration);
			print_list((const listint_t *)*list);
		}
	}
}

