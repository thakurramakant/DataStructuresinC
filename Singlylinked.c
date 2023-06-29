#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    struct node *next;
 };

//Insertion at begining/
struct node *insert_begin(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    return head;
}
// Insertion at given index//
struct node* at_index(struct node *head,int data,int index){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    while(i!=index-1){
        i++;
        p=p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;

   return head;
}
//Insertion at the end//
void at_end(struct node *head,int data){
    struct node*ptr=head;
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}
//Insertion after node//
void insert_after(struct node *head,struct node *previousnode,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=previousnode->next;
    previousnode->next=ptr;
}
//traversing the linked list//
void traverse(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("\nElements are:%d",ptr->data);
        ptr=ptr->next;
    }
}
//Counting the linked list//
void count(struct node *head){
    int count=0;
    if(head==NULL){
        printf("\nLinked List is empty.");
    }
    struct node *ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    printf("\nNumber of nodes are:%d",count);
}

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    struct node *fourth = (struct node*)malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=8;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=7;
    fourth->next=NULL;
    

    at_end(head,5);
    
    head=insert_begin(head,54);
 

    head=at_index(head,12,3);
    insert_after(head,second,45);
    traverse(head);
    count(head);
}
