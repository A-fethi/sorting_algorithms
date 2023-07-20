#include "sort.h"
/**
 * swap_1 - swaps nodes from left to right
 * @list: parameter
 * @head: parameter
 * @aux: parameter
 */

void swap_1(listint_t **list, listint_t *head, listint_t *aux)
{
	if (head->prev)
		head->prev->next = aux;
	else
		*list = aux;
	if (aux->next)
		aux->next->prev = head;
	head->next = aux->next;
	aux->prev = head->prev;
	aux->next = head;
	head->prev = aux;
	print_list(*list);
}

/**
 * swap_2 - swaps nodes from right to left
 * @list: parameter
 * @head: parameter
 * @aux: parameter
 */

void swap_2(listint_t **list, listint_t *head, listint_t *aux)
{
	aux = head->prev;
	aux->next->prev = aux->prev;
	if (aux->prev)
		aux->prev->next = aux->next;
	else
		*list = aux->next;
	aux->prev = aux->next;
	aux->next = aux->next->next;
	aux->prev->next = aux;
	if (aux->next)
		aux->next->prev = aux;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * @list: parameter
 **/

void cocktail_sort_list(listint_t **list)
{
	listint_t *j, *a;
	int b = 1;

	if (list)
	{
		j = *list;
		while (b != 0)
		{
			b = 0;
			while (j->next)
			{
				if (j->n > j->next->n)
				{
					a = j->next;
					swap_1(list, j, a);
					b = 1;
				}
				else
					j = j->next;
			}
			if (b == 0)
				break;
			b = 0;
			while (j->prev)
			{
				if (j->prev->n > j->n)
				{
					swap_2(list, j, a);
					b = 1;
				}
				else
					j = j->prev;
			}

		}
	}
}
