#include <stdio.h>

void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);
int partition_2(int array[], int low, int high);

int main(void)
{
    int a[] = {-122,3,1,5,4,12,4,23,12,22,-2,-3,-1,123,3,2,1,321,4,3,231,545,34,343,3,5,43,245,34,3543,2,5,21,2,45};                               
    int length = sizeof(a)/sizeof(int);                                  

    quicksort(a, length);

    for (int i = 0; i < length; i++)
        printf("%i ", a[i]);
}

void swap(int *x, int *y)                                                                                                   
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int array[], int length)
{
    quicksort_recursion(array, 0, length - 1);
}

void quicksort_recursion(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition_2(array, low, high);
        quicksort_recursion(array, low, pivot_index - 1);   //left side of pivot
        quicksort_recursion(array, pivot_index + 1, high);  //right side of pivot
    }
}

int partition(int array[], int low, int high)
{
    int pivot_value = array[high];

    int i = low;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot_value)
        {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i;
}

int partition_2(int array[], int low, int high)
{
    int i = low, j = high + 1;

    int pivot_value = array[low];

    while (1)
    {
        while (array[++i] < pivot_value) if (i == high) break;
        while (pivot_value < array[--j]) if (j == low) break;
        if (i >= j) break;
        swap(&array[i], &array[j]);
    }
    swap(&array[low], &array[j]);
    return j;
}






//      5 9 8 2 1 3 [6]          1) bir girdi seç
//                   |
//         5 2 1 [3] 6 9 [8]     2) sol tarafına küçükleri sağa büyükleri at
//                |       | 
//          2 [1] 3 5   6 8 9    3) 2 yi tekrarla  
//             | 
//             1 2 3 5  6 8 9
//
//
//