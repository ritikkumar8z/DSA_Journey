### Graphs: Cycle Detection (Python DSA)

---

### ✅ Cycle Detection Using DFS (Undirected Graph)
```python
class Graph:
    def __init__(self, size):
        self.adj_matrix = [[0] * size for _ in range(size)]
        self.size = size
        self.vertex_data = [''] * size

    def add_edge(self, u, v):
        self.adj_matrix[u][v] = 1
        self.adj_matrix[v][u] = 1  # undirected

    def add_vertex_data(self, vertex, data):
        self.vertex_data[vertex] = data

    def dfs_util(self, v, visited, parent):
        visited[v] = True
        for i in range(self.size):
            if self.adj_matrix[v][i] == 1:
                if not visited[i]:
                    if self.dfs_util(i, visited, v):
                        return True
                elif i != parent:
                    return True
        return False

    def is_cyclic(self):
        visited = [False] * self.size
        for i in range(self.size):
            if not visited[i]:
                if self.dfs_util(i, visited, -1):
                    return True
        return False

g = Graph(7)
for i, label in enumerate(['A', 'B', 'C', 'D', 'E', 'F', 'G']):
    g.add_vertex_data(i, label)

g.add_edge(3, 0)  # D - A
g.add_edge(0, 2)  # A - C
g.add_edge(0, 4)  # A - E
g.add_edge(4, 2)  # E - C
g.add_edge(2, 5)  # C - F
g.add_edge(2, 1)  # C - B
g.add_edge(2, 6)  # C - G
g.add_edge(1, 5)  # B - F

print("Graph has cycle:", g.is_cyclic())
```

---

### 🔁 Cycle Detection Using DFS (Directed Graph)
```python
class Graph:
    def __init__(self, size):
        self.adj_matrix = [[0] * size for _ in range(size)]
        self.size = size
        self.vertex_data = [''] * size

    def add_edge(self, u, v):
        self.adj_matrix[u][v] = 1  # directed only

    def add_vertex_data(self, vertex, data):
        self.vertex_data[vertex] = data

    def dfs_util(self, v, visited, recStack):
        visited[v] = True
        recStack[v] = True
        print("Current vertex:", self.vertex_data[v])

        for i in range(self.size):
            if self.adj_matrix[v][i] == 1:
                if not visited[i]:
                    if self.dfs_util(i, visited, recStack):
                        return True
                elif recStack[i]:
                    return True

        recStack[v] = False
        return False

    def is_cyclic(self):
        visited = [False] * self.size
        recStack = [False] * self.size
        for i in range(self.size):
            if not visited[i]:
                if self.dfs_util(i, visited, recStack):
                    return True
        return False

g = Graph(7)
for i, label in enumerate(['A', 'B', 'C', 'D', 'E', 'F', 'G']):
    g.add_vertex_data(i, label)

g.add_edge(3, 0)  # D -> A
g.add_edge(0, 2)  # A -> C
g.add_edge(2, 1)  # C -> B
g.add_edge(2, 4)  # C -> E
g.add_edge(1, 5)  # B -> F
g.add_edge(4, 0)  # E -> A
g.add_edge(2, 6)  # C -> G

print("Graph has cycle:", g.is_cyclic())
```

---

### 🔄 Cycle Detection Using Union-Find (Undirected Graph)
```python
class Graph:
    def __init__(self, size):
        self.adj_matrix = [[0] * size for _ in range(size)]
        self.size = size
        self.vertex_data = [''] * size
        self.parent = [i for i in range(size)]

    def add_edge(self, u, v):
        self.adj_matrix[u][v] = 1
        self.adj_matrix[v][u] = 1

    def add_vertex_data(self, vertex, data):
        self.vertex_data[vertex] = data

    def find(self, i):
        if self.parent[i] == i:
            return i
        return self.find(self.parent[i])

    def union(self, x, y):
        x_root = self.find(x)
        y_root = self.find(y)
        print(f'Union: {self.vertex_data[x]} + {self.vertex_data[y]}')
        self.parent[x_root] = y_root
        print(self.parent, '\n')

    def is_cyclic(self):
        for i in range(self.size):
            for j in range(i + 1, self.size):
                if self.adj_matrix[i][j]:
                    x = self.find(i)
                    y = self.find(j)
                    if x == y:
                        return True
                    self.union(x, y)
        return False

g = Graph(7)
for i, label in enumerate(['A', 'B', 'C', 'D', 'E', 'F', 'G']):
    g.add_vertex_data(i, label)

g.add_edge(1, 0)  # B - A
g.add_edge(0, 3)  # A - D
g.add_edge(0, 2)  # A - C
g.add_edge(2, 3)  # C - D
g.add_edge(3, 4)  # D - E
g.add_edge(3, 5)  # D - F
g.add_edge(3, 6)  # D - G
g.add_edge(4, 5)  # E - F

print("Graph has cycle:", g.is_cyclic())
```

---
