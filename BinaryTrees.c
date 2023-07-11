#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};
// Creating the tree //
struct node *create(int data){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    return n;
}
// Traversing the tree in preorder//
void preOrder_traversal(struct node *p){
    if(p!=NULL){
       printf("%d ",p->data);
       preOrder_traversal(p->left);
       preOrder_traversal(p->right); 
    }
    
}
// Traversing the postorder//
void postOrder_traversal(struct node *p){
    if(p!=NULL){                        
        postOrder_traversal(p->left);   
        postOrder_traversal(p->right);  
        printf("%d ",p->data);          
    }
}
// Traversing the tree in inorder//
void inorder_traverse(struct node *p){
    if(p!=NULL){
        inorder_traverse(p->left);
        printf("%d ",p->data);
        inorder_traverse(p->right);
    }
}
int main(){
    int c;
    struct node *p = create(3);
    struct node *p1 = create(5);
    struct node *p2 = create(7);
    struct node *p3 = create(12);
    struct node *p4 = create(45);
    struct node *p5 = create(32);
    struct node *p6 = create(21);
    struct node *p7 = create(78);
    struct node *p8 = create(56);
    struct node *p9 = create(23);
    struct node *p10 = create(67);


    p->left = p1;
    p->right = p2;

    p1->left = p3; 
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    p3->left = p7;
    p3->right = p8;

    p4->left = p9;
    p4->right = p10;

    p5->left = NULL;
    p5->right = NULL;

    p6->left = NULL; 
    p6->right = NULL;

    p7->left = NULL;
    p7->right = NULL;

    p8->left = NULL;
    p8->right = NULL;

    p9->left = NULL;
    p9->right = NULL;

    p10->left = NULL;
    p10->right = NULL;

    do{
    printf(" \nMenu Driven ");
    printf("\nEnter '1' for PreOrder Traversal.");
    printf("\nEnter '2' for PostOrder Traversal.");
    printf("\nEnter '3' for InOrder Traversal.");
    printf("\nEnter '0' for exit.\n");
    scanf("%d",&c);

    switch(c){
        case 1:preOrder_traversal(p);
               printf("\n");
               break;

        case 2:postOrder_traversal(p);
               printf("\n");
               break;

        case 3:inorder_traverse(p);
               break;
    }
    }while (c!=0);
     return 0;

}