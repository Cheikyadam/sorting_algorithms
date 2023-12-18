#include "sort.h"

/**
 * swap - to swap two nodes
 * @head: the list
 * @node1: the first node
 * @node2: 2nd node
 *
 * Return: Nothing
 */

void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *tempPrev = NULL, *tempNext = NULL;

	(void)head;
	if (node1 == NULL || node2 == NULL || node1 == node2)
		return;
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	else
	{
		(*head) = node2;
	}
	if (node2->prev != NULL)
	{
		node2->prev->next = node1;
	}
	else
	{
		(*head) = node1;
	}
	if (node1->next != NULL)
		node1->next->prev = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	tempPrev = node1->prev;
	tempNext = node1->next;

	node1->prev = node2->prev;
	node1->next = node2->next;

	node2->prev = tempPrev;
	node2->next = tempNext;
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
	int print = 0;

	if (list == NULL)
		return;
	if ((*list) == NULL)
		return;
	while (mov != NULL)
	{
		print = 0;
		tmp = mov;
		if (tmp->prev != NULL && tmp->prev->n > tmp->n)
		{
			print = 1;
			to_move = tmp;
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp =  tmp->prev;
			while (tmp->prev != NULL && to_move->n < tmp->n)
				tmp = tmp->prev;
			if (to_move->n >= tmp->n)
			{
				tmp->next->prev = to_move;
				to_move->next = tmp->next;
				tmp->next = to_move;
				to_move->prev = tmp;
			}
			else
			{
				tmp->prev = to_move;
				to_move->prev = NULL;
				to_move->next = tmp;
				(*list) = to_move;
			}
		}
		if (print == 1)
			print_list((*list));
		mov = mov->next;
	}
}
