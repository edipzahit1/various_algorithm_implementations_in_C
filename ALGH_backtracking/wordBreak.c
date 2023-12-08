#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isWord(char *currWord);
void searchingWord(char *sentence, int len, char *result, int index);
int* pushWord(char **str, char *word);
int popWord(char **str, int n);

typedef struct entry
{
    char word[10];
}entry;

entry dictionary[15] = 
{
    "i","like","sam","sung","samsung","mobile","ice",
    "and","cream","icecream","man","go","mango"
};

int isWord(char *currWord)
{
    int j;
    for (int i = 0 ; i < 15; ++i)
    {
        j = 0;
        while (currWord[j] != '\0' && dictionary[i].word[j] != '\0')
        {
            if (currWord[j] != dictionary[i].word[j])
            {
                break;
            }
            ++j;
        }
        if (currWord[j] != '\0' && dictionary[i].word[j] != '\0')
        {
            return 1;
        }
    }
    return 0;
}

void searchingWord(char *sentence, int len, char *result, int index)
{
    
}

int main()
{
    char *str = (char *)malloc(sizeof(char)), *result;
    
    if (str == NULL) return 1;
    
    str[0] = '\0';

    pushWord(&str, "ilikesamsungmobile");
    searchingWord(str, strlen(str), result, 0);
}

//Functions that i thought i could use implementing this but
//turns out i didnt need them so let them stay here.
int* pushWord(char **str, char *word) //concentanates 2 strings together with memory reallocation.
{
    int length = strlen(*str) + strlen(word);
    *str = (char *)realloc(*str, length + 1);

    if (*str == NULL) return NULL;

    strcat(*str, word);
}

int popWord(char **str, int n) //pops the last n element from a string
{
    int len = strlen(*str);

    if (n >= len) (*str)[0] = '\0';
    else (*str)[len - n] = '\0';
}