#include "graph.h"

void set_out_degree(Graph *graph);
void set_page_rank(Graph *graph, float tolerance);

int main() {
    Graph graph;
    char file_name[] = "brasileirao_1_turno_2017.txt";

    get_vertices(&graph, file_name);
    create_adj_matrix(&graph, file_name);

    // Step 1
    set_out_degree(&graph);

    //

    destroy_graph(graph);
}

void set_out_degree(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        int line_sum = 0;
        for (int j = 0; j < graph->size; j++) {
            line_sum += graph->adj_matrix[i][j];
        }

        graph->vertices[i].out_degree = line_sum;
    }
}

void set_page_rank(Graph *graph, float tolerance) {
    float *new_score = calloc(graph->size, sizeof(float));
    float diff_sum;

    do {
        evaluate_current_page_rank(*graph, new_score);

        diff_sum = 0;

        for (int i = 0; i < graph->size; i++) {
            diff_sum = fabs(new_score[i] - graph->vertices[i].score);
            graph->vertices[i].score = new_score[i];
        }

    } while (diff_sum >= tolerance);
}
