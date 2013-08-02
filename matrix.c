#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int**  initialise_matrix ( int **matrix, int size) {
      int i;
      matrix = calloc(size, sizeof(int *));
      for (i = 0; i < size; i++)
          matrix[i] = calloc(size, sizeof(int));
      return matrix;
}

void destroy_matrix (int **matrix, int size) {
    int i;
    for (i = 0; i < size; i++)
        free(matrix[i]);
    
    free(matrix);
}

void print_matrix(int **matrix, int size) {
    int i,j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
