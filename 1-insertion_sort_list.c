#include "sort.h"

/**
 * swap - to swap two nodes
 * @current: the first node
 * @to_move: 2nd node
 * @list: the list
 *
 * Return: Nothing
 */
void swap(listint_t *current, listint_t *to_move, listint_t **list)
{
	current->next = to_move->next;
	if (to_move->next != NULL)
		to_move->next->prev = current;
	to_move->next = current;
	to_move->prev = current->prev;
	if (current->prev == NULL)
		(*list) = to_move;
	else
		current->prev->next = to_move;
	current->prev = to_move;
}

/**
 * insertion_sort_list - inserton sort
 * @list: the list to be sorted
 *
 * Return: Nothing
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *mov = NULL, *to_move = NULL;
	listint_t *current = NULL;
	int c = 0;

	if (list == NULL || (*list) == NULL)
		return;
	mov = (*list);
	while (mov != NULL)
	{
		c = 0;
		to_move = mov;
		current = mov->prev;
		while (current != NULL && current->n > to_move->n)
		{
			c += 1;
			tmp = current;
			swap(tmp, to_move, list);
			current = current->prev->prev;
			if (c == 1)
				mov = mov->next;
			print_list((*list));
		}
		mov = mov->next;
	}
}
