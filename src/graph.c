#include "graph.h"
#include "arrays.h"

#define LINE_LENGTH 80

int vertex_cmp_score(const void *v1, const void *v2) {
    Vertex *vertex1 = (Vertex *) v1;
    Vertex *vertex2 = (Vertex *) v2;

    if (vertex1->score == vertex2->score) {
        return 0;
    } else if (vertex1->score > vertex2->score) {
        return -1;
    } else {
        return 1;
    }
}

// Função utilizada para comparar dois vértices por meio dos nomes.
int vertex_cmp_name(const void *v1, const void *v2) {
    // O retorno será utilizado por qsort que exige ponteiros para void no cabeçalho da função
    // de comparação. Para acessar o campo 'name' é necessário, então, um casting.
    return strcmp(((Vertex *)v1)->name, ((Vertex *)v2)->name);
}

void get_vertices(Graph *graph, char *file_name) {
    FILE *pFile = fopen(file_name, "r");
    assert(pFile != NULL);

    char line[LINE_LENGTH]; // Vetor para guardar uma linha lida do arquivo
    char *words_in_line[2]; // Vetor que guarda referências de cada palavra na linha

    // O objetivo é ler todos os nomes DISTINTOS do arquivo e cada nome será atribuido
    // a um 'Vertex' no vetor de vértices 'graph->vertices'.

    graph->vertices = NULL;
    graph->size = 0;

    // Cada linha será lida, até que fgets indique EOF (retornar NULL)
    while (fgets(line, LINE_LENGTH, pFile) != NULL) {
        // Como cada linha sempre tem duas palavras separadas por vírgula, pode-se
        // separar a linha lida do arquivo manualmente.
        words_in_line[0] = strtok(line, ",\n");
        words_in_line[1] = strtok(NULL, ",\n");

        // Para cada palavra na linha, verifica-se se ela já existe por meio da função
        // find_vertex(). Veja arrays.h.
        for (int i = 0; i < 2; i++) {
            int index_in_list = find_vertex(words_in_line[i], graph->vertices, graph->size);

            // Se find_str() retornar -1, então a palavra não existe na lista e pode ser colocada.
            if (index_in_list == -1) {
                // É alocado um novo espaço pra um vértice.
                graph->vertices = realloc(graph->vertices, ++(graph->size) * sizeof(Vertex));

                // Descobre-se o tamanho do nome do vértice que será guardado.
                int word_size = strlen(words_in_line[i]);

                // Aloca-se espaço para copiar a palavra na string 'name'.
                graph->vertices[graph->size - 1].name = (char *)malloc(word_size + 1);
                assert(graph->vertices[graph->size - 1].name != NULL);

                // Copia-se a palavra de 'word_in_line' para a variável 'name'.
                strcpy(graph->vertices[graph->size - 1].name, words_in_line[i]);

                // Inicializa todos os vértices com um page rank base.
                graph->vertices[graph->size - 1].score = 1 - DUMPING_FACTOR;
            }
        }
    }

    // Por fim, ordena-se utilizando Quick Sort o vetor de Vértices.
    qsort(graph->vertices, graph->size, sizeof(Vertex), vertex_cmp_name);

    fclose(pFile);
}

void create_adj_matrix(Graph *graph, char *file_name) {
    FILE *pFile = fopen(file_name, "r");
    assert(pFile != NULL);

    char line[LINE_LENGTH]; // Vetor para guardar uma linha lida do arquivo
    char *words_in_line[2]; // Vetor que guarda referências de cada palavra na linha

    // Aloca-se a matriz de adjacência usando allocate_matrix_int() de arrays.h
    graph->adj_matrix = allocate_matrix_int(graph->size, graph->size);

    while (fgets(line, LINE_LENGTH, pFile) != NULL) {
        // Como cada linha sempre tem duas palavras separadas por vírgula, pode-se
        // separar a linha lida do arquivo manualmente.
        words_in_line[0] = strtok(line, ",\n");
        words_in_line[1] = strtok(NULL, ",\n");

        // Encontra-se os índices dos vértices associados as palavras da linha.
        int index_word0 = find_vertex(words_in_line[0], graph->vertices, graph->size);
        int index_word1 = find_vertex(words_in_line[1], graph->vertices, graph->size);

        // Associaremos o índice da primeira palavra com a linha da matriz.
        int line = index_word0;

        // E a segunda palavra com a coluna
        int column = index_word1;

        // Então, criaremos uma adjacência na posição (line, column)
        graph->adj_matrix[line][column] = 1;
    }

    fclose(pFile);
}

void show_vertices(Graph graph) {
    for (int i = 0; i < graph.size; i++) {
        Vertex v = graph.vertices[i];
        printf("%2d → %-20s\tOUT: %2d\t\tPR: %f\n", i + 1, v.name, v.out_degree, v.score);
    }

    putchar('\n');
}

void show_adj_matrix(Graph graph) {
    puts("---------------------------------------");
    printf("→ Matriz de Adjacência %dx%d\n", graph.size, graph.size);
    puts("---------------------------------------");
    for (int i = 0; i < graph.size; i++) {
        for (int j = 0; j < graph.size; j++) {
            printf("%d ", graph.adj_matrix[i][j]);
        }
        putchar('\n');
    }
    puts("---------------------------------------");
}

void destroy_graph(Graph graph) {
    for (int i = 0; i < graph.size; i++) {
        free(graph.vertices[i].name);
        free(graph.adj_matrix[i]);
    }

    free(graph.vertices);
    free(graph.adj_matrix);
}