#include "sort.h"

/**
 * bubble_sort - trie un tableau d'entier par
 * ordre croissant en utilisant l'algorithme de tri à bulle
 * @array: le tableau à trier
 * @size: la taille du tableau
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;
	int swapped = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;

				print_array(array, size);
			}
		}

		if (!swapped)
			break;
	}
}
