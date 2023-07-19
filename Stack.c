// Array implementation //
#include<stdio.h>

// Inserting in stack
void Push(int *A,int *top,int n){
    if(*top==n-1){
        printf("\n Stack Overflow!!! ");
    }
    else{
            (*top)++;
            printf("\nEnter the elements: ");
            scanf("%d",&A[(*top)]);
    }
}
// Deleting in stack
void PoP(int A[],int *top){
    if(*top==-1){
        printf("\n Stack Underflow!!! ");
    }
    else{
        printf("\nDeleted element is: %d",A[*top]);
        (*top)--;
    }
}

// Traversing in stack
void traversal(int A[],int top){
    if(top==-1){
        printf("\n Stack Underflow!!");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("\nElements are: %d",A[i]);
        }
    }
}

int main(){
    int n,c;
    int top=-1;
    printf("\nEnter the no of elements to be inserted: ");
    scanf("%d",&n);

    int A[n];
     
    do{
    printf("\n**Main Menu** ");
    printf("\nEnter '1' for Push in stack.");
    printf("\nEnter '2' for Pop in stack.");
    printf("\nEnter '3' for Traversal in stack.");
    printf("\nEnter '0' for exit.\n");
    scanf("%d",&c);

    switch(c){
        case 1:Push(A,&top,n);
               break;

        case 2:PoP(A,&top);
               break;

        case 3:traversal(A,top);
               break;
    }

    }while(c!=0);
}