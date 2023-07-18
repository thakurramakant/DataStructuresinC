#include<stdio.h>

void Arrayprint(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

void selection_sort(int *A,int n){
    int indexOfMin,temp;
    for(int i=0;i<n;i++){
        indexOfMin=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[indexOfMin]){
            indexOfMin=j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
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
    selection_sort(A,n);
    printf("\n");
    Arrayprint(A,n);
}