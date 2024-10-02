#include <stdio.h>
#include <stdlib.h>

typedef char *string;

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, string argv[])
{
    if (argc <= 1)
    {
        printf("Empty Linked List");
        return 1;
    }

    node *list = malloc(sizeof(node));
    if (list == NULL)
    {
        printf("Memory Allocation Failed!");
        return 1;
    }
    list->number = atoi(argv[1]);
    list->next = NULL;

    node *n1 = list;
    for (int i = 2; i < argc; i++)
    {
        node *n2 = malloc(sizeof(node));
        if (n2 == NULL)
        {
            printf("Memory Allocation Failed!");
            return 1;
        }
        int number = atoi(argv[i]);

        n1->next = n2;

        n2->number = number;
        n2->next = NULL;

        n1 = n1->next;
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
    return 0;
}
