// -----------------------* 🌳 Binary Trees *-------------------------



/* 🌳 Binary Trees in DSA
This guide provides a deep dive into Binary Trees—a foundational data structure in computer science that enables efficient data storage, sorting, searching, and more.

📖 Introduction to Binary Trees
A Binary Tree is a hierarchical structure where each node can have at most two child nodes: a left child and a right child. This setup offers several benefits:

Efficient Traversal and Search: Searching, inserting, and deleting nodes are streamlined.
Memory Efficient: Binary Trees can be represented as arrays.
Sorted Data: Binary Search Trees (BST) allow for fast data retrieval.
Balanced Structures: AVL Binary Trees self-balance, keeping tree height minimized for faster operations.

🔍 Binary Tree Representation

                        R
                       / \
                      A   B
                     / \   \
                    C   D   E

🌳 Binary Tree Terminology

Root Node: The starting node of the tree.
Child Node: Node linked from a parent node.
Parent/Internal Node: A node with at least one child.
Left Child / Right Child: The left and right child nodes of a parent node.
Leaf Node: Node with no children.
Tree Height: The number of edges from the root to the deepest leaf.
Tree Size: Total number of nodes in the tree.


Example Terms in Action
In the example tree above:

Root = R
Left Child of R = A
Right Child of R = B
Leaf Nodes = C, D, E


🪜 Types of Binary Trees
⚖️ Balanced Binary Tree
A Balanced Binary Tree has subtrees of each node with height differences of at most one. Balanced trees keep operations efficient by minimizing height.


🔲 Complete Binary Tree
A Complete Binary Tree has all levels filled except possibly the last, where nodes are filled from left to right.


🎯 Full Binary Tree
A Full Binary Tree has nodes with either 0 or 2 children only.


🌟 Perfect Binary Tree
A Perfect Binary Tree has all internal nodes with exactly two children, and all leaf nodes are on the same level. This tree is full, balanced, and complete.


🛠️ Binary Tree Implementation in C
Below is a simple example of implementing a Binary Tree in C, creating nodes with left and right children.
*/
                #include <stdio.h>
                #include <stdlib.h>
                
                struct Node {
                    int data;
                    struct Node *left, *right;
                };
                
                // Create a new node
                struct Node* createNode(int data) {
                    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
                    node->data = data;
                    node->left = node->right = NULL;
                    return node;
                }
                
                int main() {
                    // Constructing the binary tree
                    struct Node* root = createNode(1);
                    root->left = createNode(2);
                    root->right = createNode(3);
                    root->left->left = createNode(4);
                    root->left->right = createNode(5);
                
                    printf("Root node: %d\n", root->data);
                    return 0;
                }


/*
Output:
Root node: 1


🔄 Traversing a Binary Tree
Traversal methods allow visiting each node in a Binary Tree in different orders. The primary methods are Breadth First Search (BFS) and Depth First Search (DFS).

🔍 Breadth First Search (BFS)
In BFS, nodes on each level are visited before moving to the next level. This is also known as Level Order Traversal.

🔎 Depth First Search (DFS)
DFS goes deep into each branch before backtracking. DFS includes three types of traversal:

Pre-order: Visit the node, then left subtree, then right subtree.
In-order: Visit left subtree, then node, then right subtree.
Post-order: Visit left subtree, then right subtree, then node.
*/

// Example: In-order Traversal in C

          void inOrderTraversal(struct Node* node) {
              if (node == NULL) return;
              inOrderTraversal(node->left);
              printf("%d ", node->data);
              inOrderTraversal(node->right);
          }

/*
🏋️ Practice Exercise
In the tree below, what is the relationship between node B and nodes E and F?


                    A
                   / \
                  B   C
                 / \
                E   F

Answer:

Node E is B's left child.
Node F is B's right child.
*/


