#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Prints a list of integers
 *
 * @array: The array
 * @size: The size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t x, y;

	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
