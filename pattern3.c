#include<stdio.h>
int main(){
int n;
scanf("%d",&n);
char k;
for(int i=1;i<=n;i++){
   for(int j=i;j<n;j++){
       printf("  ");
   }
    for(k='A';k<'A'+i;k++){
        printf("%c ",k);
        
    }
    for(k='A'+i-2;k>='A';k--){
        printf("%c ",k);
    }
    printf("\n");
}
return 0;
}