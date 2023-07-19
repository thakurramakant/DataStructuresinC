#include<stdio.h>

void Arrayprint(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

int partition(int A[],int low,int high){
    int temp;
    int pivot = A[low];
    int i = low+1;
    int j = high;
    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i<j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;

}

void Quicksort(int A[],int low,int high){
    int partitionIndex;

    if(low<high){
        partitionIndex = partition(A,low,high);
        Quicksort(A,low,partitionIndex-1);
        Quicksort(A,partitionIndex+1,high);
    }
}

int main(){
    int n;
    printf("\n No of Elements to enter: ");
    scanf("%d",&n);
    int A[n];
    
    for(int i=0;i<n;i++){
    printf("\nEnter the elements in array:\n ");
    scanf("%d",&A[i]);
    }

    Arrayprint(A,n);
    printf("\n");
    Quicksort(A,0,n-1);
    printf("\n");
    Arrayprint(A,n);
}