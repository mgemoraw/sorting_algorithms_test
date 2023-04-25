#include "linked_list.h"

/**
* main - main function
*
* Return: always 0
*/
int main(void)
{
	slist_t *list, *node1, *node2, *node3, *node4;

	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	// list = create_listint(array, n);

	list = malloc(sizeof(slist_t));
	list->n = array[4];
	list->next = NULL;

	node1 = malloc(sizeof(slist_t));
	node1->n = array[1];
	node1->next = NULL;

	node2 = malloc(sizeof(slist_t));
	node2->n = array[0];
	node2->next = NULL;

	node3 = malloc(sizeof(slist_t));
	node3->n = array[2];
	node3->next = NULL;

	node4 = malloc(sizeof(slist_t));
	node4->n = 66;
	node4->next = NULL;



	if (!list)
		return (1);
	print_list_s(list);
	add_after_s(&list, node1);
	print_list_s(list);
	printf("\t... added %d after %d \n", node1->n, list->n);

	add_after_s(&list, node2);
	print_list_s(list);
	printf("\t... added %d after %d \n", node2->n, list->n);


	add_before_s(&list, &(list->next), node3);
	print_list_s(list);
	printf("\t... added %d before %d \n", node3->n, list->next->next->n);

	swap_nodes_s(&(list->next), &(list->next->next));
	// print_list_s(list);

	return (0);
}

/**
* add_head_s - adds new node at the beginning
* @head: head node (reference node)
* @node: new node to be added
* Return: returns nothing
*/
void add_head_s(slist_t **head, slist_t *node)
{
	slist_t *temp;

	if (*head == NULL)
	{
		*head = node;
		(*head)->next = NULL;
		return;
	}
	else
	{
		temp = *head;
		node->next = temp;
		(*head) = node;
	}
}

/**
* add_tail_s - adds new node at the end
* @tail: tail node (reference node)
* @node: new node to be added
* Return: returns nothing
*/
void add_tail_s(slist_t **tail, slist_t *node)
{
	slist_t *temp;

	if(*tail == NULL)
	{
		add_head_s(tail, node);
		return;
	}
	while ((*tail)->next != NULL)
		*tail = (*tail)->next;
   
	(*tail)->next = node;
	node->next = NULL;
}

/**
* add_after_s - adds new node after given reference node
* @left: left node (reference node)
* @node: new node to be added
* Return: returns nothing
*/
void add_after_s(slist_t **left, slist_t *node)
{
	slist_t *temp;
	if (*left == NULL)
	{
		add_head_s(left, node);
		return;
	}
	else
	{
		temp = (*left)->next;
		node->next = temp;
		(*left)->next = node;
	}
}
/**
* add_before_s - adds new node after given reference node
* @head: head of the list
* @right: right node (reference node)
* @node: new node to be added
* Return: returns nothing
*/
void add_before_s(slist_t **head, slist_t **right, slist_t *node)
{
	slist_t *temp, *tp;
	bool b;
	if (*head == *right)
	{
		add_head_s(head, node);
		return;
	}

	if (*right == NULL)
	{
		printf("\n...can't add node before NULL...\n");
		printf("\n...please add it at the end...\n");
		return;
	}
	temp = *head;
	while ((temp->next) != *right)
		temp = temp->next;

	tp = temp->next;
	temp->next = node;
	node->next = *right;
	(*right)->next = tp;
}

 
/**
* swap_adjacent_s - swappes adjecent nodes
* @node1: first node to be swapped
* @node2: second node to be swapped
* Return: returns nothing
*/
void swap_adjacent_s(slist_t **node1, slist_t **node2)
{

}

/**
* swap_nodes_s - swappes two nodes
* @node1: first node to be swapped
* @node2: second node to be swapped
* Return: returns nothing
*/
void swap_nodes_s(slist_t **node1, slist_t **node2)
{

}

/**
* print_list_s - prints values to the stdout
* @node: node representing head of the list
* Return: returns nothing
*/
void print_list_s(slist_t *node)
{
	if (node == NULL)
	{
		return;
	}

		
	while (node != NULL)
	{
		printf("%d ", node->n);
		node = node->next;
	}
	printf("\n");
}
