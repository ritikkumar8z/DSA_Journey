class Graph:
    def __init__(self, size):
        self.adj_matrix = [[0] * size for _ in range(size)]
        self.size = size
        self.vertex_data = [''] * size  # To store vertex names like A, B, C...

    def add_edge(self, u, v, weight):
        if 0 <= u < self.size and 0 <= v < self.size:
            self.adj_matrix[u][v] = weight
            self.adj_matrix[v][u] = weight  # Undirected graph

    def add_vertex_data(self, vertex, data):
        if 0 <= vertex < self.size:
            self.vertex_data[vertex] = data

    def prims_algorithm(self):
        in_mst = [False] * self.size
        key_values = [float('inf')] * self.size
        parents = [-1] * self.size

        key_values[0] = 0  # Start from vertex 0 (A)

        print("Edge \tWeight")
        for _ in range(self.size):
            # Find the vertex with the minimum key value that’s not in MST yet
            u = min((v for v in range(self.size) if not in_mst[v]), key=lambda v: key_values[v])

            in_mst[u] = True

            if parents[u] != -1:
                print(f"{self.vertex_data[parents[u]]}-{self.vertex_data[u]} \t{self.adj_matrix[u][parents[u]]}")

            # Update the key values and parent for adjacent vertices
            for v in range(self.size):
                if 0 < self.adj_matrix[u][v] < key_values[v] and not in_mst[v]:
                    key_values[v] = self.adj_matrix[u][v]
                    parents[v] = u


# Create graph instance with 8 vertices
g = Graph(8)

# Add vertex names
g.add_vertex_data(0, 'A')
g.add_vertex_data(1, 'B')
g.add_vertex_data(2, 'C')
g.add_vertex_data(3, 'D')
g.add_vertex_data(4, 'E')
g.add_vertex_data(5, 'F')
g.add_vertex_data(6, 'G')
g.add_vertex_data(7, 'H')

# Add all edges (undirected) with their weights
g.add_edge(0, 1, 4)  # A-B
g.add_edge(0, 3, 3)  # A-D
g.add_edge(1, 2, 3)  # B-C
g.add_edge(1, 3, 5)  # B-D
g.add_edge(1, 4, 6)  # B-E
g.add_edge(2, 4, 4)  # C-E
g.add_edge(2, 7, 2)  # C-H
g.add_edge(3, 4, 7)  # D-E
g.add_edge(3, 5, 4)  # D-F
g.add_edge(4, 5, 5)  # E-F
g.add_edge(4, 6, 3)  # E-G
g.add_edge(5, 6, 7)  # F-G
g.add_edge(6, 7, 5)  # G-H

# Run Prim's Algorithm
print("Prim's Algorithm MST:")
g.prims_algorithm()
