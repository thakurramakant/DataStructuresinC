#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

// Inserting the element //
void Enqueue(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = 0;

    if(front==0 && rear==0){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear = temp;
    }
}

// Deleting the element //
void Dequeue(){
    struct node *temp;
    if(front==NULL && rear==NULL){
        printf("\nQueue Underflow!!");
        return;
    }
    else{
        temp = front;
        printf("\n%d,Element is deleted.",temp->data);
        front = front->next;
        free(temp);
    }
}

// Displaying the element //
void Display(){
    struct node *temp;
    if(front==0 && rear==0){
        printf("\nQueue Underflow!!");
    }
    else{
        temp = front;
        while(temp!=0){
        printf("\nElements are: ");
        printf("\n%d",temp->data);
        temp = temp->next;
        }
    }
}

int main(){
    int data,c;

    do{
    printf("\n**Main Menu** ");
    printf("\nEnter '1' for Enqueue in queue.");
    printf("\nEnter '2' for Dequeue in queue.");
    printf("\nEnter '3' for Traversal in queue.");
    printf("\nEnter '0' for exit.\n");
    scanf("%d",&c);

    switch(c){
        case 1:printf("\nElement the element to be inserted: ");
               scanf("%d",&data);
               Enqueue(data);
               break;

        case 2:Dequeue();
               break;

        case 3:Display();
               break;
    }

    }while(c!=0);

}