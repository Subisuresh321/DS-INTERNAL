#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *newnode,*head=NULL,*current;

void insert(){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("\nEnter the data: ");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        current=head;
        while (current->next!=head)
        {
            current=current->next;
        }
        current->next=newnode;
        newnode->next=head;
    }
}

void delete(){
    if(head==NULL){
        printf("\nThe list is Empty!!!");
        return;
    }
    else if(head->next==head){
        struct node *temp=head;
        printf("\n%d deleted",temp->data);
        free(temp);
        head=NULL;
        return;
    }
    else{
         struct node *temp;
         current=head;
         while(current->next->next!=head){
            current=current->next;
         }
         temp=current->next;
         printf("\n%d deleted",temp->data);
         free(temp);
         current->next=head;
    }
}

