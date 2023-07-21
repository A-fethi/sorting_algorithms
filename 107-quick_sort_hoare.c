#include "sort.h"

/**
* swap - swap
* @arr: array
* @i: index
* @j: index
**/
void swap(int *arr, size_t i, size_t j)
{
	int tmp = arr[i];

	arr[i] = arr[j];
	arr[j] = tmp;
}

/**
 * swapAndPrint - Swaps two elements in an array and prints it
 * @array: Pointer to the array.
 * @i: Index of the first element to swap.
 * @j: Index of the second element to swap.
 * @arraySize: Size of the array.
 * Return : void
 */
void swapAndPrint(int *array, size_t i, size_t j, size_t arraySize)
{
	if (i != j)
	{
		swap(array, i, j);
		print_array(array, arraySize);
	}
}

/**
 * hoarePartition - Partitions an array around a pivot element.
 * @array: Pointer to the array to be partitioned.
 * @startIdx: Starting index of the subarray to be partitioned.
 * @endIdx: Ending index of the subarray to be partitioned.
 * @size: Size of the array.
 * Return: void
 */
size_t	hoarePartition(int *array, size_t startIdx, size_t endIdx, size_t size)
{
	size_t	i, j;
	int	pivot;

	i = startIdx - 1;
	j = endIdx + 1;
	pivot = array[endIdx];

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);
		swapAndPrint(array, i, j, size);
	}
}

/**
 * quickSortHoare-  helper func for quicksort algorithm.
 * @array: Pointer to the array to be sorted.
 * @startIdx: Starting index of the subarray to be sorted.
 * @endIdx: Ending index of the subarray to be sorted.
 * @arraySize: Size of the array.
 * Return: void
 */
void quickSortHoare(int *array, size_t startIdx, size_t endIdx,
		size_t arraySize)
{

	size_t pivotIdx;

	if (startIdx < endIdx)
	{
		pivotIdx = hoarePartition(array, startIdx, endIdx, arraySize);
		quickSortHoare(array, startIdx, pivotIdx - 1, arraySize);
		quickSortHoare(array, pivotIdx, endIdx, arraySize);
	}
}



/**
 * quick_sort_hoare - quicksort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array != NULL)
	{
		quickSortHoare(array, 0, size - 1, size);
	}
}

