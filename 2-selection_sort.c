#include "sort.h"

/**
 * selection_sort - trie un tableau d'entiers par ordre croissant
 * en utilisant l'algorithme de trie par selection
 * @array: un tableau à trier
 * @size: la taille du tableau
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);
		}
	}
}
