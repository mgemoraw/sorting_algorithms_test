#include "sort.h"



/**
 * _swap - swaps values of two containers
 *
 * @a: input element 1
 * @b: input element 2
 */
void _swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * lomuto_partition -  partitions array using Lomuto partition scheme
 *
 * @arr: input array
 * @low: lower index
 * @high: higher index
 * @size: size of array
 * Return: returns next partition pivot
 */
int lomuto_partition(int arr[], size_t size, int low, int high)
{
	int pivot = arr[high];

	int i, j, swaps = 0;

	for (i = j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			if (i < j)
			{
				_swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
			swaps++;
			i++;
		}


	}
	if (arr[i] > pivot)
	{
		_swap(&arr[i], &arr[high]);
		print_array(arr, size);
		swaps++;
	}
	return (i);
}


/**
 * lomuto_sort - quick sort implementation using lomuto partition scheme
 *
 * @arr: input array
 * @low: lower index
 * @high: higher index
 * @size: size of the list
 */
void lomuto_sort(int arr[], size_t size, int low, int high)
{
	if (low < high)
	{
		int pi = lomuto_partition(arr, size, low, high);

		lomuto_sort(arr, size, low, pi - 1);
		lomuto_sort(arr, size, pi + 1, high);
	}
}

/**
 * quick_sort - quick sort algorithm
 *
 * @array: input array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t low = 0, high = size - 1;

	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, low, high);
}
