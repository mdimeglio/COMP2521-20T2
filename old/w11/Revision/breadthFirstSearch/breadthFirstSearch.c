
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src) {
	int visited[GraphNumVertices(g)];
	for (int i = 0; i < GraphNumVertices(g); i++) {
		visited[i] = 0;
	}

	Queue toVisit = QueueNew();
	QueueEnqueue(toVisit, src);
	while(!QueueIsEmpty(toVisit)) {
		int u = QueueDequeue(toVisit);
		if (visited[u]) continue;

		// We are going to visit u
		printf("%d ", u);
		visited[u] = 1;
		for(int v = 0; v < GraphNumVertices(g); v++) {
			if (GraphIsAdjacent(g, u, v) && !visited[v]) {
				QueueEnqueue(toVisit, v);
			}
		}
	}
	QueueFree(toVisit);
}

