from collections import deque

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0] * vertices for _ in range(vertices)]

    def add_edge(self, u, v, capacity):
        self.graph[u][v] = capacity 

    def bfs(self, s, t, parent):
        visited = [False] * self.V
        queue = deque([s]) 
        visited[s] = True

        while queue:
            u = queue.popleft()

            for v, cap in enumerate(self.graph[u]):
                if not visited[v] and cap > 0:
                    queue.append(v)
                    visited[v] = True
                    parent[v] = u

        return visited[t]

    def ford_fulkerson(self, source, sink):
        parent = [-1] * self.V
        max_flow = 0

        while self.bfs(source, sink, parent):
            path_flow = float('inf')
            s = sink
            while s != source:
                path_flow = min(path_flow, self.graph[parent[s]][s])
                s = parent[s]

            max_flow += path_flow

            v = sink
            while v != source: 
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]

        return max_flow




#  ▶️ Sample Usage (in test_case_runner.py) 
from max_flow import Graph

g = Graph(6)

# Sample Graph from s(0) to t(5) 
g.add_edge(0, 1, 16) 
g.add_edge(0, 2, 13)
g.add_edge(1, 2, 10)
g.add_edge(2, 1, 4)
g.add_edge(1, 3, 12)
g.add_edge(2, 4, 14)
g.add_edge(3, 2, 9)
g.add_edge(3, 5, 20)
g.add_edge(4, 3, 7)
g.add_edge(4, 5, 4)

source, sink = 0, 5
print("Maximum Flow:", g.ford_fulkerson(source, sink))
