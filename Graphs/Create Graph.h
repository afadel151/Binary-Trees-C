#include <stdio.h>
#include <stdlib.h>

/*
 * algorithm:
 * 1. visit adjacent unvisited node, mark it visited
 * 2. display it & push in stack
 * 3. if no adjacent vertex found pop()
 * 4. goto 1
 * 5. if stack.empty() end
*/

struct Graph{
    int nodeCount;
    int **adj;
    int *visited;
};

typedef struct Graph Graph;

void adjMatrixTestCase(Graph* graph){
    int matrix[7][7] = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0}
    };

    // Initialize the adjacency matrix based on the provided matrix
    for (int i = 0; i < graph->nodeCount; ++i) {
        for (int j = 0; j < graph->nodeCount; ++j) {
            graph->adj[i][j] = matrix[i][j];
        }
    }
}

// fill data in adjacency matrix
Graph* createAdjMatrix(){
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    int max_edges, origin, destination;

    printf("Creating a adjacency matrix\n");
    printf("Enter no of nodes in graph: ");
    // scanf("%d", &graph->nodeCount);
    graph->nodeCount = 7;

    graph->adj = (int**) malloc(graph->nodeCount * sizeof(int*));
    if(graph->adj == NULL){
        printf("malloc error\n");
        return NULL;
    }
    for(int i = 0; i < graph->nodeCount; i++)
        graph->adj[i] = (int*) malloc(graph->nodeCount * sizeof(int));


    max_edges = graph->nodeCount * (graph->nodeCount - 1);
    // create matrix from user input
    // for(int i = 0; i < max_edges; i++){
    //     printf("Enter origin and destination vertex to make a edge: ");
    //     scanf("%d %d", &origin, &destination);

    //     if(origin == -1 && destination == -1)
    //         break;

    //     else if(origin < 0 || origin > graph->nodeCount || destination < 0 || destination > graph->nodeCount){
    //         printf("invalid input! retry...\n");
    //         i--;
    //     }

	// 	else if(graph->adj[origin][destination] == 1){
    //         printf("Edge already exists! retry...\n");
    //         i--;
    //     }
    //     else graph->adj[origin][destination] = 1;
    // }

    // fills the adj matrix with a test case graph
    adjMatrixTestCase(graph);
    printf("\n");
    return graph;
}

void printMatrix(Graph* graph){
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < graph->nodeCount; i++){
        for(int j = 0; j < graph->nodeCount; j++){
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}