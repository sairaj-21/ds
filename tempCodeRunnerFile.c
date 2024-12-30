#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
void main()
{
    int ch, n, i;
    h = NULL;
    temp = tail = NULL;
    printf("-----------------MENU--------------------\n");
    printf("\n 1 - Create a DLL of n emp");
    printf("\n 2 - Display from beginning");
    printf("\n 3 - Insert at end");
    printf("\n 4 - Delete at end");
    printf("\n 5 - Insert at beg");
    printf("\n 6 - Delete at beg");
    printf("\n 7 - Exit\n");
    printf("------------------------------------------\n");
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter no of employees : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insertend();
            break;
        case 2:
            displaybeg();
            break;
        case 3:
            insertend();
            break;
        case 4:
            deleteend();
            break;
        case 5:
            insertbeg();
            break;
        case 6:
            deletebeg();
            break;
        case 7:
            exit(0);
        default:
            printf("wrong choice\n");
        }
    }
}
struct node
{
    struct node *prev;
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node *next;
} *h, *temp, *temp1, *temp2, *tail;
void create()
{
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter ssn,name,department, designation, salary and phno of employee : ");
    scanf("%d %s %s %s %f %d", &ssn, name, dept, desg, &sal, &phno);
    temp->ssn = ssn;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    temp->phno = phno;
    count++;
}
void insertbeg()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}
void insertend()
{
    if (h == NULL)
    {
        create();
        h = temp;
        tail = h;
    }
    else
    {
        create();
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void displaybeg()
{
    temp2 = h;
    if (temp2 == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("\n Linked list elements from begining : \n");
    while (temp2 != NULL)
    {
        printf("%d %s %s %s %f %d\n", temp2->ssn, temp2->name, temp2->dept,
               temp2->desg, temp2->sal, temp2->phno);
        temp2 = temp2->next;
    }
    printf(" No of employees = %d ", count);
}
int deleteend()
{
    struct node *temp;
    temp = h;
    if (temp->next == NULL)
    {
        free(temp);
        h = NULL;
        return 0;
    }
    else
    {
        temp2 = tail;
        tail = tail->prev;
        tail->next = NULL;
        printf("%d %s %s %s %f %d\n", tail->ssn, tail->name, tail->dept,
               tail->desg, tail->sal, tail->phno);
        free(temp2);
    }
    count--;
    return 0;
}
int deletebeg()
{
    struct node *temp;
    temp = h;
    if (temp->next == NULL)
    {
        free(temp);
        h = NULL;
    }
    else
    {
        h = h->next;
        printf("%d %s %s %s %f %d", temp->ssn, temp->name, temp->dept,
               temp->desg, temp->sal, temp->phno);
        free(temp);
    }
    count--;
    return 0;
}