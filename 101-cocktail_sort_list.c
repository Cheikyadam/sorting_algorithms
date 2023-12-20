#include "sort.h"

/**
 * swapbeg - swapping
 * @tmp: node
 * @help: node
 * @list: list
 *
 * Return: Nothing
 */

void swapbeg(listint_t *tmp, listint_t *help, listint_t (**list))
{
	if (tmp->next != NULL)
		tmp->next->prev = help;
	help->next = tmp->next;
	if (help->prev == NULL)
	{
		tmp->prev = NULL;
		tmp->next = help;
		help->prev = tmp;
		(*list) = tmp;
	}
	else
	{
		help->prev->next = tmp;
		tmp->prev = help->prev;
		help->prev = tmp;
		tmp->next = help;

	}
}
/**
 * swapend - swapping
 * @help: node
 * @tmp: node
 * @list: list
 *
 * Return: Nothing
 */
void swapend(listint_t *tmp, listint_t *help, listint_t (**list))
{
	tmp->next = help->next;
	if (help->next != NULL)
		help->next->prev = tmp;
	if (tmp->prev ==  NULL)
	{
		help->prev = NULL;
		help->next = tmp;
		tmp->prev = help;
		(*list) = help;
	}
	else
	{
		help->prev = tmp->prev;
		help->next = tmp;
		tmp->prev = help;
	}
}
/**
 * cocktail_sort_list - cocktail sort
 * @list: the list to be sorted
 *
 * Return: Nothing
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *mov = (*list), *end = NULL, *tmp = NULL, *help = NULL;

	do {
		swapped = 0;
		while (mov->next != NULL)
		{
			if (mov->n > mov->next->n)
			{
				help = mov;
				tmp = mov->next;
				swapbeg(tmp, help, list);
				mov = help;
				swapped = 1;
				print_list((*list));
			}
			end = mov;
			mov = mov->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (end->prev != NULL)
		{
			if (end->n < end->prev->n)
			{
				help = end;
				tmp = end->prev;
				swapend(tmp, help, (list));
				print_list((*list));
			}
			swapped = 1;
			end = end->prev;
		}
	} while (swapped);
}
