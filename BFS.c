#include<stdio.h>
#include<stdlib.h>

struct queue{
      int f;
      int r;
      int size;
      int *arr;
};

int isfull(struct queue *q){
     if(q->r==q->size-1){
        return 1;
     }

     return 0;
}

int isempty(struct queue *q){
     if(q->r==q->f){
        return 1;
     }

     return 0;
}



void enqueue(struct queue *q,int value){
     if(isfull(q)){
        printf("\n Queue is full!!");
     }
     else{
        q->r++;
        q->arr[q->r]=value;
     }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isempty(q)){
        printf("\nQueue overflow!!");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }

    return a;

}

void traversal(struct queue *q){
    if(q->f==q->r){
        printf("\nQueue Underflow!!");
    }
    else{
        for(int i=q->f+1;i<=q->r;i++){
            printf("\nElements are: %d",q->arr[i]);
        }
    }
}

int main(){
    struct queue q;
    q.size = 100;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size*sizeof(int ));

// Graph //
int node;
int i = 0;
int visited[7]={0,0,0,0,0,0,0};

int a[7][7] = {
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0},
    
};

printf(" %d",i);
visited[i] = 1;
enqueue(&q,i);

while(!isempty(&q)){

    int node = dequeue(&q);
    for(int j=0; j<7; j++){
        if(a[node][j]==1 && visited[j]==0 ){
             printf(" %d",j);
             visited[j]=1;
             enqueue(&q,j);
        }
    }
}


}