#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: the array of integers to be sorted
 * @size: array size
 */

void	selection_sort(int *array, size_t size)
{
	int	tmp;
	size_t	i, j, min;

	i = 0;
	min = i;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
			j++;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
		i++;
		min = i;
	}
}
