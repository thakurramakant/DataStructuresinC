#include<stdio.h>

void Arrayprint(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

void insertion_sort(int A[],int n){
    int key,j;
    for(int i=1;i<=n-1;i++){
       key = A[i];
       j = i-1;
       while(j>=0 && A[j]>key){
        A[j+1]=A[j];
        j--;
       }
       A[j+1]=key;
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
    insertion_sort(A,n);
    printf("\n");
    Arrayprint(A,n);
}