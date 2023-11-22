#include <stddef.h>
#include "sort.h"
/**
  * selection_sort - arrange array of ints ascending
  * order using selec sort
  * @array: array of integers
  * @size: array taille
  */
void selection_sort(int *array, size_t size)
{
	size_t pas, indx_min, k;

	for (pas = 0; pas < size - 1; pas++)
	{
		indx_min = pas;
		for (k = pas + 1; k < size; k++)
		{
			if (array[k] < array[indx_min])
			{
				indx_min = k;
			}
		}
		if (indx_min != pas)
		{
			echange(&array[indx_min], &array[pas]);
			print_array(array, size);
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

