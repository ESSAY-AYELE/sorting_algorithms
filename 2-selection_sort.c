#include "sort.h"

/**
 * selection_sort - sort array using selection sort algoritm
 * @array: the array
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	int min, tmp;
	size_t i, j, index;

	if (size <= 1)
		return;
	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				index = j;
			}
		}
		if (array[i] != min)
		{
			tmp = array[i];
			array[i] = min;
			array[index] = tmp;
			print_array(array, size);
		}
	}
}
