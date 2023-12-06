#include <stdio.h>

#define N 7

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int *arr)
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j > 0 && arr[j] < arr[j - 1] ; j--)
        {
            swap(&arr[j], &arr[j - 1]);
        }
    }
}

int selectionSort(int *arr)
{
    for (int i = 0; i < N; i++)
    {
        int min = i;
        for (int j = i; j < N; j++)
        {
            if (arr[j] < arr[min]) min = j;
        }
        swap(&arr[i], &arr[min]);
    }
}

int main()
{
    int arr_0[N] = {3,2,-23,122,45,76,12};

    insertionSort(arr_0);

    for (int i = 0; i < N; i++)
    {
        printf("%i ",arr_0[i]);
    }

    printf("\n");

    int arr_1[N] = {5,6,-76,23,-32,3,6};

    selectionSort(arr_1);

    for (int i = 0; i < N; i++)
    {
        printf("%i ",arr_1[i]);
    }
}