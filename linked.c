#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

typedef char *string;

int main(int argc, string argv[])
{
    node *list = NULL;
    if (list == NULL)
    {
        printf("Memory Allocation Failed!");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Memory Allocation Failed!");
            return 1;
        }

        int number = atoi(argv[i]);
        n->number = number;
        n->next = list;

        list = n;
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
}