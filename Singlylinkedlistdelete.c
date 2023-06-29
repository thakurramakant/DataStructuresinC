#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

// Deletion at beginning//
struct node *delete_at_begin(struct node *head){
     struct node *ptr=head;
     head=head->next;
     free(ptr);
     return ptr;
}
// Delection at index//
struct node *at_index(struct node *head,int index){
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
// Deleting the value//
struct node *at_value(struct node *head,int value){
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == value){
        p->next=q->next;
        free(q);
    }
    return head;
}
// Deletion at end//
struct node*delete_at_end(struct node *head){
    struct node *p=head;
    struct node *q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

void traverse(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("\nElements are:%d",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    struct node *fourth=(struct node*)malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=8;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=7;
    fourth->next=NULL;

    traverse(head);
    head=delete_at_begin(head);
    head=delete_at_end(head);
    head=at_index(head,2);
    head=at_value(head,8);
    traverse(head);
    
}