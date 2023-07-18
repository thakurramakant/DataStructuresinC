#include<stdio.h>

void Arrayprint(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

void bubble_sort(int A[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
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
    bubble_sort(A,n);
    printf("\n");
    Arrayprint(A,n);
}