#include <stdio.h>
#include <stdlib.h>
struct node
{
    int power;
    int coeff;
    struct node *next;
};
typedef struct node NODE;
NODE *polynomial(NODE *start)
{
    int n = 1;
    NODE *newnode, *prev;
    do
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        printf("Enter power and coeff\n");
        scanf("%d %d", &newnode->power, &newnode->coeff);
        newnode->next = NULL;
        if (start == NULL)
            start = newnode;
        else
            prev->next = newnode;
        prev = newnode;
        printf("Do you want add more terms \n");
        scanf("%d", &n);
    } while (n != 0);
    return start;
}
NODE *addition(NODE *p1, NODE *p2, NODE *res)
{
  NODE*temp=res;
    while (p1 != NULL && p2 != NULL)
    {
        NODE *newnode;
        if (p1->power == p2->power)
        {

            newnode = (NODE *)malloc(sizeof(NODE));
            newnode->next = NULL;
            newnode->coeff = p1->coeff + p2->coeff;
            newnode->power = p1->power;
            if (temp == NULL)
            {
                res = newnode;
                temp=newnode;
            }
            else
               { 
                 res->next = newnode;
                res=res->next;
               }
            p1 = p1->next;
            p2 = p2->next;
        
        }
        else if (p1->power > p2->power)
        {
            newnode = (NODE *)malloc(sizeof(NODE));
            newnode->next = NULL;
            newnode->coeff = p1->coeff;
            newnode->power = p1->power;
             if (temp == NULL)
            {
                res = newnode;
                temp=newnode;
            }
            else
               { 
                 res->next = newnode;
                res=res->next;
               }
            p1 = p1->next;
            
        }
        else if (p1->power < p2->power)
        {
            newnode = (NODE *)malloc(sizeof(NODE));
            newnode->next = NULL;
            newnode->coeff = p2->coeff;
            newnode->power = p2->power;
             if (temp == NULL)
            {
                res = newnode;
                temp=newnode;
            }
            else
               { 
                 res->next = newnode;
                res=res->next;
               }
            p2 = p2->next;
            
        }
    }
    while (p2 != NULL)
    {
        NODE *newnode;
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->next = NULL;
        newnode->coeff = p2->coeff;
        newnode->power = p2->power;
        if (temp == NULL)
            {
                res = newnode;
                temp=newnode;
            }
            else
               { 
                 res->next = newnode;
                res=res->next;
               }
        p2 = p2->next;
    }
    while (p1 != NULL)
    {
        NODE *newnode;
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->next = NULL;
        newnode->coeff = p1->coeff;
        newnode->power = p1->power;
       if (temp == NULL)
            {
                res = newnode;
                temp=newnode;
            }
            else
               { 
                 res->next = newnode;
                res=res->next;
               }    
        p1 = p1->next;
    }
    return temp;
}
void display(NODE *start)
{
    if (start == NULL)
        printf("null");
    else
    {
        int count = 1;
        printf("Expression is: ");
        while (start != NULL)
        {
            if (count != 1)
                printf(" +");
            printf(" %dx^%d", start->coeff, start->power);
            start = start->next;
            count++;
        }
    }
    printf("\n");
}


void swap(NODE *a, NODE *b) 
{ 
    int temp = a->power; 
    a->power = b->power; 
    b->power= temp; 
} 
void sort(NODE *start) 
{ 
    int swapped, i; 
    NODE *ptr1; 
    NODE *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->power < ptr1->next->power) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

int main()
{
    NODE *polynomial1 = NULL, *polynomial2 = NULL, *result = NULL;
    polynomial1 = polynomial(polynomial1);
    polynomial2 = polynomial(polynomial2);
    printf("1st ");
    display(polynomial1);
    sort(polynomial1);
    printf("Sorted 1st ");
    display(polynomial1);
     printf("2st ");
    display(polynomial2);
    sort(polynomial2);
    printf(" Sorted 2st ");
    display(polynomial2);
    result = addition(polynomial1, polynomial2, result);
     printf("Result ");
    display(result);
}