#include<stdio.h>

// Insertion of Enqueue //
void Enqueue(int *A,int *rear,int n){
    if(*rear==n-1){
        printf("\nQueue Overflow!!");
    }
    else{
        (*rear)++;
        printf("\nInsert the element: ");
        scanf("%d",&A[*rear]);
    }
}

// Deletion of Dequeue //
void Dequeue(int *A,int *front,int rear){
    if(*front==rear){
        printf("\n Queue Underflow!!");
    }
    else{
        (*front)++;
        printf("\nDeleted element is: %d",A[*front]);
    }
}

// Traversing the Queue //
void traversal(int *A,int front,int rear){
    if(front==rear){
        printf("\nQueue Underflow!!");
    }
    else{
        for(int i=front+1;i<=rear;i++){
            printf("\nElements are: %d",A[i]);
        }
    }
}

int main(){
    int n,c;
    int front = -1;
    int rear = -1;
    printf("\nEnter the no of elements to be inserted: ");
    scanf("%d",&n);

    int A[n];
     
    do{
    printf("\n**Main Menu** ");
    printf("\nEnter '1' for Enqueue in queue.");
    printf("\nEnter '2' for Dequeue in queue.");
    printf("\nEnter '3' for Traversal in queue.");
    printf("\nEnter '0' for exit.\n");
    scanf("%d",&c);

    switch(c){
        case 1:Enqueue(A,&rear,n);
               break;

        case 2:Dequeue(A,&front,rear);
               break;

        case 3:traversal(A,front,rear);
               break;
    }

    }while(c!=0);
}