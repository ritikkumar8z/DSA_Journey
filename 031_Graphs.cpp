#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 1. Graph using Adjacency Matrix (Undirected, Unweighted)
class GraphAdjMatrix {
    int V;
    vector<vector<int>> graph;

public:
    GraphAdjMatrix(int vertices) {
        V = vertices;
        graph.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << graph[i][j] << " ";
            }
            cout << "\n";
        }
    }
};


// 2. Graph using Adjacency Matrix (Directed, Weighted)
class DirectedWeightedGraphAdjMatrix {
    int V;
    vector<vector<int>> graph;

public:
    DirectedWeightedGraphAdjMatrix(int vertices) {
        V = vertices;
        graph.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight; // directed and weighted
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << graph[i][j] << " ";
            }
            cout << "\n";
        }
    }
};


// 3. Graph using Adjacency List (Undirected, Unweighted)
class GraphAdjList {
    int V;
    vector<list<int>> adj;

public:
    GraphAdjList(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (auto v : adj[i]) {
                cout << v << " ";
            }
            cout << "\n";
        }
    }
};


// Example usage
int main() {
    cout << "Undirected Unweighted Graph using Adjacency Matrix:\n";
    GraphAdjMatrix g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.printGraph();

    cout << "\nDirected Weighted Graph using Adjacency Matrix:\n";
    DirectedWeightedGraphAdjMatrix g2(3);
    g2.addEdge(0, 1, 5);
    g2.addEdge(1, 2, 3);
    g2.addEdge(2, 0, 1);
    g2.printGraph();

    cout << "\nUndirected Unweighted Graph using Adjacency List:\n";
    GraphAdjList g3(4);
    g3.addEdge(0, 1);
    g3.addEdge(0, 2);
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    g3.printGraph();

    return 0;
}
