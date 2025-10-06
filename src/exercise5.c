#include <stdio.h>

int main() {
    double matrix1[10][3];  
    double matrix2[3][10];  
    double result[10][10];  
    
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }
    
   
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 10; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }
    
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            result[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%g", result[i][j]);
            if (i < 9 || j < 9) {
                printf(" ");
            }
        }
    }
    printf("\n");
    
    return 0;
}
