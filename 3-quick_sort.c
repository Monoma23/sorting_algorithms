#include <stddef.h>
#include "sort.h"

/**
  * partitionn - partitionn the array
  * @array: array of ints
  * @myLow: myLow idx
  * @high: high idx
  * @size: array size
  * Return: return i_ lowest idx
  */

int partitionn(int *array, int myLow, int high, size_t size)
{
	int pivott = array[high], i = myLow, w;

	for (w = myLow; w <= high - 1; w++)
	{
		if (array[w] <= pivott)
		{
			echange(&array[i], &array[w]);
			if (i != w)
				print_array(array, size);
			i++;
		}
	}
	echange(&array[i], &array[high]);
	if (i != w)
		print_array(array, size);
	return (i);
}
/**
  * arryQuicksort - .
  * @array: array of ints
  * @left: lowest idx
  * @right: highest idx
  * @size: size of array
  */
void arryQuicksort(int *array, int left, int right, size_t size)
{
	int pivott;

	if (left < right)
	{
		pivott = partitionn(array, left, right, size);
		arryQuicksort(array, left, (pivott - 1), size);
		arryQuicksort(array, (pivott + 1), right, size);
	}
}
/**
  * quick_sort - sort array of ints using insertion sort
  * @array: array to sort
  * @size: size of array
  */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	arryQuicksort(array, 0, size - 1, size);
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

