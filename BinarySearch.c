#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};
// Creating the tree//
struct node *create(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
// Traversing the tree in preorder//
void preOrder_traversal(struct node *p){
    if(p!=NULL){
        printf(" %d",p->data);
        preOrder_traversal(p->left);
        preOrder_traversal(p->right);
    }
}
// Traversing the tree in postorder//
void postOrder_traversal(struct node *p){
    if(p!=NULL){
        preOrder_traversal(p->left);
        preOrder_traversal(p->right);
        printf(" %d",p->data);
    }
}
// Traversing the tree in inorder//
void InOrder_traversal(struct node *p){
    if(p!=NULL){
        InOrder_traversal(p->left);
        printf(" %d",p->data);
        InOrder_traversal(p->right);
    }
}

// Searching function for BST using recursion //
struct node *search(struct node*p,int key){
    if(p==NULL){
        return NULL;
    }
    if(p->data==key){
        return p;
    }
    else if (p->data > key)
    {
        return search(p->left,key);
    }
    else{
        return search(p->right,key);
    }
     
}
// Searching function for BST using Itteration//
struct node *searchitter(struct node*p,int key){
     while(p!=NULL){
        if(p->data==key){
            return p;
        }
        else if(p->data>key){
            p = p->left;
        }
        else{
            p = p->right;
        }
     }

     return NULL;
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

    InOrder_traversal(p);

    // struct node *n = search(p,45);
    struct node *n = searchitter(p,3);
    if(n!=NULL){
        printf("\nFound: %d",n->data);
    }
    else{
        printf("\nNot Found!!");
    }
}