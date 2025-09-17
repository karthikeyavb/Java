/* Progarm to create variable, pointer  variable, and display the values using %p and %x*/
// #include<stdio.h>
// int main(){
// 	int x=25;
// 	int *ptr=&x;
	
// 	printf("Value of X:%d", x);
// 	printf("\nAddress of X:%p",&x);
// 	printf("\nAddress of X(Hexadecimal):%x",&x);
// 	ptr=&x;
// 	printf("\nValue of Ptr:%p",ptr);
// 	printf("\nAddress of Ptr:%p", &ptr);
// 	printf("\nAddress of Ptr:%x", &ptr);
// 	printf("\nPTR value:%d", ptr);
// 	ptr++;
// 	printf("\nPTR value:%d", ptr);

// 	return 0;
// }

// int main(){
// int x=45,y=25;
// int *p,*q;
// p=&x;
// q=&y;
// int temp=*p;
// *p=*q;
// *q=temp;
// printf("X:%d",x);
// printf("\nY:%d",y);
// return 0;
// }


#include<stdio.h>
// int main(){
// 	float x=56.7;
// 	float*ptr;
// 	ptr=&x;
// 	printf("X:%f",x);
// 	printf("\nPtr:%x", ptr);
// 	*ptr=76.99;
// 	printf("\nx:%f",*ptr);
// 	printf("\nx:%f",x);
// }


int main(){
    int x=45;
    int *sp=&x;
    int **dp=&sp;
    printf("X value:%d",x);
    printf("\nsp:%x",sp);
    printf("\ndp:%x",dp);
    **dp++;
    printf("\nX value:%d",x);
    *sp=101;
    printf("\nX value:%d",x);
    *dp=202;
    printf("\nX value:%d",x);
   return 0; 
}
