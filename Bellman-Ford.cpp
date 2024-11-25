#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

void bellmanFord(int vertices, int edges, vector<Edge>& edgeList, int source) {
    // Step 1: Initialize distances from source to all vertices as infinity
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 0; i < vertices - 1; ++i) {
        for (const auto& edge : edgeList) {
            if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.dest]) {
                distance[edge.dest] = distance[edge.src] + edge.weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (const auto& edge : edgeList) {
        if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.dest]) {
            cout << "Graph contains a negative-weight cycle\n";
            return;
        }
    }

    // Print the distances from source
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < vertices; ++i) {
        if (distance[i] == INT_MAX) 
            cout << i << "\tInfinity\n";
        else 
            cout << i << "\t" << distance[i] << "\n";
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<Edge> edgeList(edges);
    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < edges; ++i) {
        cin >> edgeList[i].src >> edgeList[i].dest >> edgeList[i].weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(vertices, edges, edgeList, source);

    return 0;
}
