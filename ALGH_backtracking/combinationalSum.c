//combinational sum (can be optimized)
#include <stdio.h>

int *findCombinations(int arr[], int sizeOfarr, int sum, int indexOfarr, int res[], int indexOfres);
void clear_arr(int arr[], int size);

void clear_arr(int arr[], int size)
{
    int temp[50];
    int i = 0;
    temp[0] = arr[0];

    for (int j = 0; j < size; ++j)
    {
        if (arr[i] == temp[j])
            ++i;
        else
            temp[j] = arr[i];
        ++i;
    }
    
    while (size > 0)
    {
        arr[size] = temp[size];
        --size;
    }
}

int *findCombinations(int arr[], int sizeOfarr, int sum, int indexOfarr, int res[], int indexOfres)
{
    if (sum == 0)
    {
        for (int i = 0; i < indexOfres; ++i)
        {
            printf("%i ",res[i]);
        }
        printf("\n");
        return 0;
    }
    for (int i = indexOfarr; i < sizeOfarr; ++i)
    {
        if (sum >= arr[i])
        {
            res[indexOfres] = arr[i];
            findCombinations(arr, sizeOfarr, sum - arr[i], i, res, indexOfres + 1);
            
            while (i + 1 < sizeOfarr && arr[i] == arr[i + 1])
            {
                ++i;
            }
        }
        
    }
    
}

int main()
{
    int arr[7] = {1,1,2,3,4,6,8};
    int res[6]; //combination array
    clear_arr(arr,7); //removes dublicates
    findCombinations(arr,7,8,0,res,0);

}
