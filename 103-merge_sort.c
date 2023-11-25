#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _merge_sort - start merge sort
 * @array: array to be sorted
 * @temp: temp array for holding sorted elements
 * @size: size of the array
 */
void _merge_sort(int *array, int *temp, size_t size)
{
	size_t _half = size / 2, i = 0, j = 0, k;

	if (size < 2)
		return;

	_merge_sort(array, temp, _half);
	_merge_sort(array + _half, temp + _half, size - _half);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, _half);
	printf("[right]: ");
	print_array(array + _half, size - _half);
	for (k = 0; k < size; k++)
		if (j >= size - _half || (i < _half && array[i] < (array + _half)[j]))
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = (array + _half)[j];
			j++;
		}
	for (k = 0; k < size; k++)
		array[k] = temp[k];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - start merge sort
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *_temp;

	if (!array || size < 2)
		return;

	_temp = malloc(sizeof(*_temp) * size);
	if (!temp)
		return;

	_merge_sort(array, _temp, size);
	free(_temp);
}
