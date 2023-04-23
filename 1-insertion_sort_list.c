#include "sort.h"
/**
 * insertion_sort_list - sorts a linked list
 *
 * @list: list of integers in a double linked list
 * Return: returns nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current, *sorted, *unsorted;
	size_t size, i = 0;

	if (*list == NULL)
		return;

	size = get_size(*list);

	current = *list;
	sorted = malloc(sizeof(listint_t));
	unsorted = malloc(sizeof(listint_t));
 
	while (i < size)
	{
		sorted = current->next->prev;
		unsorted = current->next;
		while (unsorted->next)
		{
			temp = unsorted;
			if (current->n > temp->n)
			{
				swap_nodes(&sorted, &unsorted);
				print_list(*list); 
			}
			unsorted = unsorted->next;
		}
		current = current->next;
		i++;
	}

}

void swap_nodes(listint_t **node1, listint_t **node2)
{
	listint_t *temp1, *temp2;

	if (*node1 == NULL || *node2 == NULL)
		return;

	temp1 = (*node1)->prev;
	temp2 = (*node2)->next;

	(*node2)->prev = temp1;
	(*node1)->next = temp2;

	(*node1)->prev = (*node2);
	(*node2)->next = (*node1);
}


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