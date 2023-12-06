#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int printAllPossibleSpaces(char str[], char strS[], int i, int j);
void remSpaces(char *str);

void remSpaces(char *str) 
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] != ' ') 
        {
            str[count] = str[i];
            count++;
        }
    }
    str[count] = '\0';
}

int printAllPossibleSpaces(char str[], char strS[], int i, int j)
{
    if (j == strlen(str))
    {   
        strS[i] = '\0';
        printf("%s\n",strS);
        return 0;
    }
    
    strS[i] = str[j];
    printAllPossibleSpaces(str, strS, i + 1, j + 1);
    
    strS[i] = ' ';
    strS[i + 1] = str[j];
    printAllPossibleSpaces(str, strS, i + 2, j + 1);
}

int main()
{
    char myStr[] = "yo mama fat";
    int len = strlen(myStr);

    char *myStrS = (char *)malloc(2 * len * sizeof(char));

    myStrS[0] = myStr[0];

    remSpaces(myStr);
    printf("%s\n\n",myStr);

    printAllPossibleSpaces(myStr, myStrS, 1, 1);
}