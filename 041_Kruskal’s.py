## Code
```
class Graph:
    def __init__(self, size):
        self.size = size
        self.edges = []  # (u, v, weight)
        self.vertex_data = [''] * size

    def add_edge(self, u, v, weight):
        if 0 <= u < self.size and 0 <= v < self.size:
            self.edges.append((u, v, weight))
 
    def add_vertex_data(self, vertex, data):
        if 0 <= vertex < self.size:
            self.vertex_data[vertex] = data

    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    def union(self, parent, rank, x, y):
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)
        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1

    def kruskals_algorithm(self):
        result = []
        i = 0

        self.edges = sorted(self.edges, key=lambda item: item[2])

        parent = [node for node in range(self.size)]
        rank = [0] * self.size

        while len(result) < self.size - 1 and i < len(self.edges):
            u, v, weight = self.edges[i]
            i += 1

            x = self.find(parent, u)
            y = self.find(parent, v)

            if x != y:
                result.append((u, v, weight))
                self.union(parent, rank, x, y)

        print("Edge \tWeight")
        for u, v, weight in result:
            print(f"{self.vertex_data[u]}-{self.vertex_data[v]} \t{weight}")
```

  
  ## Example Usage:        
          g = Graph(7)
          g.add_vertex_data(0, 'A')
          g.add_vertex_data(1, 'B')
          g.add_vertex_data(2, 'C')
          g.add_vertex_data(3, 'D')
          g.add_vertex_data(4, 'E')
          g.add_vertex_data(5, 'F')
          g.add_vertex_data(6, 'G')
          
          # Edges (u, v, weight)
          g.add_edge(0, 1, 4)   # A-B
          g.add_edge(0, 6, 10)  # A-G
          g.add_edge(0, 2, 9)   # A-C
          g.add_edge(1, 2, 8)   # B-C
          g.add_edge(2, 3, 5)   # C-D
          g.add_edge(2, 4, 2)   # C-E
          g.add_edge(2, 6, 7)   # C-G
          g.add_edge(3, 4, 3)   # D-E
          g.add_edge(3, 5, 7)   # D-F
          g.add_edge(4, 6, 6)   # E-G
          g.add_edge(5, 6, 11)  # F-G
          
          print("Kruskal's Algorithm MST:")
          g.kruskals_algorithm()




