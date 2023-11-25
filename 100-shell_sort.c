#include "sort.h"
/**
 * shell_sort -Use shell_sort to organize an array
 * @array: array
 * @size: size of the array
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, i, j;
	int _tmp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			_tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > _tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = _tmp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
