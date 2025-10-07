#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    double array[10];
    double result[10];
    
    
    if (argc != 2) {
        printf("Usage: %s <K>\n", argv[0]);
        return 1;
    }
    
    int K = atoi(argv[1]);
    
    
    for(int i = 0; i < 10; i++) {
        scanf("%lf", &array[i]);
    }
    
  
    for(int i = 0; i < 10; i++) {
        int new_index = (i - K) % 10;
        if (new_index < 0) {
            new_index += 10;
        }
        result[new_index] = array[i];
    }
    
    
    for(int i = 0; i < 10; i++) {
        printf("%g", result[i]);
        if (i < 9) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
