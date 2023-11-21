#include "sort.h"
/**
 * swap - Arranges integers in asc order within an array.
 * @array: elements to be sorted
 * @i: left element
 * @j: right element
 * @size: size of array
 */
void swap(int *array, int i, int j, int size)
{
	int asc;

	if (array[i] == array[j])
		return;
	asc = array[i];
	array[i] = array[j];
	array[j] = asc;
	print_array(array, size);
}
/**
 * partition - sort array partition
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 * Return: pivot sorted
 */
int partition(int *array, int start, int end, int size)
{
	int k;
	int pivot = array[end];
	int split_idx = start;

	for (k = start; k < end; k++)
		if (array[k] < pivot)
			swap(array, split_idx++, k, size);
	swap(array, split_idx, end, size);
	return (split_idx);
}
/**
 * recursive - quick_sort core
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 */
void recursive(int *array, int start, int end, int size)
{
	if (start < end)
	{
		int pivot_pos = partition(array, start, end, size);

		recursive(array, start, pivot_pos - 1, size);
		recursive(array, pivot_pos + 1, end, size);
	}
}
/**
 * quick_sort - Arranges integers in asc order within an array.
 * @array: elements to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	recursive(array, 0, size - 1, size);
}
