#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *dynamicArray = (char *)malloc(5 * sizeof(char));  
    strcpy(dynamicArray, "inno");
    printf("Dynamic array: %s\n", dynamicArray);
    dynamicArray = (char *)realloc(dynamicArray, 10 * sizeof(char)); 
    strcpy(dynamicArray, "innopolis");
    printf("Resized dynamic array: %s\n", dynamicArray);

    free(dynamicArray);

    size_t floatArraySize = 4;
    float *m = (float *)malloc(floatArraySize * sizeof(float));
    m[0] = 0.25f;
    m[1] = 0.5f;
    m[2] = 0.75f;
    m[3] = 1.0f;

    float *p = m;
    printf("Size of array m: %zu bytes\n", floatArraySize * sizeof(float));
    printf("Size of pointer p: %zu bytes\n", sizeof(p));
    printf("Size of pointer to char: %zu bytes\n", sizeof(char *));
    printf("Size of pointer to float: %zu bytes\n", sizeof(float *));
    
    size_t rows = 3, cols = 3;
    int **n = (int **)malloc(rows * sizeof(int *));
    for (size_t i = 0; i < rows; i++) {
        n[i] = (int *)malloc(cols * sizeof(int));
    }

    int value = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            n[i][j] = value++;
        }
    }
    
    printf("2D array n (3x3):\n");
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%d ", n[i][j]);
        }
        printf("\n");
    }

    size_t newRows = 2, newCols = 4;
    float **m2 = (float **)malloc(newRows * sizeof(float *));
    for (size_t i = 0; i < newRows; i++) {
        m2[i] = (float *)malloc(newCols * sizeof(float));
    }

    for (size_t i = 0; i < newRows; i++) {
        for (size_t j = 0; j < newCols; j++) {
            m2[i][j] = m[j % floatArraySize];
        }
    }

    printf("2D array m2 (2x4):\n");
    for (size_t i = 0; i < newRows; i++) {
        for (size_t j = 0; j < newCols; j++) {
            printf("%.2f ", m2[i][j]);
        }
        printf("\n");
    }

    for (size_t i = 0; i < rows; i++) {
        free(n[i]);
    }
    free(n);

    for (size_t i = 0; i < newRows; i++) {
        free(m2[i]);
    }
    free(m2);
    free(m);

    return 0;
}
