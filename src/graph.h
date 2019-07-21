// Author: Nicolas Rezende
// Date: 09/07/2019
// Baseado no código da Mônica.

// Biblioteca responsável por toda a estruturação do grafo. É capaz de obter
// vértices de um arquivo texto e gerar a matriz de adjacência. Além disso,
// define os tipos "Vertex" e "Graph" para facilitar a manipulação dos dados.

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void get_vertices(Graph *graph, char *file_name);
void create_adj_matrix(Graph *graph, char *file_name);
int vertex_cmp_score(const void *v1, const void *v2);
int vertex_cmp_name(const void *v1, const void *v2);
void show_vertices(Graph graph);
void show_adj_matrix(Graph graph);
void show_top_page_rank(Graph *graph, int n_vertex);
void destroy_graph(Graph graph);

#endif