#include "sort.h"

/**
 * selection_sort - selection sort implementation
 *
 * @array: input array
 * @size: size of int array
 * Return: returns nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, small;
	int temp;

	for (i = 0; i < size; i++)
	{
		small = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[small])
				small = j;
		}
		if (array[i] != array[small])
		{
		temp = array[i];
		array[i] = array[small];
		array[small] = temp;
		print_array(array, size);
		}
	}
}
