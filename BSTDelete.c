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

struct node *inOrderPredesser(struct node *p){
    p = p->left;
    while(p->right != NULL){
        p = p->right;
    }
    return p;
}

// Deletion of Binary tree //
struct node *delete(struct node *p,int value){
    struct node *iPre;
    if(p==NULL){
        return NULL;
    }

    if(p->left==NULL && p->right==NULL){
        free(p);
        return NULL;
    }

    if(value < p->data){
        p->left=delete(p->left,value);
    }

    else if(value > p->data){
        p->right=delete(p->right,value);
    }
    else{
        iPre = inOrderPredesser(p);
        p->data=iPre->data;
        p->left=delete(p->left,iPre->data);
    }

    return p;

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
    
    inOrder(p);
    delete(p,3);
    printf("\n");
    inOrder(p);
    

}