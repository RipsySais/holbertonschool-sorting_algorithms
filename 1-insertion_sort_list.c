#include "sort.h"

/**
 * insertion_sort_list - trie une liste doublement chainée
 * d'entiers en ordre croissant
 * en utilisant l'algorithme de tri par insertion
 * @list: pointeur vers la tete de la liste
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		while (temp->prev && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
