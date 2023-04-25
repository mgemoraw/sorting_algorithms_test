#include "sort.h"
/**
 * insertion_sort_list - sorts a linked list
 *
 * @list: list of integers in a double linked list
 * Return: returns nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = (iter->next);
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodess(list, &insert, iter);

			print_list(*list);
		}

	}

}
/**
 * get_size - Get the size object
 *
 * @list: head of the list
 * Return: returns size of list
 */
size_t get_size(listint_t *list)
{
	size_t size = 0;

	if (list == NULL)
		return (size);

	while (list != NULL)
	{
		size++;
		list = list->next;
	}

	return (size);
}


/**
 * swap_nodess - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodess(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
