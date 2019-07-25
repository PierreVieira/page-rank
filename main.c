#include "src/graph.h"
#include "src/arrays.h"

void set_out_degree(Graph *graph);
void set_page_rank(Graph *graph, float tolerance);

int main() {
    Graph graph;
    char file_name[] = "brasileirao_1_turno_2017.txt";

    get_vertices(&graph, file_name);
    create_adj_matrix(&graph, file_name);

    // Step 1 - Calcular o grau de saída de cada vértice.
    set_out_degree(&graph);

    // Step 2 - Calcular o page rank até que ele atinja uma mudança menor que 'tolerance'.
    float tolerance = 0.1;
    set_page_rank(&graph, tolerance);

    // Ordena o vetor em ordem decrescente em relação ao score.
    qsort(graph.vertices, graph.size, sizeof(Vertex), vertex_cmp_score);

    // Mostra os vértices.
    show_vertices(graph);

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

void evaluate_current_page_rank(Graph graph, float *new_score) {
    for (int vertex_index = 0; vertex_index < graph.size; vertex_index++) {
        // Para cada vértice descobre-se quem incide nele, percorrendo as linhas
        // da coluna 'vertex_index'
        float page_rank = 0;

        for (int line = 0; line < graph.size; line++) {
            if (graph.adj_matrix[line][vertex_index] == 1) {
                // Vértice que incide no vértice que iremos calcular o page rank.
                Vertex v = graph.vertices[line];
                page_rank += v.score / v.out_degree;
            }
        }

        new_score[vertex_index] = (1 - DUMPING_FACTOR) + DUMPING_FACTOR * page_rank;
    }
}

void set_page_rank(Graph *graph, float tolerance) {
    float *new_score = calloc(graph->size, sizeof(float));
    float diff_sum;

    do {
        evaluate_current_page_rank(*graph, new_score);

        normalize(new_score, graph->size);

        diff_sum = 0;
        for (int i = 0; i < graph->size; i++) {
            diff_sum += fabs(new_score[i] - graph->vertices[i].score);
            graph->vertices[i].score = new_score[i];
        }

    } while (diff_sum >= tolerance);

    free(new_score);
}
