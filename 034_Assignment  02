# DSA_DataNetwork_System.py

# ----------- HASHING SECTION -------------
class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_func(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_func(key)
        while self.table[index] is not None and self.table[index][0] != key:
            index = (index + 1) % self.size
        self.table[index] = (key, value)

    def search(self, key):
        index = self.hash_func(key)
        start = index
        while self.table[index] is not None:
            if self.table[index][0] == key:
                return self.table[index][1]
            index = (index + 1) % self.size
            if index == start:
                break
        return None

    def delete(self, key):
        index = self.hash_func(key)
        while self.table[index] is not None:
            if self.table[index][0] == key:
                self.table[index] = None
                return True
            index = (index + 1) % self.size
        return False

# ----------- TREE SECTION (BST) -------------
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BSTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert(self.root, key)

    def _insert(self, node, key):
        if not node:
            return TreeNode(key)
        if key < node.key:
            node.left = self._insert(node.left, key)
        elif key > node.key:
            node.right = self._insert(node.right, key)
        return node

    def inorder(self, node=None):
        if node is None:
            node = self.root
        if node:
            self.inorder(node.left)
            print(node.key, end=" ")
            self.inorder(node.right)

    def search(self, key):
        return self._search(self.root, key)

    def _search(self, node, key):
        if not node or node.key == key:
            return node
        if key < node.key:
            return self._search(node.left, key)
        return self._search(node.right, key)

# ----------- GRAPH SECTION -------------
class Graph:
    def __init__(self, size):
        self.adj_matrix = [[0]*size for _ in range(size)]
        self.size = size
        self.vertices = ['']*size

    def add_vertex(self, idx, name):
        self.vertices[idx] = name

    def add_edge(self, u, v):
        self.adj_matrix[u][v] = 1
        self.adj_matrix[v][u] = 1  # undirected

    def dfs_util(self, v, visited):
        visited[v] = True
        print(self.vertices[v], end=" ")
        for i in range(self.size):
            if self.adj_matrix[v][i] == 1 and not visited[i]:
                self.dfs_util(i, visited)

    def dfs(self, start_idx):
        visited = [False] * self.size
        self.dfs_util(start_idx, visited)

    def bfs(self, start_idx):
        visited = [False] * self.size
        queue = [start_idx]
        visited[start_idx] = True
        while queue:
            current = queue.pop(0)
            print(self.vertices[current], end=" ")
            for i in range(self.size):
                if self.adj_matrix[current][i] == 1 and not visited[i]:
                    queue.append(i)
                    visited[i] = True

    def is_cyclic_util(self, v, visited, parent):
        visited[v] = True
        for i in range(self.size):
            if self.adj_matrix[v][i]:
                if not visited[i]:
                    if self.is_cyclic_util(i, visited, v):
                        return True
                elif i != parent:
                    return True
        return False

    def is_cyclic(self):
        visited = [False] * self.size
        for i in range(self.size):
            if not visited[i]:
                if self.is_cyclic_util(i, visited, -1):
                    return True
        return False

# ----------- DRIVER CODE (Using All DSA) -------------
if __name__ == "__main__":
    print("\n--- Hashing Demo ---")
    ht = HashTable(10)
    ht.insert("user1", {"name": "Ritik", "email": "ritik@example.com"})
    ht.insert("user2", {"name": "Sandip", "email": "sandip@example.com"})
    print("Search user1:", ht.search("user1"))

    print("\n--- Binary Search Tree Demo ---")
    bst = BSTree()
    for id in [50, 30, 70, 20, 40, 60, 80]:
        bst.insert(id)
    print("Inorder Traversal:")
    bst.inorder()
    print("\nSearch 60:", "Found" if bst.search(60) else "Not Found")

    print("\n--- Graph Demo ---")
    g = Graph(5)
    users = ['A', 'B', 'C', 'D', 'E']
    for idx, name in enumerate(users):
        g.add_vertex(idx, name)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 4)

    print("DFS from A:")
    g.dfs(0)
    print("\nBFS from A:")
    g.bfs(0)
    print("\nHas Cycle:", g.is_cyclic())
