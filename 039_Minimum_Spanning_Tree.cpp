import heapq
from collections import defaultdict

def prim_mst(graph, start):
    visited = set()
    min_heap = [(0, start)]  # (weight, node)
    total_cost = 0 
    mst_edges = []

    while min_heap:  
        weight, u = heapq.heappop(min_heap)
        if u in visited:
            continue
        visited.add(u)
        total_cost += weight

        # Record edge in MST (skip the first dummy edge from None)
        if weight != 0:
            mst_edges.append((prev_node[u], u, weight))

        for v, w in graph[u]:
            if v not in visited:
                heapq.heappush(min_heap, (w, v))
                prev_node[v] = u

    if len(visited) != len(graph):
        print("Graph is not connected.")
        return None, []

    return total_cost, mst_edges

# 📈 Sample Graph
graph = defaultdict(list)
edges = [
    (0, 1, 4), (0, 2, 3),
    (1, 2, 1), (1, 3, 2),
    (2, 3, 4), (3, 4, 2),
    (4, 5, 6)
]

# Create adjacency list
for u, v, w in edges:
    graph[u].append((v, w))
    graph[v].append((u, w))

# 🏁 Start Prim's Algorithm from node 0
prev_node = {}  # Global for tracking edges
cost, mst = prim_mst(graph, 0)

# 🖨️ Output
print("Total cost of MST using Prim's Algorithm:", cost)
print("Edges in MST:")
for u, v, w in mst:
    print(f"{u} -- {v} [Weight: {w}]")
