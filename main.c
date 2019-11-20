/**
 * @file main.c
 * @author Nicolas Rezende (nicolasgomes0905@gmail.com)
 * @brief Possui a função principal e as funções para calcular Page Rank.
 * @date 2019-07-28
 * @note Baseado no código escrito por Mônica Karine, aluna de Eng. Computação / CEFET-MG
 */

#include "src/arrays.h"
#include "src/graph.h"
#include <stdlib.h>

/**
 * @brief Calcula o out degree (grau de saída) de cada vértice.
 *
 * Dada uma variável do tipo Graph, essa função inicializa a variável
 * out_degree das posições do vetor de vértices.
 *
 * @param graph Referência ao Grafo que terá os out degree's calculados.
 */
void getVetorOutdegree(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        int line_sum = 0;
        for (int j = 0; j < graph->size; j++) {
            line_sum += graph->adj_matrix[i][j];
        }
        graph->vertices[i].out_degree = line_sum;
    }
}

/**
 * @brief Calcula o Page Rank atual de cada vértice e coloca no vetor new_score.
 *
 * Cada vértice terá seu Page Rank calculado se os vértices do grafo já tiverem
 * valores de out degree inicializados por set_out_degree(). A posição do vértice em new_score
 * será correspondente ao vetor de vértices em graph.
 *
 * @param graph Grafo que será calculado o page rank atual.
 * @param new_score Vetor que guardará o page rank de cada vértice naquele instante.
 */
void CalculaPageRankVertice(Graph graph, float *new_score) {
    for (int vertex_index = 0; vertex_index < graph.size; vertex_index++) {
        float page_rank = 0;

        for (int line = 0; line < graph.size; line++) {
            if (graph.adj_matrix[line][vertex_index] == 1) {
                Vertex v = graph.vertices[line];
                page_rank += v.score /(float) v.out_degree;
            }
        }
        new_score[vertex_index] = (1 - DUMPING_FACTOR) + DUMPING_FACTOR * page_rank;
    }
}

/**
 * @brief Calcula o page rank dos vértices de um grafo até que um valor de tolerância seja
 * alcançado.
 *
 * Calcula-se iterativamente o page rank, em que o valor atual é armazenado na variável 'score' da
 * estrutura Vertex (Graph->vertices[i].score) e os valores seguintes são calculados por
 * evaluate_current_page_rank(). Para cada iteração, verifica-se se a soma das diferenças de page
 * rank é menor que uma tolerância. Caso seja, o page rank final fica armazenado na variável 'score'
 * de cada vértice.
 *
 * @param graph Grafo que será calculado o page rank.
 * @param tolerance Condição de parada para o cálculo iterativo do page rank.
 */
void CalculaPageRank(Graph *graph, float tolerance) {
    float *new_score = calloc(graph->size, sizeof(float));
    float diff_sum;

    do {
        CalculaPageRankVertice(*graph, new_score);
        normalize(new_score, graph->size);
        diff_sum = 0;
        for (int i = 0; i < graph->size; i++) {
            diff_sum += fabsf(new_score[i] - graph->vertices[i].score);
            graph->vertices[i].score = new_score[i];
        }

    } while (diff_sum >= tolerance);

    free(new_score);
}

int main() {
    Graph graph;
    //char file_name[] = "text_files/grafo.txt";
    char file_name[] = "text_files/brasileirao_1_turno_2017.txt";
    get_vertices(&graph, file_name);
    create_adj_matrix(&graph, file_name);

    // Step 1 - Calcular o grau de saída de cada vértice.
    getVetorOutdegree(&graph);

    // Step 2 - Calcular o page rank até que ele atinja uma mudança menor que 'tolerance'.
    float tolerance = 0.1;
    CalculaPageRank(&graph, tolerance);

    // Mostra os vértices ordenados do maior pro menor.
    //system("clear");
    system("cls");
    qsort(graph.vertices, graph.size, sizeof(Vertex), vertex_cmp_score);
    show_vertices(graph);
    destroy_graph(graph);
}