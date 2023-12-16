#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N = 10; //hash table size

typedef struct person
{
    char name[20];
    int age;
    struct person *next;
}person;

void initializeNULL(person **peopleList) 
{ 
    for (int i = 0; i < N; ++i) peopleList[i] = NULL; 
}

int hashFunc(char *name)  //hash function to convert name to an index number
{
    int sum = 0, i = 0;
    while (name[i] != '\0')
    {
        sum += name[i];
        ++i;
    }
    return sum % N;
}

int insert(person **peopleList, char *name, int age)  //function to insert new person to the list
{
    int index = hashFunc(name);
    person *new_node = (person *)malloc(sizeof(person));   //create new node

    if (new_node == NULL)   //check for memory allocation failure
    {
        printf("fail");
        return -1;
    }
    strcpy(new_node->name, name);   //copy the elements in new node
    new_node->age = age;
    new_node->next = NULL;

    if (peopleList[index] != NULL)    //if first index is not empty
    {
        new_node->next = peopleList[index]; //make new_node the new head of the list
    }
    peopleList[index] = new_node; //update head to be new_node
    return 1;
}

int isPresent(person **peopleList, char *name, int age)
{
    int index = hashFunc(name);     //get the index to be searched
    person *walker = peopleList[index];
    while (walker != NULL)
    {
        if (strcmp(walker->name, name) == 0 && walker->age == age)      //if match return 1
            return 1;        
        walker = walker->next;
    }
    // You can include this part if you want to make guesses
    /*
    walker = peopleList[index];   
    while (walker != NULL)
    {
        int range = 3;
        if (strcmp(walker->name, name) == 0)
        {
            if (walker->age > age - range && walker->age < age + range)
                printf("There is a \"%s\" with age between [%i, %i]", walker->name, (walker->age - range), (walker->age + range));
        }
        walker = walker->next;
    }
    */
    return 0;   //not found
}

int deletePerson(person **peopleList, char *name, int age)
{
    if (isPresent(peopleList, name, age))
    {
        int index = hashFunc(name);
        person *current = peopleList[index];
        person *prev = NULL;

        if (strcmp(current->name, name) == 0 && current->age == age)
        {
            peopleList[index] = current->next;
            free(current);
            return 1;
        }
        while (current != NULL)
        {
            if (strcmp(current->name, name) == 0 && current->age == age)
            {
                prev->next = current->next;
                free(current);
                return 1;
            }        
            prev = current;
            current = current->next;
        }
    }
    else
    {
        printf("There is no person named %s whos age is %i.",name, age);
        return 0;
    }
}

void printTable(person **peopleList)
{
    printf(" Name   Age\n------    -----\n");
    for (int i = 0; i < N; ++i)
    {
        person *walker = peopleList[i];
        while (walker != NULL)
        {
            printf("%s    %i\n", walker->name, walker->age);
            walker = walker->next;
        }
    }
}

int main()
{   
    person **peopleList = (person **)malloc(sizeof(person *) * N);
    
    initializeNULL(peopleList);
    
    insert(peopleList,"mali",21);
    insert(peopleList,"mahmut",32);
    insert(peopleList,"ismail",2);
    insert(peopleList,"ziya",12);
    insert(peopleList,"omar",45);
    insert(peopleList,"samuel",65);

    deletePerson(peopleList,"mali",21);
    
    printTable(peopleList);

    if (isPresent(peopleList,"mali",21))   
        printf("Yes there is.");
    else
        printf("No there is not.\n");
    
}
