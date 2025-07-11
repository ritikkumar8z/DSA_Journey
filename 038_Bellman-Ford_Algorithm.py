 
---

### ✅ `bellman_ford.py`
```python
class Graph:
    def __init__(self, size):
        self.adj_matrix = [[0] * size for _ in range(size)]
        self.size = size
        self.vertex_data = [''] * size

    def add_edge(self, u, v, weight):
        if 0 <= u < self.size and 0 <= v < self.size:
            self.adj_matrix[u][v] = weight

    def add_vertex_data(self, vertex, data):
        if 0 <= vertex < self.size:
            self.vertex_data[vertex] = data

    def bellman_ford(self, start_vertex_data):
        start_vertex = self.vertex_data.index(start_vertex_data)
        distances = [float('inf')] * self.size
        predecessors = [None] * self.size
        distances[start_vertex] = 0

        # Step 1: Relax all edges V-1 times
        for i in range(self.size - 1):
            for u in range(self.size):
                for v in range(self.size):
                    if self.adj_matrix[u][v] != 0:
                        if distances[u] + self.adj_matrix[u][v] < distances[v]:
                            distances[v] = distances[u] + self.adj_matrix[u][v]
                            predecessors[v] = u
                            print(f"Relaxing {self.vertex_data[u]}->{self.vertex_data[v]}, Distance: {distances[v]}")

        # Step 2: Check for negative weight cycles
        for u in range(self.size):
            for v in range(self.size):
                if self.adj_matrix[u][v] != 0:
                    if distances[u] + self.adj_matrix[u][v] < distances[v]:
                        return (True, None, None)  # Negative cycle detected

        return (False, distances, predecessors)

    def get_path(self, predecessors, start_vertex, end_vertex):
        path = []
        current = self.vertex_data.index(end_vertex)
        while current is not None:
            path.insert(0, self.vertex_data[current])
            current = predecessors[current]
            if current == self.vertex_data.index(start_vertex):
                path.insert(0, start_vertex)
                break
        return '->'.join(path)


if __name__ == "__main__":
    g = Graph(5)

    g.add_vertex_data(0, 'A')
    g.add_vertex_data(1, 'B')
    g.add_vertex_data(2, 'C')
    g.add_vertex_data(3, 'D')
    g.add_vertex_data(4, 'E')

    g.add_edge(3, 0, 4)  # D -> A
    g.add_edge(3, 2, 7)  # D -> C
    g.add_edge(3, 4, 3)  # D -> E
    g.add_edge(0, 2, 4)  # A -> C
    g.add_edge(2, 0, -3) # C -> A
    g.add_edge(0, 4, 5)  # A -> E
    g.add_edge(4, 2, 3)  # E -> C
    g.add_edge(1, 2, -4) # B -> C
    g.add_edge(4, 1, 2)  # E -> B

    print("\n🔄 Running Bellman-Ford Algorithm from source vertex 'D'")
    negative_cycle, distances, predecessors = g.bellman_ford('D')

    if negative_cycle:
        print("\n⚠️ Negative weight cycle detected. Cannot compute shortest paths.")
    else:
        print("\n✅ Shortest paths from vertex D:")
        for i, dist in enumerate(distances):
            if dist != float('inf'):
                path = g.get_path(predecessors, 'D', g.vertex_data[i])
                print(f"{path}, Distance: {dist}")
            else:
                print(f"No path to {g.vertex_data[i]} (Unreachable)")
