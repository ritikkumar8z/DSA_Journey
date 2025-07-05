class Graph:
    def __init__(self, size):
        self.adj_matrix = [[0] * size for _ in range(size)]
        self.size = size
        self.vertex_data = [''] * size

    def add_edge(self, u, v, weight, directed=False): 
        if 0 <= u < self.size and 0 <= v < self.size:
            self.adj_matrix[u][v] = weight
            if not directed:
                self.adj_matrix[v][u] = weight

    def add_vertex_data(self, vertex, data):
        if 0 <= vertex < self.size:
            self.vertex_data[vertex] = data

    def dijkstra(self, start_vertex_data, end_vertex_data=None):
        start_vertex = self.vertex_data.index(start_vertex_data)
        distances = [float('inf')] * self.size
        predecessors = [None] * self.size
        visited = [False] * self.size
        distances[start_vertex] = 0

        for _ in range(self.size):
            min_distance = float('inf')
            u = None
            for i in range(self.size):
                if not visited[i] and distances[i] < min_distance:
                    min_distance = distances[i]
                    u = i

            if u is None or (end_vertex_data and u == self.vertex_data.index(end_vertex_data)):
                break

            visited[u] = True

            for v in range(self.size):
                if self.adj_matrix[u][v] != 0 and not visited[v]:
                    alt = distances[u] + self.adj_matrix[u][v]
                    if alt < distances[v]:
                        distances[v] = alt
                        predecessors[v] = u

        if end_vertex_data:
            path = self.get_path(predecessors, start_vertex_data, end_vertex_data)
            return distances[self.vertex_data.index(end_vertex_data)], path
        else:
            return distances, predecessors

    def get_path(self, predecessors, start_vertex_data, end_vertex_data):
        path = []
        current = self.vertex_data.index(end_vertex_data)
        start_index = self.vertex_data.index(start_vertex_data)
        while current is not None:
            path.insert(0, self.vertex_data[current])
            current = predecessors[current]
            if current == start_index:
                path.insert(0, self.vertex_data[current])
                break
        return '->'.join(path)


# Example usage
g = Graph(7)
vertices = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
for i, v in enumerate(vertices):
    g.add_vertex_data(i, v)

# Undirected Graph
edges = [
    ('D', 'A', 4),
    ('D', 'E', 2),
    ('A', 'C', 3),
    ('A', 'E', 4),
    ('E', 'C', 4),
    ('E', 'G', 5),
    ('C', 'F', 5),
    ('C', 'B', 2),
    ('B', 'F', 2),
    ('G', 'F', 5),
]

for u, v, w in edges:
    g.add_edge(vertices.index(u), vertices.index(v), w)

# Full path result
print("\nDijkstra's Algorithm from vertex D:")
distances, preds = g.dijkstra('D')
for i, d in enumerate(distances):
    path = g.get_path(preds, 'D', vertices[i])
    print(f"Path from D to {vertices[i]}: {path}, Distance: {d}")

# Single destination example
print("\nShortest path from D to F only:")
distance, path = g.dijkstra('D', 'F')
print(f"Path: {path}, Distance: {distance}")
