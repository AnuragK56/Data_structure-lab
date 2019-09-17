#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NODE;
NODE *insertstart(NODE *end)
{
    printf("Insert start\n");
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    scanf("%d", &newnode->info);
    if (end == NULL)
    {
        newnode->next = newnode;
        return newnode;
    }
    else
    {
        newnode->next = end->next;
        end->next = newnode;
    }
    return end;
}
NODE *insertend(NODE *end)
{
    printf("Insert end\n");
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    scanf("%d", &newnode->info);
    if (end == NULL)
    {
        newnode->next = newnode;
        return newnode;
    }
    newnode->next = end->next;
    end->next = newnode;
    return newnode;
}
void insertmid(NODE *end, int x)
{
    NODE *start = end->next;
    while (start != end && start->info != x)
        start = start->next;
    if (start->info == x)
    {
        NODE *newnode;
        newnode = (NODE *)malloc(sizeof(NODE));
        scanf("%d", &newnode->info);
        newnode->next = start->next;
        start->next = newnode;
    }
    else
        printf("Element not found\n");
}
void *deletestart(NODE *end)
{
    if (end == NULL)
        printf("Empty\n");
    else
    {
        printf("Deleted start \n");
        NODE *temp;
        temp = end->next;
        end->next = end->next->next;
        free(temp);
    }
}
NODE *deleteend(NODE *end)
{
    NODE *temp;
    if (end == NULL)
    {
        printf("Empty \n");
        return end;
    }
    NODE *start = end->next;
    while (start->next != end)
        start = start->next;
    start->next = end->next;
    printf("Deleted end \n");
    free(end);
    return start;
}
void deletemid(NODE *end, int x)
{
    NODE *start = end->next, *prev = end;
    while (start != end && start->info != x)
    {
        prev = start;
        start = start->next;
    }
    if (start->info == x)
    {
        prev->next = start->next;
        free(start);
    }
}
void display(NODE *end)
{
    if (end == NULL)
        printf("empty\n");
    else
    {
        NODE *start = end->next;
        do
        {
            printf("%d  ", start->info);
            start = start->next;
        } while (start->next != end->next);
        if (start->next != start)
            printf("%d  ", start->info);
    }
    printf("\n");
}
int main()
{
    NODE *start, *end = NULL;
    int n, x;
    printf("Enter option \n");
    scanf("%d", &n);
    do
    {
        switch (n)
        {
        case 1:
            end = insertstart(end);
            display(end);
            break;
        case 2:
            printf("Enter element to be searched\n");
            scanf("%d", &x);
            insertmid(end, x);
            display(end);
            break;
        case 3:
            end = insertend(end);
            display(end);
            break;
        case 4:
            deletestart(end);
            display(end);
            break;
        case 5:
            end = deleteend(end);
            display(end);
            break;
        case 6:
            printf("Enter element to be searched\n");
            scanf("%d", &x);
            deletemid(end, x);
            display(end);
            break;
        default:
            printf("Invalid\n");
            break;
        }
        if (n == 0)
            break;
        printf("Enter option \n");
        scanf("%d", &n);
    } while (n > 0);
    return 0;
}
