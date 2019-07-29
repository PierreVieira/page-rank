/**
 * @file arrays.h
 * @author Nicolas Rezende (nicolasgomes0905@gmail.com)
 * @brief Biblioteca criada para lidar com a alocação e com operações em vetores.
 *
 * Com ela, é possível alocar uma matriz dinâmicamente, ordenar um vetor,
 * normalizar um vetor e buscar uma string em um vetor de strings.
 *
 * @date 2019-07-28
 */

#ifndef _ARRAYS_H_
#define _ARRAYS_H_

#include "graph.h"

/**
 * @brief Aloca uma matriz de inteiros.
 *
 * @param rows Número de linhas da matriz.
 * @param columns Número de colunas da matriz.
 * @return int** Referência para a matriz alocada.
 */
int **allocate_matrix_int(int rows, int columns);

/**
 * @brief Normaliza um vetor de float.
 *
 * @param array Vetor que será normalizado.
 * @param length Tamanho do array que será normalizado.
 */
void normalize(float *array, int length);

/**
 * @brief Encontra um vértice pelo nome em um vetor do tipo Vertex.
 *
 * @param str Nome do vértice.
 * @param vertices Vetor de vértices no qual o vértice será procurado.
 * @param number_of_vertices O tamanho do vetor de vértices.
 * @return int Índice da primeira aparição do vértice encontrado. Caso não encontre, retorna -1.
 */
int find_vertex(char *str, Vertex vertices[], int number_of_vertices);

#endif
