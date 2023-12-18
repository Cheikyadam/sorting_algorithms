#include "sort.h"

/**
 * bubble_sort - Bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int tmp = 0, new_c = 0;

	for (i = 0; i < size; i++)
	{
		new_c = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				new_c = 1;
				print_array(array, size);
			}
		}
		if  (new_c == 0)
			break;
	}
}
