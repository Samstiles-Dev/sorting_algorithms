/*
 * File: 107-quick_sort_hoare.c
 */

#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap 2 integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int _tmp;

	_tmp = *a;
	*a = *b;
	*b = _tmp;
}

/**
 * hoare_partition - Order a subset of an array of ints
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the _pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int _pivot, _above, _below;

	_pivot = array[right];
	for (_above = left - 1, _below = right + 1; _above < _below;)
	{
		do {
			_above++;
		} while (array[_above] < _pivot);
		do {
			_below--;
		} while (array[_below] > _pivot);

		if (_above < _below)
		{
			swap_ints(array + _above, array + _below);
			print_array(array, size);
		}
	}

	return (_above);
}

/**
 * hoare_sort - Use recursion to apply the quicksort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int _part;

	if (right - left > 0)
	{
		_part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, _part - 1);
		hoare_sort(array, size, _part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of ints in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
