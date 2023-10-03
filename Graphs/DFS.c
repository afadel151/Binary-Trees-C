#include <stdio.h>
#include <stdlib.h>

#include "../Headers/Stack.h"

/*
 * algorithm:
 * 1. visit adjacent unvisited node, mark it visited
 * 2. display it & push in stack
 * 3. if no adjacent vertex found pop()
 * 4. goto 1
 * 5. if stack.empty() end
*/

#define MAX 100

struct stack* st;

int n;
int adj[MAX][MAX];
int state[MAX];

// function to create graph 
// ie populate the adjacency matrix
void createGraph(){
    printf("Creating a graph\n");
    int i, max_edges, origin, dest;
    printf("Enter the number of nodes in graph: ");
    scanf("%d", &n);
    // printf("%d", i);
    max_edges = n*(n-1);

	for(i = 1; i < max_edges; i++){
		printf("Enter edge %d (-1 -1 to exit): ", i);
		scanf("%d %d", &origin, &dest);

        if(origin == -1 && dest == -1)
            break;

        else if(origin < 0 || origin > n || dest < 0 || dest > n){
            printf("invalid input! retry...\n");
            i--;
        }

		else if(adj[origin][dest] == 1){
            printf("Edge already exists! retry...\n");
            i--;
        }
		else adj[origin][dest] = 1;
	} 
}

void main(){
    st = createStack(MAX);
    
    createGraph();
}
