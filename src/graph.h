/**
 * @file graph.h
 * @author Nicolas Rezende (nicolasgomes0905@gmail.com)
 * @brief Biblioteca responsável por toda a estruturação e manipulação de um grafo.
 *
 * É capaz de obter vértices de um arquivo texto e gerar a matriz de adjacência. Além disso, define
 * os tipos "Vertex" e "Graph" para facilitar a manipulação dos dados.
 *
 * @date 2019-07-28
 */

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DUMPING_FACTOR 0.85

/**
 * @brief Utilizada para representar características de um vértice que téra o Page Rank calculado.
 */
typedef struct Vertex {
    char *name;     /**< Nome do vértice (um label). */
    float score;    /**< Valor do Page Rank do vértice. */
    int out_degree; /**< Valor inteiro para o grau de saída do vértice. */
} Vertex;

/**
 * @brief Utilizada para representar características de um vértice que téra o Page Rank Calculado.
 */
typedef struct Graph {
    int **adj_matrix; /**< Referência para uma matriz de adjacência */
    Vertex *vertices; /**< Referência para um vetor de vértices (Vertex) distintos. */
    int size;         /**< Quantidade de vértices no grafo. */
} Graph;

/**
 * @brief Abre o arquivo .txt e descobre quais são os vértices distintos.
 *
 * Inicializa o vetor 'vertices' e a variável 'size' de Graph. Ao final, 'get_vertices' ordena, pelo
 * nome, o vetor de vértices.
 *
 * @param graph Referência a uma variável do tipo Graph que terá os vértices inicializado.
 * @param file_name String com o path para o arquivo .txt.
 */
void get_vertices(Graph *graph, char *file_name);

/**
 * @brief Abre o arquivo .txt e constrói uma matriz de adjacência.
 *
 * Cada linha e coluna representa um vértice do Grafo e os índices são correspondentes ao vetor
 * 'vertices' inicializado por 'get_vertices'. Dessa maneira, se o vértice na posição 4 possui uma
 * aresta para o vértice na posição 2, então há um número 1 na quarta linha e segunda coluna da
 * matriz.
 *
 * @param graph Referência a uma variável do tipo Graph que terá a matriz de adjacência
 * inicializada.
 * @param file_name String com o path para o arquivo .txt.
 */
void create_adj_matrix(Graph *graph, char *file_name);

/**
 * @brief Função utilizada para comparar dois vértices pelo seu score (page rank).
 *
 * Retorna um valor MENOR QUE ZERO quando V1 < V2, pois essa função é utilizada para
 * ordenar em ordem DECRESCENTE os vértices.
 *
 * @param v1 Vértice 1
 * @param v2 Vértice 2
 * @return int Zero se é igual, maior que zero se V1 < V2 e menor que zero se V1 > V2.
 */
int vertex_cmp_score(const void *v1, const void *v2);

/**
 * @brief Função utilizada por qsort() para ordenar em ordem alfabética o vetor de vértices.
 *
 * @param v1 Vértice 1
 * @param v2 Vértice 2
 * @return int Retorno da função strcmp().
 */
int vertex_cmp_name(const void *v1, const void *v2);

/**
 * @brief Mostra a POSIÇÃO, NOME, GRAU DE SAÍDA e PAGE RANK de todos os vértices.
 *
 * @param graph Grafo que terá os vértices mostrados.
 */
void show_vertices(Graph graph);

/**
 * @brief Mostra a matriz de ajacência construida por create_adj_matrix().
 *
 * @param graph Grafo que terá a matriz de adjacência mostrada.
 */
void show_adj_matrix(Graph graph);

/**
 * @brief Libera toda a memória alocada associada a variável do tipo Graph.
 *
 * @param graph Grafo que será destruído.
 */
void destroy_graph(Graph graph);

#endif