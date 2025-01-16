#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *newnode,*front=NULL,*rear=NULL,*current;

void enqueue(){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("\nEnter the element: ");
    scanf("%d",&newnode->data);
    if(front==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    if(front==NULL){
        printf("\nThe Queue is Empty!!");
        return;
    }
    else if(rear==front){
        printf("%d Deleted",front->data);
        free(front);
        front=rear=NULL;
        return;
    }
    else{
        struct node *temp=front;
       printf("%d Deleted",front->data);
        free(temp);
        front=front->next;
    }
}

void display(){
    current=front;
    while(current!=NULL){
        printf("%d\t",current->data);
        current=current->next;
    }
}

void revdis(struct node *temp){
    if(temp==NULL)
    return;
    revdis(temp->next);
    printf("%d\t",temp->data);
}
void main(){
    dequeue();
    for(int i=0;i<5;i++){
        enqueue();
    }
    display();
    printf("\n");
    revdis(front);
}