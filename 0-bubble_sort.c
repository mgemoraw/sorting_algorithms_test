#include "sort.h"
/**
 * bubble_sort - sorts an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * Return: returns nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	for (i = 0; i < size; i++)
	{
		for (j = 0, k = 1; (j < size - i) && (k < size - i); j++, k++)
		{
			if (array[j] > array[k])
			{
				int temp = array[j];
				array[j] = array[k];
				array[k] = temp;
				print_array(array, size);
			}
		}
	}	
}
