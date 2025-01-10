#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
    char data[100];
    struct node *next;
};

struct node *head1 = NULL, *head2 = NULL, *head3 = NULL, *newnode, *current;

void insertEnd(struct node **head)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    printf("Enter the data: ");
    fgets(newnode->data, 100, stdin);
    if (newnode->data[strlen(newnode->data) - 1] == '\n')
    {
        newnode->data[strlen(newnode->data) - 1] = '\0';
    }
    if ((*head) == NULL)
    {
        (*head) = newnode;
    }
    else
    {
        current = (*head);
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("\nThe LL is empty!!");
        return;
    }
    else
    {
        current = head;
        while (current != NULL)
        {
            printf("%s->", current->data);
            current = current->next;
        }
    }
}

void merge(struct node *head1, struct node *head2, struct node **head3)
{
    current = head1;
    while (current != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        strcpy(newnode->data, current->data);
        if (*head3 == NULL)
        {
            *head3 = newnode;
        }
        else
        {
            struct node *temp = *head3;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        current = current->next;
    }

    current = head2;
    while (current != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        strcpy(newnode->data, current->data);
        if (*head3 == NULL)
        {
            *head3 = newnode;
        }
        else
        {
            struct node *temp = *head3;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        current = current->next;
    }
    printf("\nThe merged list is: ");
    display(*head3);
}

void countVow(struct node *head)
{
    current = head;
    while (current != NULL)
    {
        int count = 0;
        int len = strlen(current->data);
        for (int i = 0; i < len; i++)
        {
            char ch = tolower(current->data[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                count++;
            }
        }
        printf("\n%s has %d Vowels", current->data, count);
        current = current->next;
    }
}
void main()
{
    int num1, num2;
    printf("\nEnter the number of elements of LL 1: ");
    scanf("%d", &num1);
    getchar();

    for (int i = 0; i < num1; i++)
    {
        insertEnd(&head1);
    }
    display(head1);

    printf("\nEnter the number of elements of LL 2: ");
    scanf("%d", &num2);
    getchar();
    for (int i = 0; i < num2; i++)
    {
        insertEnd(&head2);
    }
    display(head2);
    // printf("\nElements of Merged LL : ");
    // merge(head1,head2,&head3);
    countVow(head1);
}
