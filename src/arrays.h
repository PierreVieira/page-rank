// Author: Nicolas Rezende
// Date: 09/07/2019
// Baseado no código da Mônica.

// Biblioteca criada para lidar com a alocação e com operações em vetores.
// Com ela, é possível alocar uma matriz dinâmicamente, ordenar um vetor,
// normalizar um vetor e buscar uma string em um vetor de strings.

#ifndef _ARRAYS_H_
#define _ARRAYS_H_

#include "graph.h"

int **allocate_matrix_int(int rows, int columns);
void normalize(float *array, int length);
int find_vertex(char *str, Vertex vertices[], int number_of_vertices);

#endif
