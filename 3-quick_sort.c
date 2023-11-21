#include "sort.h"

/**
 * swap - Swap two numbers in an array.
 * @num1: The first number to swap.
 * @num2: The second number to swap.
 */
void swap(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * lomuto_partition - get partitions
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @low: Low index
 * @high: high index
 *
 * Return: pivot
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	/* choose the last element as the pivot*/
	int p, tmp_quick, j;

	p = array[high]; /* last element is the pivot */
	tmp_quick = low - 1; /* temporary pivot index */
	j = low;

	while (j < high)
	{
		if (array[j] < p)
		{
			tmp_quick++; /* move it forward */

			if (tmp_quick != j)
			{
				swap(array + tmp_quick, array + j);
				print_array(array, size);
			}
		}
		j++;
	}

	if (array[high] < array[tmp_quick + 1])
	{
		swap(array + tmp_quick + 1, array + high);
		print_array(array, size);
	}

	return (tmp_quick + 1);
}

/**
 * quicksort - implement the quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @low: Low index
 * @high: high index
 *
 * Return: Nothing
 */
void quicksort(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low >= high || low < 0)
		return;

	pivot = lomuto_partition(array, size, low, high);

	/* sort partitions */
	quicksort(array, size, low, pivot - 1); /* left side*/
	quicksort(array, size, pivot + 1, high);
}

/**
 * quick_sort - Sorts an array of numbers using quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quicksort(array, size, 0, size - 1);
}
