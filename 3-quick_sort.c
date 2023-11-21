#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort_helper - Sorts an array of integers in ascending order using the
 *                     Quick sort algorithm.
 * @array: The array to be sorted.
 * @low: The lowest index of the partition to be sorted.
 * @high: The highest index of the partition to be sorted.
 * @size: The size of the array.
 */

void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	int i, j;

	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;

		while (i < j)
		{
			while (array[i] <= array[pivot] && i <= high)
				i++;
			while (array[j] > array[pivot] && j >= low)
				j--;
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}

		temp = array[j];
		array[j] = array[pivot];
		array[pivot] = temp;
		print_array(array, size);

		quick_sort_helper(array, low, j - 1, size);
		quick_sort_helper(array, j + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 *              Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
