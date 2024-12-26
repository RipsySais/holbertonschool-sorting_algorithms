#include "sort.h"
#include <stdio.h>

/**
 * partition - schéma de partition de lomuto
 * @array: le tableau de partitionner
 * @low: indice de début
 * @high: indice de fin
 * @size: taille totale du tableau
 * Return: l'indice de partition
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_rec - fonction récursive de tri rapide
 * @array: le tableau à trier
 * @low: indice de début
 * @high: indice de fin
 * @size: taille de tableau
 */

void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		quick_sort_rec(array, low, pi - 1, size);
		quick_sort_rec(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - trie un tableau d'entiers par ordre
 * croissant en utilisant le tri rapide
 * @array: le tableau à trier
 * @size: la taille du tableau
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
