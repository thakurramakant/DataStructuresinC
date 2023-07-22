#include<stdio.h>

void Arrayprint(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

void merge(int A[],int low,int high,int mid){
    int i,j,k,B[100];
    i = low;
    j = mid+1;
    k = low;

    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            k++;
            i++;
        }
        else{
            B[k]=A[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
           B[k]=A[i];
           i++;
           k++;
    }
    while(j<=high){
            B[k]=A[j];
            j++;
            k++;        
    }
    for(int i=low;i<=high;i++){
        A[i] = B[i];
    }
    
}

void mergesort(int A[],int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergesort(A,low,mid);
        mergesort(A,mid+1,high);
        merge(A,low,high,mid);
    }
}

int main(){
    int A[]={9,14,4,8,7,5,6};
    int n = 7;

    Arrayprint(A,n);
    mergesort(A,0,6);
    printf("\n");
    Arrayprint(A,n);

}