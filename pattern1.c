#include<stdio.h>
int main(){
int n;
scanf("%d",&n);
int k=1;
for(int i=1;i<=n;i++){
   for(int j=i;j<n;j++){
       printf(" ");
   }
    for(int j=1;j<=i;j++){
        printf("%d ",k);
        k++;
    }
    printf("\n");
}
return 0;
}