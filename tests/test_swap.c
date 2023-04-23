#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list, *node1, *node2, *node3;

    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    // list = create_listint(array, n);

    list = malloc(sizeof(listint_t));
    list->n = array[4];
    list->next = NULL;

    node1 = malloc(sizeof(listint_t));
    node1->n = array[1];
    node1->prev = list;
    node1->next = NULL;

    list->next = node1;

    node2 = malloc(sizeof(listint_t));
    node2->n = array[0];
    node2->next = NULL;

    node2->prev = node1;
    node1->next = node2;
    
    node3 = malloc(sizeof(listint_t));
    node3->n = array[2];
    node3->next = NULL;
    
    //add_after(&node2, &node3);
    node2->next = node3;



    if (!list)
        return (1);
    print_list(list);
    swap_nodes(&node1, &node2);
    print_list(list);
    return (0);
}


void swap_nodes(listint_t **node1, listint_t **node2)
{
	listint_t **left, **right, **temp1, **temp2;

	if (*node1 == NULL && *node2 == NULL)
		return;

	*left = (*node1)->prev;
    *temp1 = (*node1)->next;

    *temp2 = (*node2)->prev;
    *right = (*node2)->next;

    add_after(left, node2);
    // left->next = *node2;
    // (*node2)->prev = left;

    // temp1->prev = *node2;
    // (*node2)->next = temp1;
    

    // right->prev = *node1;
    // (*node1)->next = right;

    // temp2->next = *node1;
    // (*node1)->prev = temp2;

}


void add_after(listint_t **left, listint_t **node)
{
    listint_t *temp = NULL;

    temp= (*left)->next;

    (*left)->next = *node;
    temp->prev = *node;

    (*node)->next = temp;
    (*node)->prev = *left;


}

// void add_before(listint_t **right, listint_t **node)
