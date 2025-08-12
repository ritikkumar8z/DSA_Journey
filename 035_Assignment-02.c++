#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <optional>
#include <unordered_map>
using namespace std;

// ---------------- HashTable ------------------
class HashTable {
    int size;
    vector<optional<pair<string, unordered_map<string, string>>>> table;

    int hash_func(const string& key) {
        return hash<string>{}(key) % size;
    }

public:
    HashTable(int sz) : size(sz) {
        table.resize(size);
    }

    void insert(const string& key, const unordered_map<string, string>& value) {
        int index = hash_func(key);
        int start = index;

        while (table[index].has_value() && table[index]->first != key) {
            index = (index + 1) % size;
            if (index == start) {
                cout << "Hash table full! Cannot insert " << key << "\n";
                return;
            }
        }
        table[index] = make_pair(key, value);
    }

    optional<unordered_map<string, string>> search(const string& key) {
        int index = hash_func(key);
        int start = index;

        while (table[index].has_value()) {
            if (table[index]->first == key) {
                return table[index]->second;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
        return {};
    }
};

// ---------------- BST ------------------
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BSTree {
    Node* root;

    Node* insert(Node* root, int val) {
        if (!root) return new Node(val);
        if (val < root->val)
            root->left = insert(root->left, val);
        else if (val > root->val)
            root->right = insert(root->right, val);
        return root;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    bool search(Node* root, int val) {
        if (!root) return false;
        if (root->val == val) return true;
        if (val < root->val)
            return search(root->left, val);
        else
            return search(root->right, val);
    }

public:
    BSTree() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void inorder() {
        inorder(root);
        cout << "\n";
    }

    bool search(int val) {
        return search(root, val);
    }
};

// ---------------- Graph ------------------
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

    bool is_cyclic_util(int v, vector<bool>& visited, int parent) {
        visited[v] = true;
        for (int i = 0; i < size; i++) {
            if (adj_matrix[v][i] == 1) {
                if (!visited[i]) {
                    if (is_cyclic_util(i, visited, v))
                        return true;
                }
                else if (i != parent) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    Graph(int sz) : size(sz) {
        adj_matrix.resize(size, vector<int>(size, 0));
        vertex_data.resize(size);
    }

    void add_vertex(int idx, const string& name) {
        if (idx >= 0 && idx < size)
            vertex_data[idx] = name;
    }

    void add_edge(int u, int v) {
        if (u >= 0 && u < size && v >= 0 && v < size) {
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1; // undirected
        }
    }

    void dfs(int start) {
        vector<bool> visited(size, false);
        dfs_util(start, visited);
        cout << "\n";
    }

    void bfs(int start) {
        vector<bool> visited(size, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << vertex_data[current] << " ";

            for (int i = 0; i < size; i++) {
                if (adj_matrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << "\n";
    }

    bool is_cyclic() {
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                if (is_cyclic_util(i, visited, -1))
                    return true;
            }
        }
        return false;
    }
};


// ------------------- DRIVER --------------------
int main() {
    cout << "\n--- Hashing Demo ---\n";
    HashTable ht(10);
    ht.insert("user1", { {"name", "Ritik"}, {"email", "ritik@example.com"} });
    ht.insert("user2", { {"name", "Sandip"}, {"email", "sandip@example.com"} });

    auto res = ht.search("user1");
    if (res.has_value()) {
        cout << "Search user1: { ";
        for (const auto& p : res.value()) {
            cout << p.first << ": " << p.second << ", ";
        }
        cout << "}\n";
    } else {
        cout << "user1 not found\n";
    }

    cout << "\n--- Binary Search Tree Demo ---\n";
    BSTree bst;
    vector<int> ids = {50, 30, 70, 20, 40, 60, 80};
    for (int id : ids)
        bst.insert(id);

    cout << "Inorder Traversal:\n";
    bst.inorder();

    cout << "Search 60: " << (bst.search(60) ? "Found" : "Not Found") << "\n";

    cout << "\n--- Graph Demo ---\n";
    Graph g(5);
    vector<string> users = {"A", "B", "C", "D", "E"};
    for (int i = 0; i < (int)users.size(); i++) {
        g.add_vertex(i, users[i]);
    }

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);

    cout << "DFS from A:\n";
    g.dfs(0);

    cout << "BFS from A:\n";
    g.bfs(0);

    cout << "Has Cycle: " << (g.is_cyclic() ? "Yes" : "No") << "\n";

    return 0;
}
