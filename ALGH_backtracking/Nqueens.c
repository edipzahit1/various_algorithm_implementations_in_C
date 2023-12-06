#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define N 7

int isSafe(char board[N][N], int row, int col);
int Nqueens(char board[N][N], int row);
void printBoard(char board[N][N]);

void printBoard(char board[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(char board[N][N], int row, int col)
{
    for (int i = 0; i < N; ++i)  //check rows
    {
        if (board[row][i] == 'Q')
            return FALSE;
    }
    for (int i = 0; i < N; ++i)  //check cols
    {
        if (board[i][col] == 'Q') 
            return FALSE;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)  //diagonal #1
    {
        if (board[i][j] == 'Q')
            return FALSE;
    }
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j)  //diagonal #2
    {
        if (board[i][j] == 'Q')
            return FALSE;
    }
    return TRUE;
}

int Nqueens(char board[N][N], int row)  //draw a stack box to get a better understanding for this recursive function.
{
    if (row == N) //if you reach the final row it means that you find a solution. 
    {
        printBoard(board); //print the solution
        return TRUE;  
    }

    int found = FALSE; 

    for (int col = 0; col < N; col++)
    {
        if (board[row][col] == '_')
        {
            if (isSafe(board, row, col))
            {
                board[row][col] = 'Q';  //place the queen
                found = Nqueens(board, row + 1) || found;  //go to next row
                board[row][col] = '_';  //backtracking
            }
        }
    }
    return found;  // if it returns true it means board is reseting itself to find new solution. // if returns false you are backtracking
}

int main()
{
    char myBoard[N][N] =
    {
        "_______",
        "_______",
        "_______",
        "_______",
        "_______",
        "_______",
        "_______"
    };
    if (Nqueens(myBoard, 0) == FALSE)
        printf("no solution");
    return 0;
}