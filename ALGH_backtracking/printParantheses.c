#include <stdio.h>
#include <stdlib.h>

#define n 3 //change the number of parantheses

void printPar(char *paranthese);
int paranth(char *parantheses, int openCount, int closeCount, int i);

int paranth(char *parantheses, int openCount, int closeCount, int i)  //recursive function to print all combinations
{
    if (i == 2 * n )  //print if reached end
    {
        parantheses[i] = '\0';  //terminate null char at the end
        printf("%s\n",parantheses);
        return 0;
    }

    if (closeCount < openCount)  //print ) until close count reaches open count
    {
        parantheses[i] = ')';
        paranth(parantheses, openCount, closeCount + 1, i + 1); //increment close count and string index
    }

    if (openCount < n) //if open count reaches n it means we are done printing open parantheses
    {
        parantheses[i] = '(';
        paranth(parantheses, openCount + 1, closeCount, i + 1); //increment open count and string index
    }
}

void printPar(char *paranthese)
{
    paranth(paranthese, 0, 0, 0);
}

int main()
{
    char *par;

    par = (char *)malloc(2 * n * sizeof(char));

    printPar(par);

    free(par);
}