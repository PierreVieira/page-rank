#include "arrays.h"

int find_vertex(char *str, Vertex vertices[], int number_of_vertices) {
    for (int i = 0; i < number_of_vertices; i++) {
        if (strcmp(str, vertices[i].name) == 0) {
            return i;
        }
    }

    return -1;
}

int **allocate_matrix_int(int rows, int columns) {
    int **matrix = calloc(rows, sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = calloc(columns, sizeof(int));
    }

    return matrix;
}

void normalize(float *array, int length) {
    float sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    for (int i = 0; i < length; i++) {
        array[i] /= sum;
    }
}
