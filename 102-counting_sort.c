#include "sort.h"
#include <limits.h>
#include <stdlib.h>

/**
 * get_max - Discover max int value in an array.
 *
 * @array: array to find max value of
 * @size: size of the array
 * Return: 0
 */
int get_max(int *array, size_t size)
{
	int _max = INT_MIN;

	while (size--)
		if (array[size] > _max)
			_max = array[size];

	return (_max);
}

/**
 * counting_sort - array sorting
 * @array: array to sort
 * @size: size of array to sort
 */
void counting_sort(int *array, size_t size)
{
	int *_tmp, *_cpy, j, max;
	size_t i;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	_tmp = calloc(max + 1, sizeof(*_tmp));
	if (!_tmp)
		return;

	_cpy = malloc(sizeof(*_cpy) * size);
	if (!_cpy)
	{
		free(_tmp);
		return;
	}

	for (i = 0; i < size; i++)
		_tmp[array[i]]++;

	for (j = 1; j < max + 1; j++)
		_tmp[j] += _tmp[j - 1];

	print_array(_tmp, max + 1);

	for (i = 0; i < size; i++)
	{
		_tmp[array[i]]--;
		_cpy[_tmp[array[i]]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = _cpy[i];

	free(_tmp);
	free(_cpy);
}
