#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};
// Creating the node of the tree//
struct node *create(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->data = data;
    temp->right = NULL;
    
    return temp;
}
// Traversing of the tree//
void preOrder(struct node *p){
    if(p!=NULL){
        printf(" %d",p->data);
        preOrder(p->left);
        preOrder(p->right);
    }
}
// Traversing of the tree//
void postOrder(struct node *p){
    if(p!=NULL){
        postOrder(p->left);
        postOrder(p->right);
        printf(" %d",p->data);
    }
}
// Traversing of the tree//
void inOrder(struct node *p){
    if(p!=NULL){
        inOrder(p->left);
        printf(" %d",p->data);
        inOrder(p->right);
    }
}
// insertion in binary tree//
void insert(struct node *p,int key){
    struct node *pre = NULL;
    while(p!=NULL){
        pre = p;
        if(p->data==key){
            printf("\nInsertion cannot happen because %d,is present in BST.\n",pre->data);
            return 0;
        }
        else if(p->data>key){
            p = p->left;
        }
        else{
            p = p->right;
        }
    }
    struct node *new = create(key);
    if(pre->data==key){
        printf("\nInsertion cannot happen because %d,is present in BST.\n",pre->data);
        return 0;
    }
    else if(pre->data>key){
        pre->left = new;
    }
    else{
        pre->right = new;
    }

}
int main(){
    struct node *p = create(4);
    struct node *p1 = create(2);
    struct node *p2 = create(6);
    struct node *p3 = create(1);
    struct node *p4 = create(3);
    struct node *p5 = create(5);
    struct node *p6 = create(7);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    insert(p,5);
    inOrder(p);

}