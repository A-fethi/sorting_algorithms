#include "sort.h"

/**
 * swap - Swaps two integer values
 * @i: pointer to the first integer value
 * @j: pointer to the second integer value
 */

void	swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * lomuto - Lomuto partition scheme for the QuickSort algorithm
 * @arr: pointer to the array or subarray to be partioned
 * @low: starting index of the subarray to be partioned
 * @high: ending index of the subarray to be partioned
 * Return: the index of the pivot element after the partitioning is complete
 */

int	lomuto(int *arr, size_t low, size_t high)
{
	int	pivot;
	size_t	i, j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			print_array(arr, high + 1);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	print_array(arr, high + 1);
	return (i + 1);
}

/**
 * quick_sort -  sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array of integers to be sorted
 * @size: array size
 */

void	quick_sort(int *array, size_t size)
{
	int	lomutoindex;

	if (size <= 1)
		return;
	lomutoindex = lomuto(array, 0, size - 1);
	quick_sort(array, lomutoindex);
	quick_sort(array + lomutoindex + 1, size - lomutoindex - 1);
}
