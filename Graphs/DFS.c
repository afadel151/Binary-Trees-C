#include <stdio.h>
#include "Adjacency matrix.c"

// depth first traversal recrusive function to print traversal
void DFS(Graph* graph, int nodeIndex){
    graph->visited[nodeIndex] = 1;
    printf("%d ", nodeIndex);

    for(int connectedNode = 0; connectedNode < graph->nodeCount; connectedNode++){
        if(!graph->visited[connectedNode] && graph->adj[nodeIndex][connectedNode])
            DFS(graph, connectedNode);
    }  
}

void DFSTraversal(Graph* graph){
    printf("DFS Traversal: ");

    // calloc initilizes visited array to zero
    if(graph->visited == NULL)
        graph->visited = (int*) calloc(graph->nodeCount, sizeof(int));

    // this triggers the DFS() recursive function
    // the for loop is there if the graph is disconnected
    for(int i = 0; i < graph->nodeCount; i++){
        if(!graph->visited[i])
            DFS(graph, i);
    }
    printf("\n");
    free(graph->visited);
}

void main(){
    Graph* g = createAdjMatrix();
    printMatrix(g);

    DFSTraversal(g);
}