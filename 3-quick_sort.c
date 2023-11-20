#include "sort.h"

/**
 * quick_sort - sort a array using a quick sort algorithm
 * @array: the array
 * @size: the poistion of the pivote
 */
void quick_sort(int *array, size_t size)
{
	size_t r, l, p, i, n;
	int tmp;

	if (size <= 1)
		return;
	for (n = 0; array[n] != '\0'; n++)
		;
	n--;
	r = size - 2;
	l = 0;
	p = size - 1;
	for (i = 0; i < size; i++)
	{
		while (array[l] <= array[p] && l < r)
			l++;
		while (array[r] >= array[p] && l < r)
			r--;
		if (l != r)
		{
			tmp = array[l];
			array[l] = array[r];
			array[r] = tmp;
			print_array(array, n);
		}
		else if (l == r)
		{
			if (array[p] < array[l])
			{
				tmp = array[l];
				array[l] = array[p];
				array[p] = tmp;
				print_array(array, n);
				quick_sort(array, size);
				break;
			}
			else
			{
				quick_sort(array, size - 1);
				break;
			}}}}
