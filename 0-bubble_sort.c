#include <stddef.h>
#include "sort.h"

/**
  * bubble_sort - arrange array of ints in ascending order
  * bubble sort
  * @array: array of ints
  * @size: arry size
  */

void bubble_sort(int *array, size_t size)
{
	size_t k, h;

	if (size < 2)
		return;
	for (k = 0; k < size; k++)
	{
		for (h = 0; h < size - k - 1; h++)
		{
			if (array[h] > array[h + 1])
			{
				echange(&array[h], &array[h + 1]);
				print_array(array, size);
			}
		}
	}
}

/**
  * echange - exchange two elems
  * @c: first one
  * @d: second
  */
void echange(int *c, int *d)
{
	int temporaire = *c;
	*c = *d;
	*d = temporaire;
}