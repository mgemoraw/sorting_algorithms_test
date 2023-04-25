#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UNUSED(x) (void)x

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    //const int n;
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


/**
 * struct slist - Singly linked list node
 *
 * @n: Integer stored in the node
 * @next: Pointer to the next element of the list
 */
typedef struct slist
{
    int n;
    struct slist *next;
} slist_t;

/* double linked list method */
void add_head(listint_t **head, listint_t *node);
void add_after(listint_t **left, listint_t *node);
void add_before(listint_t **right, listint_t *node);
void add_tail(listint_t **tail, listint_t *node);
void swap_adjacent(listint_t **node1, listint_t **node2);
void swap_nodes(listint_t **node1, listint_t **node2);
void print_list(listint_t *node);

/* single linked list method */
void add_head_s(slist_t **head, slist_t *node);
void add_after_s(slist_t **left, slist_t *node);
void add_before_s(slist_t **head, slist_t **right, slist_t *node);
void add_tail_s(slist_t **tail, slist_t *node);
void swap_adjacent_s(slist_t **node1, slist_t **node2);
void swap_nodes_s(slist_t **node1, slist_t **node2);
void print_list_s(slist_t *node);
#endif