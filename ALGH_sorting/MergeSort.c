#include <stdio.h>

#define m 17

void insertionSort(int *arr, int low, int high);
void merge(int *arr, int low, int mid, int high);
void sort(int *arr, int low, int high);
void sort_bottomUp(int *arr, int size);
void swap(int *a, int *b);

//The key is in the "merge" step, where two sorted 
//sub-arrays are combined into a single sorted array. 
//It compares elements from both arrays, one by one, 
//and places them in the correct order in a new temporary array.
void merge(int *arr, int low, int mid, int high) //see robert sedgewick-kevin wayne algorithms /page271
{
    if (high - low < 15)                //if the size of small subarray is less than 15
    {                                   //
        insertionSort(arr, low, high);  //switch to insertion sort for better performance.
        return;
    }
    
    int i = low, j = mid + 1;
    int temp[m];

    for (int k = low; k <= high; k++)
        temp[k] = arr[k];
    
    if (temp[mid] <= temp[mid + 1]) return;     //checking if the two sub arrays already sorted by comparing
                                                //the last element of first sub array and first element of second sub array
    for (int k = low; k <= high; k++)
    {
        if      (i > mid)            arr[k] = temp[j++];  //if its exceeded from the left side include the right side of the arr
        else if (j > high)           arr[k] = temp[i++];  //if its exceeded from the right side include the left side of the arr              
        else if (temp[j] < temp[i])  arr[k] = temp[j++];  //compare the elements from left to right from both left and right array 
        else                         arr[k] = temp[i++];  //compare the elements from left to right from both left and right array
    }   
}

//Recursively sort.
void sort(int *arr, int low, int high)
{
    if (high <= low) return;
    
    int mid = low + (high - low) / 2;

    sort(arr, low, mid);        //sort left side
    sort(arr, mid + 1, high);   //sort right side
    merge(arr, low, mid, high); //merge the sorted arrays
}

//Divide all array then merge all, divide all, merge all and so on
void sort_bottomUp(int *arr, int size)
{
    int N = size;

    for (int sz = 1; sz < N; sz = sz + sz)
    {
        for (int low = 0; low < N - sz; low += sz + sz)
        {
            int min = ((low + sz + sz - 1) > (N - 1)) ? (N - 1) : (low + sz + sz - 1);
            merge(arr, low, low + sz - 1, min);
        }
    }
}

void insertionSort(int *arr, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        for (int j = i; j > 0 && arr[j] < arr[j - 1] ; j--)
        {
            swap(&arr[j], &arr[j - 1]);
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[m] = {2,2,-2,5,8,4,1,12,34,54,-83,12,5,35,75,-3,-332};

    sort(arr, 0, m - 1);

    for (int i = 0; i < m; i++)
    {
        printf("%i ",arr[i]);
    }
    
}