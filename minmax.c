#include<stdio.h>
int max(int arr[],int n){
    int m=0;
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            m=arr[i];
        }
    }
    return m;
}
int min(int arr[],int n){
    int mi=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<mi){
            mi=arr[i];
        }
    }
    return mi;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int m=max(arr,n);
   int mi= min(arr,n);
    printf("%d\n",m);
    printf("%d",mi);
}