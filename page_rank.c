#include "page_rank.h"

int *get_array_out_degree(Graph graph) {
    int *out_degree = calloc(graph.size, sizeof(int));

    for (int i = 0; i < graph.size; i++) {
        int line_sum = 0;
        for (int j = 0; j < graph.size; j++) {
            line_sum += graph.adj_matrix[i][j];
        }

        out_degree[i] = line_sum;
    }

    return out_degree;
}