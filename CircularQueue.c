#include<stdio.h>
# define MAX 3
int q[MAX];
int r = -1;
int f = -1;

// Insertion in circular Queue //
void Enqueue(int x){
    if(f==(r+1)%MAX){
        printf("\nQueue Overflow!!");
    }
    else if(f==r && f==-1){
        f=r=0;
        q[r]=x;
    }
    else{
        r=(r+1)%MAX;
        q[r]=x;
    }
    printf("\nElement Enqueued!!");
}

// Deletion in circular Queue //
void Dequeue(){
    if(f==-1){
        printf("\nQueue Underflow!!");
    }
    else if(f==r && f!=-1){
        printf("\n%d Element is enqueued.",q[f]);
        f=r=-1;
    }
    else{
        printf("\n%d Element is enqueued.",q[f]);
        f=(f+1)%MAX;
    }
}

// Traversing the queue //
void traverse(){
    if(f==-1 && r==-1){
        printf("\nQueue Underflow!! ");
    }
    else{
        int i=f;
        printf("\nElements are:\n");
        while(i!=r){
            printf("\n%d\t",q[i]);
            i=(i+1)%MAX;
        }
        printf("\n%d",q[r]);
    }
}

int main(){
    int c,x;

    do{
    printf("\n**Main Menu** ");
    printf("\nEnter '1' for Enqueue in queue.");
    printf("\nEnter '2' for Dequeue in queue.");
    printf("\nEnter '3' for Traversal in queue.");
    printf("\nEnter '0' for exit.\n");
    scanf("%d",&c);

    switch(c){
        case 1:printf("\nEnter the element to insert: ");
               scanf("%d",&x);
               Enqueue(x);
               break;

        case 2:Dequeue();
               break;

        case 3:traverse();
               break;
    }

    }while(c!=0);
}    
