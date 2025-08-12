#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int size;
    vector<vector<int>> adj_matrix;
    vector<char> vertices;

public:
    Graph(const vector<char>& vertexData) {
        vertices = vertexData;
        size = vertices.size();
        adj_matrix.resize(size, vector<int>(size, 0));
    }

    // Initialize the adjacency matrix directly
    void setAdjacencyMatrix(const vector<vector<int>>& matrix) {
        if (matrix.size() == size && matrix[0].size() == size) {
            adj_matrix = matrix;
        }
        else {
            cout << "Error: Matrix size mismatch\n";
        }
    }

    void printAdjacencyMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void printConnections() {
        cout << "\nConnections for each vertex:\n";
        for (int i = 0; i < size; i++) {
            cout << vertices[i] << ": ";
            for (int j = 0; j < size; j++) {
                if (adj_matrix[i][j] == 1) {
                    cout << vertices[j] << " ";
                }
            }
            cout << "\n";
        }
    }
};


int main() {
    vector<char> vertexData = {'A', 'B', 'C', 'D'};
    vector<vector<int>> adjacency_matrix = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0}
    };

    cout << "vertexData: ";
    for (char v : vertexData) cout << v << " ";
    cout << "\n";

    Graph g(vertexData);
    g.setAdjacencyMatrix(adjacency_matrix);

    g.printAdjacencyMatrix();
    g.printConnections();

    return 0;
}
