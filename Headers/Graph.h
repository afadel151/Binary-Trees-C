#include <stdio.h>
#include <stdlib.h>

/*
 * algorithm: DFS
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