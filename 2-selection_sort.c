#include "sort.h"
/**
 * selection_sort - Arranges integers in asc order within an array.
 * @array: element to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int k, j;

	if (size < 2)
		return;

	for (k = 0; k < size; k++)
	{
		unsigned int x = k;
		int asc = array[k];

		for (j = k + 1; j < size; j++)
		{
			if (array[j] < asc)
				asc = array[j], x = j;
		}
		if (x != k)
		{
			array[x] = array[k];
			array[k] = asc;
			print_array(array, size);
		}
	}
}
