#include <stdio.h>

void _swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int _partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1, j, swaps=0;

    for (j = low; j <= high -1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            _swap(&arr[i], &arr[j]);
            
            //print_array(arr, high+1);
            //printf("...%d", iter);
            swaps++;
        }
    }
    _swap(&arr[i + 1], &arr[high]);
    swaps++;
    print_array(arr, high+1);
    printf("...%d\n", swaps);


    return (i + 1);
}


void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
      int pi = _partition(arr, low, high);

      quick_sort(arr, low, pi - 1);
      quick_sort(arr, pi + 1, high);  
    }
}

int main(void)
{
    // int arr[] = { 10, 7, 8, 9, 1, 5 };
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 4};
    int it, n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, 10);
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("\n........\n");
    //     it = _partition(arr, 0, 9);
    //     printf("\n i = %d\n", it);
    // }
    quick_sort(arr, 0, 9);
    printf("\n........\n");
    print_array(arr, 10);
    
}