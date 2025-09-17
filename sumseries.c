#include<stdio.h>
#include<math.h>
int main(){
    int x;
    scanf("%d",&x);
    int n;
    scanf("%d",&n);
    double sum=1.0;
    int sign=-1.0;
    for (int i = 2; i <= 2 * (n - 1); i += 2) {
        // calculate factorial of i
        double fact = 1.0;
        for (int j = 1; j <= i; j++) {
            fact *= j;
        }

        // add term
        sum += sign * pow(x, i) / fact;

        // flip sign
        sign *= -1;
    }
    printf("Sum of the series = %.6f\n", sum);
    return 0;
}