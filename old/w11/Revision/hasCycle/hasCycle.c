
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Graph.h"
#include "Stack.h"

bool dfs(Graph g, int pred[], int src);

bool hasCycle(Graph g) {
	for (int src = 0; src < GraphNumVertices(g); src++) {
		int pred[GraphNumVertices(g)];
		for (int i = 0; i < GraphNumVertices(g); i++) {
			pred[i] = -1;
		}

		pred[src] = src;
		if (dfs(g, pred, src)) {
			return true;
		}
	}

	return false;
}

bool dfs(Graph g, int pred[], int src) {
	for(int v = 0; v < GraphNumVertices(g); v++) {
		if (GraphIsAdjacent(g, src, v) && pred[src] != v) {
			if (pred[v] != -1) {
				return true;
			}

			// Visit vertex v
			pred[v] = src;
			if (dfs(g, pred, v)) {
				return true;
			}
		}
	}
	return false;
}

