#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

int main() {
    Graph graph;
    char file_name[] = "brasileirao_1_turno_2017.txt";

    get_vertices(&graph, file_name);
    create_adj_matrix(&graph, file_name);

    // TODO: PAGE-RANK

    destroy_graph(graph);

    // show_vertices(graph);
    // show_adj_matrix(graph);
}