#include "sort.h"

/**
 * selection_sort - Selection sort
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: Nothibg
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, ind_min, j;
	int tmp = 0;

	if (array == NULL || size == 0)
		return;
	for (i = 0; i < size; i++)
	{
		ind_min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[ind_min])
				ind_min = j;
		}
		if (ind_min != i)
		{
			tmp = array[ind_min];
			array[ind_min] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
