// * Author: Nicolas Rezende
// * Date: 09/07/2019
// * Baseado no código da Mônica.

// * Biblioteca responsável por toda a estruturação do grafo. É capaz de obter
// * vértices de um arquivo texto e gerar a matriz de adjacência. Além disso,
// * define os tipos "Vertex" e "Graph" para facilitar a manipulação dos dados.

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DUMPING_FACTOR 0.85

typedef struct Vertex {
    char *name;
    float score;
    int out_degree;
} Vertex;

typedef struct Graph {
    int **adj_matrix;
    Vertex *vertices;
    int size;
} Graph;

// Abre o arquivo .txt e descobre quais são os vértices distintos. Inicializa o vetor 'vertices' e a
// variável 'size' de Graph. Ao final, 'get_vertices' ordena, pelo nome, o vetor de vértices.
void get_vertices(Graph *graph, char *file_name);

// Abre o arquivo .txt e constrói uma matriz de adjacência. Cada linha e coluna representa um
// vértice do Grafo e os índices são correspondentes ao vetor 'vertices' inicializado por
// 'get_vertices'. Dessa maneira, se o vértice na posição 4 possui uma aresta para o vértice na
// posição 2, então há um número 1 na quarta linha e segunda coluna da matriz
void create_adj_matrix(Graph *graph, char *file_name);

// Função utilizada para comparar dois vértices pelo seu score (page rank). É utilizada por qsort()
// para ordenar em ordem decrescente o vetor de vértices.
int vertex_cmp_score(const void *v1, const void *v2);

// Função utilizada por qsort() para ordenar em ordem alfabética o vetor de vértices.
int vertex_cmp_name(const void *v1, const void *v2);

// Mostra TODOS os vértices do grafo. As informações mostradas são POSIÇÃO, NOME, GRAU DE SAÍDA e
// PAGE RANK.
void show_vertices(Graph graph);

// Mostra a matriz de ajacência construida por create_adj_matrix().
void show_adj_matrix(Graph graph);

// Libera todo os espaço alocado em uma variável do tipo Graph.
void destroy_graph(Graph graph);

#endif
