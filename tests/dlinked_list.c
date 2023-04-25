#include "linked_list.h"


/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list, *node1, *node2, *node3, *node4;

	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	//size_t n = sizeof(array) / sizeof(array[0]);

	// list = create_listint(array, n);

	list = malloc(sizeof(listint_t));
	list->n = array[4];
	list->next = NULL;

	node1 = malloc(sizeof(listint_t));
	node1->n = array[1];
	node1->prev = NULL;
	node1->next = NULL;

	node2 = malloc(sizeof(listint_t));
	node2->n = array[0];
	node2->next = NULL;
	node2->prev = NULL;

	node3 = malloc(sizeof(listint_t));
	node3->n = array[2];
	node3->next = NULL;
	node3->prev = NULL;

	node4 = malloc(sizeof(listint_t));
	node4->n = 77;
	node4->next = NULL;
	node4->prev = NULL;

	list->next = node1;
	node1->prev = list;

	node1->next = node2;
	node2->prev = node1;

	node2->next = node3;
	node3->prev = node2;

	node3->next = node4;
	node4->prev = node3;

	if (!list)
		return (1);
	/*
	print_list(list);
	add_after(&list, node1);
	print_list(list);
	printf("\t... added %d after %d \n", node1->n, list->n);

	add_after(&list, node2);
	print_list(list);
	printf("\t... added %d after %d \n", node2->n, list->n);


	add_before(&list, node3);
	print_list(list);
	printf("\t... added %d before %d \n", node3->n, list->next->n);


	add_tail(&list, node4);
	printf("\t... added %d on tail \n", node4->n);
	print_list(list);
	*/
	print_list(list);
	// swap_nodes(&node1, &node2);
	swap_nodes(&list, &node1);
	print_list(list);

	return (0);
}

/**
* add_head - adds new node at the beginning
* @head: head node (reference node)
* @node: new node to be added
* Return: returns nothing
*/
void add_head(listint_t **head, listint_t *node)
{
	listint_t *temp;

	if (*head == NULL)
	{
		*head = node;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		return;
	}
	else
	{
		temp = *head;
		temp->prev = node;
		node->next = temp;
		(*head) = node;
	}
}

/**
* add_tail - adds new node at the end
* @tail: tail node (reference node)
* @node: new node to be added
* Return: returns nothing
*/
void add_tail(listint_t **tail, listint_t *node)
{

	if (*tail == NULL)
	{
		add_head(tail, node);
		return;
	}
	while ((*tail)->next != NULL)
		*tail = (*tail)->next;

	node->prev = *tail;
	node->next = NULL;
	(*tail)->next = node;

}

/**
* add_before - adds new node after given reference node
* @right: right node (reference node)
* @node: new node to be added
* Return: returns nothing
*/
void add_before(listint_t **right, listint_t *node)
{
	listint_t *temp;

	if (*right == NULL || (*right)->prev == NULL)
	{
		add_head(right, node);
		return;
	}
	else
	{
		temp = (*right)->prev;
		(*right)->prev = node;
		temp->next = node;

		node->next = *right;
		node->prev = temp;
	}

}

/**
* add_after - adds new node after given reference node
* @left: left node (reference node)
* @node: new node to be added
* Return: returns nothing
*/
void add_after(listint_t **left, listint_t *node)
{
	listint_t *temp;

	if (*left == NULL)
	{
		add_head(left, node);
		return;
	}
	temp = (*left)->next;

	if (temp == NULL)
	{
		add_tail(left, node);
	}
	else
	{
	   temp->prev = node;
	   (*left)->next = node;
	   node->prev = *left;
	   node->next = temp;
	}
}



/**
* swap_nodes - swappes adjecent nodes
* @node1: first node to be swapped
* @node2: second node to be swapped
* Return: returns nothing
*/
void swap_nodes(listint_t **node1, listint_t **node2)
{
	listint_t *left, *right, *temp1, *temp2;

	if (*node1 == NULL || *node2 == NULL)
		return;

	left = (*node1)->prev;
	right = (*node2)->next;

	temp1 = (*node1)->next;
	temp2 = (*node2)->prev;

	
	if ((*node1)->next == *node2  && (*node2)->prev == *node1)
	{
		if (left != NULL)
			left->next = *node2;
		(*node2)->prev = left;
		(*node2)->next = *node1;

		if (right != NULL)
			right->prev = *node1;
		(*node1)->prev = *node2;
		(*node1)->next = right;
		return;
	}
	if ((*node2)->next == *node1 && (*node1)->prev == *node2)
	{
		left = (*node2)->prev;
		right = (*node1)->next;

		if (left != NULL)
			left->next = *node1;
		(*node1)->prev = left;
		(*node1)->next = *node2;

		if (right != NULL)
			right->prev = *node2;
		(*node2)->prev = *node1;
		(*node2)->next = right;
		return;
	}
	
	//((*node1)->prev !=NULL && (*node2)->next != NULL)
	if (*node1 && *node2)
	{
		if (left != NULL)
			left->next = *node2;

		(*node2)->prev = left;
		temp1->prev = *node2;
		(*node2)->next = temp1;

		if (right != NULL)
			right->prev = *node1;

		temp2->next = *node1;
		(*node1)->prev = temp2;
		(*node1)->next = right;
		return;
	}
}

/**
* swap_adjacent - swappes adjecent nodes
* @node1: first node to be swapped
* @node2: second node to be swapped
* Return: returns nothing
*/
void swap_adjacent(listint_t **node1, listint_t **node2)
{
	listint_t *left, *right;

	if (*node1 == NULL || *node2 == NULL)
		return;

	left = (*node1)->prev;
	right = (*node2)->next;

	if ((*node1)->next == *node2  && (*node2)->prev == *node1)
	{
		if (left != NULL)
			left->next = *node2;
		(*node2)->prev = left;
		(*node2)->next = *node1;

		if (right != NULL)
			right->prev = *node1;
		(*node1)->prev = *node2;
		(*node1)->next = right;
		return;
	}
	if ((*node2)->next == *node1 && (*node1)->prev == *node2)
	{
		left = (*node2)->prev;
		right = (*node1)->next;

		if (left != NULL)
			left->next = *node1;
		(*node1)->prev = left;
		(*node1)->next = *node2;

		if (right != NULL)
			right->prev = *node2;
		(*node2)->prev = *node1;
		(*node2)->next = right;
		return;
	}
}

/**
* print_list - prints values to the stdout
* @node: node representing head of the list
* Return: returns nothing
*/
void print_list(listint_t *node)
{
	if (node == NULL)
	{
		return;
	}

	while (node->prev != NULL)
		node = node->prev;

	while (node != NULL)
	{
		printf("%d ", node->n);
		node = node->next;
	}
	printf("\n");
}
