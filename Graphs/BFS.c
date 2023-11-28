#include <stdio.h>
#include "Adjacency matrix.c"
#include "../Headers/Queue.h"

void BFS(Graph *graph){
    printf("BFS Traversal: ");

    if(graph->visited == NULL){
        graph->visited = (int*) calloc(graph->nodeCount, sizeof(int));
    }

    struct Queue* queue = createQueue();
    enQueue(queue, 0);
    graph->visited[0] = 1;

    while(queue->front != NULL){
        // 1. get a vertex from queue
        int vertex = deQueue(queue);

        // 2. print it
        printf("%d ", vertex);

        // 4. push adjacent vertices and mark as visited
        for (int i = 0; i < graph->nodeCount; i++){
            if(!graph->visited[i] && graph->adj[vertex][i]){
                enQueue(queue, i);
                graph->visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void main(){
    Graph* g = createAdjMatrix();
    printMatrix(g);
    BFS(g);
}