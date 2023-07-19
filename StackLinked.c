#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *top = 0;

// Inserting in list //
void Push(int data){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = top;
    top = temp;
}

// Deleting the element //
void Pop(){
    struct node *temp;
    temp=top;
    if(top==0){
        printf("\nStack Underflow!!");
    }
    else{
        printf("%d,Element is Deleted.",top->data);
        top = top->next;
        free(temp);
    }
}

// Displaying the list //
void display(){
    struct node *temp;
    temp = top;
    if(top==0){
        printf("\nStack Underflow!!");
    }
    else{
        while(temp!=0){
            printf("\nElements are: %d",temp->data);
            temp = temp->next;
        }
    }
}


int main(){
    int c,data;
     
    do{
    printf("\n**Main Menu** ");
    printf("\nEnter '1' for Push in stack.");
    printf("\nEnter '2' for Pop in stack.");
    printf("\nEnter '3' for Traversal in stack.");
    printf("\nEnter '0' for exit.\n");
    scanf("%d",&c);

    switch(c){
        case 1:printf("\nElement the element to be inserted: ");
               scanf("%d",&data);
               Push(data);
               break;

        case 2:Pop();
               break;

        case 3:display();
               break;
    }

    }while(c!=0);
}
