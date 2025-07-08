
# 1. Graph using Adjacency Matrix (Undirected, Unweighted)
class GraphAdjMatrix:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def add_edge(self, u, v):
        self.graph[u][v] = 1
        self.graph[v][u] = 1  # undirected

    def print_graph(self):
        for row in self.graph:
            print(row)




# 2. Graph using Adjacency Matrix (Directed, Weighted)
class DirectedWeightedGraphAdjMatrix:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight  # directed and weighted

    def print_graph(self):
        for row in self.graph:
            print(row)




# 3. Graph using Adjacency List (Undirected, Unweighted)
from collections import defaultdict

class GraphAdjList:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)  # undirected

    def print_graph(self):
        for vertex in self.graph:
            print(f"{vertex} -> {self.graph[vertex]}")


# 4. Graph using Adjacency List (Directed, Weighted)
class DirectedWeightedGraphAdjList:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v, weight):
        self.graph[u].append((v, weight))  # directed and weighted

    def print_graph(self):
        for vertex in self.graph:
            print(f"{vertex} -> {self.graph[vertex]}")


# Example Usage
if __name__ == '__main__':
    print("Undirected, Unweighted Graph (Adjacency Matrix):")
    g1 = GraphAdjMatrix(4)
    g1.add_edge(0, 1)
    g1.add_edge(0, 2)
    g1.add_edge(1, 3)
    g1.print_graph()

    print("\nDirected, Weighted Graph (Adjacency Matrix):")
    g2 = DirectedWeightedGraphAdjMatrix(4)
    g2.add_edge(0, 1, 3)
    g2.add_edge(0, 2, 2)
    g2.add_edge(1, 3, 5)
    g2.print_graph()

    print("\nUndirected, Unweighted Graph (Adjacency List):")
    g3 = GraphAdjList()
    g3.add_edge('A', 'B')
    g3.add_edge('A', 'C')
    g3.add_edge('B', 'D')
    g3.print_graph()

    print("\nDirected, Weighted Graph (Adjacency List):")
    g4 = DirectedWeightedGraphAdjList()
    g4.add_edge('A', 'B', 3)
    g4.add_edge('A', 'C', 2)
    g4.add_edge('B', 'D', 5)
    g4.add_edge('D', 'A', 4)
    g4.print_graph()
