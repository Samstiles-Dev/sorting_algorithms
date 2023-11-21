#include "sort.h"

/**
 * bubble_sort - Sorts integer array in ascending order using Bubble sort.
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
size_t i, n, new_node;
int swap;

if (array == NULL || size < 2)
return;

n = size;
while (n > 0)
{
new_node = 0;
for (i = 0; i < n - 1; i++)
{
if (array[i] > array[i + 1])
{
swap = array[i];
array[i] = array[i + 1];
array[i + 1] = swap;
new_node = i + 1;
print_array(array, size);
}
}
n = new_node;
}
}
