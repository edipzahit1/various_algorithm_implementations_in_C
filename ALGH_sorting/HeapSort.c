#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swim(int *arr, int k)    //to move an entry to up
{
    while (k > 1 && arr[k / 2] < arr[k])
    {
        swap(&arr[k / 2], &arr[k]);
        k = k / 2;
    }
}

void sink(int *arr, int k, int size)      //to bottom
{
    while (2 * k < size)
    {
        int j = 2 * k;
        if (j < size && arr[j] < arr[j + 1]) j++;
        if (j <= k) break;
        swap(&arr[k], &arr[j]);
        k = j;
    }
}

void sort(int *arr, int size)
{
    for (int k = size / 2; k >= 1; k--)
        sink(arr, k, size);

    while (size > 1)
    {
        swap(&arr[1], &arr[size--]);
        sink(arr, 1, size);
    }
}

int main()
{
    int arr[] = {0, 10, 20, 15, 12, 40, 25, 18};
    int siz = sizeof(arr)/sizeof(int);
    int x = sizeof(arr)/sizeof(int);

    printf("%i\n",x);
    sort(arr, siz);   
    printf("%i %i\n",siz, x);
    
    /*for(int i = 1; i < 9; ++i)
        printf("%i ",arr[i]);*/
}

/*int heapify(int arr[], int size, int i);
int swap(int *a, int *b);
int Heapify(int *arr, int size);
int heapSort(int *arr, int size, int i);*/

/*
int heapSort(int *arr, int size, int i)
{
    for (int i = size - 1; i > 0; i--) //go thorugh all elements
    {
        swap(&arr[0], &arr[i]); //swap the current elemnt with root
        heapify(arr, i, 0); // rearanging the changed array //size reduced in order to avoid arranging the root at the end of the list.
    }
}

int heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

int Heapify(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; --i)
    {
        heapify(arr, size, i);
    }
}*/

//Another implementation of heap//



/*int delMax(int *arr, int size)
{
    int max = arr[1];
    swap(&arr[1], &arr[size--]);
   // arr[size + 1] = NULL;
    sink(arr, 1, size);
    return max;
}*/

/*void insert(int *arr, int size, int v)
{
    arr = (int *)malloc(sizeof(arr) + sizeof(int));
    arr[++size] = v;
    swim(arr,size);
}*/

