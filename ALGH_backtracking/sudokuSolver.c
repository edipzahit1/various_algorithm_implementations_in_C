//Sudoku Solver Using Backtracking//

#include <stdio.h>
#include <stdbool.h>

bool isValid(char board[9][9], int row, int col, char c);
bool solveSudoku(char board[9][9], int row, int col);

bool isValid(char board[9][9], int row, int col, char c)
{
    for (int i = 0; i < 9; i++)     //check rows
        if(board[i][col] == c)
            return false;   
    
    for (int i = 0; i < 9; i++)     //check cols
        if(board[row][i] == c)
            return false;
    
    row = (row / 3) * 3;    //assign correct values before checking box
    col = (col / 3) * 3;

    for (int j = row; j < row + 3; ++j)    // check box
    {
        for (int i = col; i < col + 3; ++i)
        {
            if (board[j][i] == c)
                return false;
        }
    }
    return true;
}

bool solveSudoku(char board[9][9], int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; ++c)
                {
                    if (isValid(board,i,j,c))
                    {
                        board[i][j] = c;
                        if (solveSudoku(board, i, j + 1)) //put the number and then go to next box
                        {
                            return true;  //point #1 //return to main.. puzzle completed.
                        }
                        board[i][j] = '.'; //if you cant place the next number in next box go back and change the previous box to '.'
                    }
                }
                return false;  //return false if you cant place the number
            }
        }
    }
    return true; //to indicate and return true to point #1
}

int main()
{
    char board[9][9] = 
    {
    "53..7....",
    "6..195...",
    ".98....6.",
    "8...6...3",
    "4..8.3..1",
    "7...2...6",
    ".6....28.",
    "...419..5",
    "....8..79"
    };

    solveSudoku(board, 0, 0);

    for(int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}