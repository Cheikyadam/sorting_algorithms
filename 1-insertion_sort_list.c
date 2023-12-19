#include "sort.h"

/**
 * quickswap - to swap two nodes
 * @tmp: the first node
 * @to_move: 2nd node
 *
 * Return: Nothing
 */

void quickswap(listint_t *tmp, listint_t *to_move)
{
	tmp->next = to_move->next;
	to_move->next->prev = tmp;
}

/**
 * slowswap - to swap two nodes
 * @tmp: the first node
 * @to_move: 2nd node
 *
 * Return: Nothing
 */

void slowswap(listint_t *tmp, listint_t *to_move)
{
	to_move->next = tmp->next;
	to_move->prev = tmp;
	tmp->next->prev = to_move;
	tmp->next = to_move;
}

/**
 * initswap - to swap two nodes
 * @tmp: the first node
 * @to_move: 2nd node
 * @list: the list
 *
 * Return: Nothing
 */
void initswap(listint_t *tmp, listint_t *to_move, listint_t **list)
{
	to_move->next = tmp;
	tmp->prev = to_move;
	to_move->prev = NULL;
	to_move->next = tmp;
	(*list) = to_move;
}

/**
 * insertion_sort_list - inserton sort
 * @list: the list to be sorted
 *
 * Return: Nothing
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *mov = (*list), *to_move = NULL;
	int c = 0;

	if (list == NULL || (*list) == NULL)
		return;
	while (mov != NULL)
	{
		tmp = mov;
		c = 0;
		if (tmp->prev != NULL && tmp->prev->n > tmp->n)
		{
			to_move = tmp;
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp =  tmp->prev;
			while (tmp->prev != NULL && to_move->n < tmp->n)
			{
				c += 1;
				if (c > 1)
					quickswap(tmp, to_move);
				tmp = tmp->prev;
				slowswap(tmp, to_move);
				print_list((*list));
			}
			if (tmp->prev == NULL)
			{
				if (to_move->n >= tmp->n)
					slowswap(tmp, to_move);
				else
				{
					if (c >= 1)
						quickswap(tmp, to_move);
					initswap(tmp, to_move, (list));
				}
				print_list((*list));
			}
		}
		mov = mov->next;
	}
}
