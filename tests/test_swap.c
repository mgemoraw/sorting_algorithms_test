#include "../sort.h"

void add_head(listint_t **head, listint_t *node);
void add_after(listint_t **left, listint_t *node);
void add_before(listint_t **right, listint_t *node);
void add_tail(listint_t **tail, listint_t *node);
void swap_adjacent(listint_t **node1, listint_t **node2);

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

    //node2->prev = node1;
    //node1->next = node2;
    //list->next = node1;
    //add_after(&node2, &node3);
    //node2->next = node3;



    if (!list)
        return (1);
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

    swap_nodes(&(list->next), &(list->next->next));
    print_list(list);

    return (0);
}


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

void add_tail(listint_t **tail, listint_t *node)
{
    listint_t *temp;

    if(*tail == NULL)
    {
        add_head(tail, node);
        return;
    }
    else
    {
        (*tail)->next = node;
        node->prev = *tail;
        node->next = NULL;
    }
}

void add_before(listint_t **right, listint_t *node)
{
    listint_t *temp;

    if(*right == NULL || (*right)->prev == NULL)
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
        add_tail(left,node);
    }
    else
    {
       temp->prev = node;
       (*left)->next = node;
       node->prev = *left;
       node->next = temp; 
    }
}





void swap_nodes(listint_t **node1, listint_t **node2)
{
	listint_t *left, *right, *temp1, *temp2;

	if (*node1 == NULL && *node2 == NULL)
		return;

    if ((*node1)->prev !=NULL && (*node2)->next != NULL)
	{
        left = (*node1)->prev;
        right = (*node2)->next;

        temp1 = (*node1)->next;
        temp2 = (*node2)->prev;

       
               

        left->next = *node2;
        right->prev = *node1;

        temp1->prev = *node2;
        (*node2)->prev = left;
        (*node2)->next = temp1;

        temp2->next = *node1;
        (*node1)->prev = temp2;
        (*node1)->next = right;

    }
   

}


void swap_adjacent(listint_t **node1, listint_t **node2)
{
    listint_t *temp1, *temp2, **temp;

	if (*node1 == NULL && *node2 == NULL)
		return;

    temp1 = (*node1)->prev;
    temp2 = (*node2)->next;

    if(temp1 == NULL)
        (*node2)->prev = NULL;        
    else
    {
        temp1->next = *node2;
        (*node2)->prev = temp1;
    }

    if (temp2 == NULL)
    {
        (*node1)->next = NULL;
    }
    else
    {
        temp2->prev = *node1;
        (*node1)->next = temp2;
    }
    
    (*node2)->next = *node1;
    (*node1)->prev = *node2;

    temp = node1;
    node1 = node2;
    node2 = temp;

}