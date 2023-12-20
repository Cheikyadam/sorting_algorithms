#include "sort.h"
#include <stdlib.h>

/**
 * merging - merging step
 * @beg1: beginning
 * @end1: first end
 * @end2: second one
 * @t: the array
 *
 * Return: Nothing
 */

void merging(int *t, int beg1, int end1, int end2)
{
	int *table1;
	int beg2 = end1 + 1;
	int compt1 = beg1;
	int compt2 = beg2;
	int i;

	table1 = malloc((end1 - beg1 + 1) * sizeof(int));

	for (i = beg1; i <= end1; i++)
		table1[i - beg1] = t[i];

	for (i = beg1; i <= end2; i++)
	{
		if (compt1 == beg2)
			break;
		else if (compt2 == (end2 + 1))
		{
			t[i] = table1[compt1 - beg1];
			compt1++;
		}
		else if (table1[compt1 - beg1] < t[compt2])
		{
			t[i] = table1[compt1 - beg1];
			compt1++;
		}
		else
		{
			t[i] = t[compt2];
		}
	}
	free(table1);
}

/**
 * mergeSort - merge sort
 * @t: the array
 * @beg: begining of the array
 * @end: end
 *
 * Return: Nothing
 */

void mergeSort(int *t, int beg, int end)
{
	int middle;

	(void)middle;
	if (beg != end)
	{
		middle = (end + beg) / 2;
		mergeSort(t, beg, middle);
		mergeSort(t, middle + 1, end);
		merging(t, beg, middle, end);
	}
}
/**
 * merge_sort - merge sort
 * @array: the array
 * @size: size of the array
 *
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
	mergeSort(array, 0, size - 1);
}
