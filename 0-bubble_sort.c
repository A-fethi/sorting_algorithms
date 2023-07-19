#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *						using the Bubble sort algorithm
 * @array: the array of integers to be sorted
 * @size: array size
 */

void	bubble_sort(int *array, size_t size)
{
	size_t	i, j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
