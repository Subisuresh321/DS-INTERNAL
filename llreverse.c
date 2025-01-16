#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *next;
};

struct node *head=NULL,*newnode,*current;

void insertEnd(){
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    if((head)==NULL){
        (head)=newnode;
    }
    else{
        current=(head);
        while (current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newnode;
    }
}

void display(){
    if(head==NULL){
        printf("\nThe LL is empty!!");
        return;
    }
    else{
        current=head;
        while(current!=NULL){
            printf("%d->",current->data);
            current=current->next;
        }
    }
}
void llreverse(){
    struct node *prev=NULL,*temp;
    current=head;
    while(current!=NULL){
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    head=prev;
    display();

}
void main(){
    for(int i=0;i<5;i++)
    insertEnd();
    display();
    llreverse();
}