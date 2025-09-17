#include <stdio.h>

int main() {
    int rows, cols, i, j;

    printf("Input the rows and columns of the matrix : ");
    scanf("%d %d", &rows, &cols);

    int a[rows][cols], transpose[cols][rows];

    // Input matrix
    printf("Input elements in the matrix :\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("element - [%d],[%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Calculate transpose
    // for (i = 0; i < rows; i++) {
    //     for (j = 0; j < cols; j++) {
    //         transpose[j][i] = a[i][j];
    //     }
    // }

    // Display original matrix
    printf("The matrix is :\n\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Display transpose matrix
    printf("\nThe transpose of a matrix is :\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }

    return 0;
}
