//print all combinations of k from 1 to n//
#include <stdio.h>
#include <stdlib.h>

int printComb(int *comb, int i, int j, int k, int n);
int comb(int *comb);

int printComb(int *comb, int i, int j, int k, int n)  //function to print all combinations of k from 1 to n.
{
    if (i == k) //print if number of elements reached k
    {
        for (int a = 0; a < k; ++a)
        {
            printf("%i ",comb[a]);
        }
        printf("\n");
        return 0;
    }

    if (j > n)  //return if value of element exceeds n
        return 0;

    comb[i] = j;    //put value

    printComb(comb, i + 1, j + 1, k, n);    //increment the value and the index

    printComb(comb, i, j + 1, k, n);    //increment the value but not index //backtrack

}

int comb(int *comb) //can be modified to check if n < k 
{
    int k, n;
    printf("Enter the values: (n and k)\n");
    scanf("%i%i", &n, &k);

    comb = (int *)malloc(k * sizeof(int));

    printComb(comb, 0, 1, k, n);
}

int main()
{
    int *myComb;

    comb(myComb);

    free(myComb);
}