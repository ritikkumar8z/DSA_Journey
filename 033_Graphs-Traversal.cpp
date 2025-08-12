#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Graph {
    int size;
    vector<vector<int>> adj_matrix;
    vector<string> vertex_data;

    void dfs_util(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << vertex_data[v] << " ";

        for (int i = 0; i < size; i++) {
            if (adj_matrix[v][i] == 1 && !visited[i]) {
                dfs_util(i, visited);
            }
        }
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
            adj_matrix[v][u] = 1; // comment this for directed graph
        }
    }

    void addVertexData(int vertex, const string& data) {
        if (vertex >= 0 && vertex < size) {
            vertex_data[vertex] = data;
        }
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
            cout << "Vertex " << i << ": " << vertex_data[i] << "\n";
        }
    }

    void dfs(const string& start_vertex_data) {
        int start_vertex = -1;
        for (int i = 0; i < size; i++) {
            if (vertex_data[i] == start_vertex_data) {
                start_vertex = i;
                break;
            }
        }
        if (start_vertex == -1) {
            cout << "Start vertex data not found.\n";
            return;
        }

        vector<bool> visited(size, false);
        cout << "DFS traversal starting from " << start_vertex_data << ": ";
        dfs_util(start_vertex, visited);
        cout << "\n";
    }

    void bfs(const string& start_vertex_data) {
        int start_vertex = -1;
        for (int i = 0; i < size; i++) {
            if (vertex_data[i] == start_vertex_data) {
                start_vertex = i;
                break;
            }
        }
        if (start_vertex == -1) {
            cout << "Start vertex data not found.\n";
            return;
        }

        vector<bool> visited(size, false);
        queue<int> q;
        visited[start_vertex] = true;
        q.push(start_vertex);

        cout << "BFS traversal starting from " << start_vertex_data << ": ";

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << vertex_data[v] << " ";

            for (int i = 0; i < size; i++) {
                if (adj_matrix[v][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << "\n";
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
    g.addEdge(0, 3);
    g.addEdge(1, 2);

    g.printGraph();

    g.dfs("A");
    g.bfs("A");

    return 0;
}
