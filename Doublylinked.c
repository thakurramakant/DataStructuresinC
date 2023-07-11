#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *pre;
    int data;
    struct node *next;
};

// traversing a linked list//
void traverse(struct node *head){
    struct node *ptr=head;
    if(head==NULL){
        printf("\nList is empty.");
    }
    while(ptr!=NULL){
        printf("\nElements are:%d",ptr->data);
        ptr=ptr->next;
    }
}

// Adding an element to an empty list//
struct node * addtoempty(struct node *head,int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->pre=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;

    return head;
}

// Inserting at the beginning//
struct node * addtobegin(struct node *head,int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->pre=NULL;
    temp->data=data;
    temp->next=head;
    head->pre=temp;
    head=temp;

    return head;
}

// Inserting after the value //
struct node * addtovalue(struct node *head,int data,int value){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr=head;
    if(ptr==NULL){
        printf("\nList is empty.");
    }
    while(ptr->data!=value){
        ptr=ptr->next;
    }
    temp->data=data;
    temp->next=ptr->next;
    temp->pre=ptr;
    ptr->next->pre=temp;
    ptr->next=temp;

    return head;
}

// Inserting at the end//
struct node * addtoend(struct node * head,int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    temp->next=NULL;
    temp->data=data;
    temp->pre=ptr;
    ptr->next=temp;

    return head;

}
// Creating a linked list//

struct node * create(struct node *head){
    int i,n,data;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    head=NULL;
    if(n==0){
        return head;
    }
    printf("\nEnter the elements to be inserted: ");
    scanf("%d",&data);
    head=addtoempty(head,data);
    for(i=2;i<=n;i++){
        printf("Enter the elements to be inserted: ");
        scanf("%d",&data);
        head=addtoend(head,data);
    }
    return head;

}
int main(){
    struct node *head =NULL;
    
    int c,data,value;
    do{

    printf(" \nMain Menu ");
    printf("\nPress '1' for traversing.");
    printf("\nPress '2' for addelement to empty list.");
    printf("\nPress '3' for insert element to start.");
    printf("\nPress '4' for insert element to last.");
    printf("\nPress '5' for insert element to at given value.");
    printf("\nPress '0' to exit.\n");
    scanf("%d",&c);

    switch(c){
        case 1:traverse(head);
               break;

        case 2:head=create(head);
               break;

        case 3:printf("\nEnter the data to be inserted: ");
               scanf("%d",&data);
               head=addtobegin(head,data);
               break;

        case 4:printf("\nEnter the data to be inserted: ");
               scanf("%d",&data);
               head=addtoend(head,data);
               break;

        case 5:printf("\nEnter the data to be inserted: ");
               scanf("%d",&data);
               printf("\nEnter the value after the number to be added.");
               scanf("%d",&value);
               head=addtovalue(head,data,value);
               break;

    }
  }while(c!=0);
}