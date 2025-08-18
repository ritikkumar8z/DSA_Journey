# DSA Mega Suite: Hashing, Trees, and Graphs

# ============================
# Hash Table Implementation
# ============================
class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value): 
        index = self._hash(key)
        for pair in self.table[index]:
            if pair[0] == key:
                pair[1] = value
                return
        self.table[index].append([key, value])

    def get(self, key):
        index = self._hash(key)
        for pair in self.table[index]:
            if pair[0] == key:
                return pair[1]
        return None

    def delete(self, key):
        index = self._hash(key)
        self.table[index] = [pair for pair in self.table[index] if pair[0] != key]

# ============================
# Binary Search Tree
# ============================
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert(self.root, key)

    def _insert(self, node, key):
        if not node:
            return TreeNode(key)
        if key < node.key:
            node.left = self._insert(node.left, key)
        else:
            node.right = self._insert(node.right, key)
        return node

    def in_order(self):
        def _in_order(node):
            return _in_order(node.left) + [node.key] + _in_order(node.right) if node else []
        return _in_order(self.root)

# ============================
# Graph with Traversals and Shortest Path
# ============================
import heapq

class Graph:
    def __init__(self):
        self.adj = {}

    def add_edge(self, u, v, w):
        if u not in self.adj:
            self.adj[u] = []
        self.adj[u].append((v, w))

    def bfs(self, start):
        visited = set()
        queue = [start]
        result = []
        while queue:
            u = queue.pop(0)
            if u not in visited:
                visited.add(u)
                result.append(u)
                for v, _ in self.adj.get(u, []):
                    queue.append(v)
        return result

    def dfs_util(self, u, visited, result):
        visited.add(u)
        result.append(u)
        for v, _ in self.adj.get(u, []):
            if v not in visited:
                self.dfs_util(v, visited, result)

    def dfs(self, start):
        visited = set()
        result = []
        self.dfs_util(start, visited, result)
        return result

    def dijkstra(self, start):
        dist = {node: float('inf') for node in self.adj}
        dist[start] = 0
        pq = [(0, start)]
        while pq:
            d, u = heapq.heappop(pq)
            for v, w in self.adj.get(u, []):
                if dist[v] > d + w:
                    dist[v] = d + w
                    heapq.heappush(pq, (dist[v], v))
        return dist

    def bellman_ford(self, start):
        dist = {node: float('inf') for node in self.adj}
        dist[start] = 0
        for _ in range(len(self.adj) - 1):
            for u in self.adj:
                for v, w in self.adj[u]:
                    if dist[u] + w < dist[v]:
                        dist[v] = dist[u] + w
        # Check for negative-weight cycles
        for u in self.adj:
            for v, w in self.adj[u]:
                if dist[u] + w < dist[v]:
                    raise Exception("Negative weight cycle detected")
        return dist

# ============================
# Main Function to Test All
# ============================
if __name__ == "__main__":
    print("--- Hash Table ---")
    ht = HashTable()
    ht.insert("101", {"name": "Ritik", "city": "Delhi"})
    ht.insert("102", {"name": "Aman", "city": "Kolkata"})
    print("User 101:", ht.get("101"))

    print("\n--- BST ---")
    bst = BST()
    for price in [5000, 7500, 3000, 6000]:
        bst.insert(price)
    print("Prices in-order:", bst.in_order())

    print("\n--- Graph ---")
    g = Graph()
    g.add_edge("Delhi", "Mumbai", 1500)
    g.add_edge("Mumbai", "Chennai", 2000)
    g.add_edge("Delhi", "Kolkata", 1700)
    g.add_edge("Kolkata", "Chennai", 1000)
    g.add_edge("Chennai", "Delhi", -300)  # for bellman-ford check

    print("BFS from Delhi:", g.bfs("Delhi"))
    print("DFS from Delhi:", g.dfs("Delhi"))
    print("Dijkstra from Delhi:", g.dijkstra("Delhi"))
    try:
        print("Bellman-Ford from Delhi:", g.bellman_ford("Delhi"))
    except Exception as e:
        print("Bellman-Ford Error:", e)
