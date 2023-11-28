#include <stdio.h>
#include "../Headers/Graph.h"

void addNodeToAdjList(Graph* graph, int source, int dest){
    if(graph == NULL){
        printf("Graph not initialized\n");
        return;
    }
    struct adjNode** adjList = graph->adjList;

    // add a note
    struct adjNode* vertexPointer = adjList[source];
    // the if condition skips the loop if there are no nodes before
    if(vertexPointer != NULL){
        while(vertexPointer->next != NULL){
            vertexPointer = vertexPointer->next;
        }
        vertexPointer->next = createAdjNode(dest, NULL);
    }
    else {
        vertexPointer = createAdjNode(dest, NULL);
        adjList[source] = vertexPointer;
    }
}

Graph* createAdjList(int nodeCount){
    // create graph
    Graph* graph = (Graph*) malloc(sizeof(Graph)); 
    graph->nodeCount = nodeCount;

    // create array for adj list
    graph->adjList = (struct adjNode**) malloc(graph->nodeCount * sizeof(struct adjNode*));
    for(int i = 0; i < graph->nodeCount; i++){
        graph->adjList[i] = NULL;
    }
    return graph;
}

void printAdjList(Graph* graph){
    for(int i = 0; i < graph->nodeCount; i++){
        struct adjNode *vertexPointer = graph->adjList[i];
        printf("%d: ", i);
        while(vertexPointer != NULL){
            printf("--> %d ", vertexPointer->vertex);
            vertexPointer = vertexPointer->next;
        }
        printf("\n");
    }
}

void adjListTestCase(Graph* g){
    for (int i = 0; i < g->nodeCount; i++){
        for (int j = 0; j < g->nodeCount; j++){
            if(i != j)
                addNodeToAdjList(g, i, j);
        }
    }
    printAdjList(g);
}

void main(){
    Graph* g = createAdjList(7);

    adjListTestCase(g);    
}