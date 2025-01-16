#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL,*newnode,*current;

void display(){
    if(top==NULL){
        printf("\nThe Stack is Empty ");
    }
    else{
        printf("\n");
        current=top;
        while(current!=NULL){
            printf("%d\t",current->data);
            current=current->next;
        }
    }
}

void revdisplay(struct node *temp){
    if(temp==NULL){
        return;
    }
    revdisplay(temp->next);
    printf("%d\t",temp->data);
}

void push(){
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("\nEnter the Data: ");
    scanf("%d",&newnode->data);
    if(top==NULL){
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}

void pop(){
    if(top==NULL){
        printf("\nThe Stack is Empty ");
        return;
    }
    else{
        struct node *temp=top;
        top=top->next;
        free(temp);
        display();
    }
}
void main(){
    for(int i=0;i<5;i++)
    push();
    display();
    printf("\n");
    revdisplay(top);
    pop();
    pop();
}