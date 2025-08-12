#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Graph {
    int size;
    vector<vector<int>> adj_matrix;
    vector<string> vertex_data;

    // Helper DFS function for cycle detection
    bool dfs_util(int v, vector<bool>& visited, int parent) {
        visited[v] = true;
        for (int i = 0; i < size; i++) {
            if (adj_matrix[v][i] == 1) {
                if (!visited[i]) {
                    if (dfs_util(i, visited, v)) {
                        return true;
                    }
                }
                else if (i != parent) {
                    // Visited vertex that is not parent means cycle
                    return true;
                }
            }
        }
        return false;
    }

public:
    Graph(int sz) {
        size = sz;
        adj_matrix.resize(size, vector<int>(size, 0));
        vertex_data.resize(size, "");
    }

    void addEdge(int u, int v) {
        if (u >= 0 && u < size && v >= 0 && v < size) {
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1; // undirected graph
        }
    }

    void addVertexData(int vertex, const string& data) {
        if (vertex >= 0 && vertex < size) {
            vertex_data[vertex] = data;
        }
    }

    bool isCyclic() {
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                if (dfs_util(i, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

    void printGraph() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\nVertex Data:\n";
        for (int i = 0; i < size; i++) {
            cout << i << ": " << vertex_data[i] << "\n";
        }
    }
};


int main() {
    Graph g(4);

    g.addVertexData(0, "A");
    g.addVertexData(1, "B");
    g.addVertexData(2, "C");
    g.addVertexData(3, "D");

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printGraph();

    if (g.isCyclic()) {
        cout << "Graph contains cycle\n";
    } else {
        cout << "Graph does not contain cycle\n";
    }

    return 0;
}
