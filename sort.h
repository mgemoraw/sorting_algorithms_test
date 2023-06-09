#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* printing functions */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* array functions */
void _swap(int *a, int *b);


/* bubble sort functions */
void bubble_sort(int *array, size_t size);

/* insertion sort functions */
size_t get_size(listint_t *list);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **node1, listint_t **node2);
void swap_nodess(listint_t **head, listint_t **node1, listint_t *node2);

/* selection sort functions */
void selection_sort(int *array, size_t size);

/* quick sort functions */
void quick_sort(int *array, size_t size);
int _partition(int arr[], int low, int high);

#endif
