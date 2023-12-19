#include "sort.h"

int partition(int *array, int lo, int hi, size_t size);

/**
 * quickSort - quick sort
 * @array: the array
 * @lo: first element
 * @hi: last one
 * @size: the main size of the array
 *
 * Return: Nothing
 */

void quickSort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo >= hi || lo < 0)
		return;

	p = partition(array, lo, hi, size);
	quickSort(array, lo, p - 1, size);
	quickSort(array, p + 1, hi, size);
}

/**
 * partition - divide array into partitions
 * @array: the array
 * @lo: first element of the partition
 * @hi: the last
 * @size: the real size
 *
 * Return: new pivot
 */

int partition(int *array, int lo, int hi, size_t size)
{
	int j, i;
	int pivot = array[hi], tmp;

	i = lo - 1;
	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	i++;
	if (array[i] != array[hi])
	{
		tmp = array[i];
		array[i] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort - algorithm, to call quicksort
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	int hi = (int)size;

	quickSort(array, 0, hi - 1, size);

}
