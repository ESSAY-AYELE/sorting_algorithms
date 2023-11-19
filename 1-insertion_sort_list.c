#include "sort.h"

/**
 * sawp_list - sawp two consiqative  doubly linked list
 * @first: first node
 * @second: the second node 
 */
void sawp_list(listint_t *first, listint_t *second)
{
	listint_t *tmp = first->prev;
	first->next = NULL;

	if (second->next != NULL)
	{
		first->next = second->next;
		second->next->prev = first;
	}
	second->prev = NULL;
	if (first->prev != NULL)
	{
		second->prev = first->prev;
		tmp->next = second;
	}

	first->prev = second;
	second->next = first;
}


/**
 * insertion_sort_list - sort a doubly linked list using insertion sort algo
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *back;
	listint_t *node = *list;

	if (list == NULL && *list != NULL)
		return;
	while (node != NULL && node->next != NULL)
	{
		if (node->n > node->next->n)
		{
			back = node;
			tmp = node->next;

			while (back != NULL && back->n > tmp->n)
			{
				sawp_list(back, tmp);
				back = tmp->prev;
				if (back == NULL)
					*list = tmp;
				print_list(*list);
			}

		}
		else
			while (node != NULL && node->next != NULL && node->n <= node->next->n)
				node = node->next;
	}
}
