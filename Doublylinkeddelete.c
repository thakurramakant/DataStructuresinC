#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *pre;
    int data;
    struct node *next;
};
struct node *head;

// Traversing the list //
void traverse(struct node * head){
    struct node *ptr=head;
    if(ptr==NULL){
        printf("\nList is empty.");
    }
    while(ptr!=NULL){
        printf("\nElements are:%d",ptr->data);
        ptr=ptr->next;
    }
}

// Add to empty list//
struct node *addtoempty(struct node *head,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->pre=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;

    return head;
}

// insert at the end//
struct node *addtoend(struct node *head,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr=head;
    if(ptr==NULL){
        printf("List is empty.");
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    temp->next=NULL;
    temp->data=data;
    temp->pre=ptr;
    ptr->next=temp;

    return head;

}

// Deleting at the begining//
struct node *atthebegin(struct node *head){
    struct node *ptr=head;
    if(head==NULL){
        printf("\nList is empty.");
    }
    head=head->next;
    head->pre=NULL;
    free(ptr);
    return head;
    
}

// Deleting node at the last //
struct node *atend(struct node *head){
      struct node *ptr,*p;
      if(head==NULL){
        printf("\nList is empty.");
      }
      ptr=head;
      p=head->next;
      while(p->next!=NULL){
         ptr=ptr->next;
         p=p->next;
      }
      ptr->next=NULL;
      free(p);

      return head;
}
// Deleting at after value //
struct node *atvalue(struct node *head,int value){
      struct node *ptr,*p;
      ptr=head;
      p=head->next;
      if(ptr==NULL){
        printf("\nList is empty.");
      }
      while(ptr->data!=value){
         ptr=ptr->next;
         p=p->next;
      }
      ptr->next=NULL;
      free(p);

      return head;

}
// Creating the list //
struct node *create(struct node *head){
    int n,data,i;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    head=NULL;
    if(n==0){
        printf("\nList is empty.");
    }
    printf("\nEnter the elements to be inserted: ");
    scanf("%d",&data);
    head=addtoempty(head,data);
    for(i=2;i<=n;i++){
        printf("\nEnter the elements to be inserted: ");
        scanf("%d",&data);
        head=addtoend(head,data);
    }
    return head;
}

int main(){
    int c,value;
    do{
    printf("\n Main Menu ");
    printf("\nEnter '1' for creating list.");
    printf("\nEnter '2' for traversing the list.");
    printf("\nEnter '3' for deleting an element at begin.");
    printf("\nEnter '4' for deleting an element at end.");
    printf("\nEnter '5' for deleting an element at value.");
    printf("\nEnter '0' for exit.\n");
    scanf("%d",&c);

    switch(c){
        case 1:head=create(head);
               break;

        case 2:traverse(head);
               break;
            
        case 3:head=atthebegin(head);
               break; 

        case 4:head=atend(head);
               break;

        case 5:printf("\nEnter the value:");
               scanf("%d",&value);
               head=atvalue(head,value);
               break;
    }
    }while(c!=0);
}