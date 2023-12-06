#include <stdio.h>

#define M 3
#define N 3

int paths(int matrix[M][N], int path[], int i, int j);

int paths(int matrix[M][N], int path[], int i, int j)
{
    if (i == M - 1 && j == N - 1)
    {
        path[i + j] = matrix[i][j]; //change the last element 0 to bottom right corner.
        printf("Path : [");
        for (int a = 0; a < M + N - 1; ++a)
            printf("%i, ",path[a]);
        printf("\b\b]\n");
        return 0;
    }

    if (j < N - 1)
    {
        path[i + j] = matrix[i][j];
        paths(matrix, path, i, j + 1);  //right
        path[i + j] = 0;
    }    
    if (i < M - 1)
    {
        path[i + j] = matrix[i][j];
        paths(matrix, path, i + 1, j);  //down
        path[i + j] = 0;
    }
}

int main()
{
    int myMatrix[M][N] = {
        {1 ,2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int myPath[M + N - 1] = {0};
    paths(myMatrix, myPath, 0, 0); 
}