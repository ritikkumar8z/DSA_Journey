// -----------------------* 🌳 DSA Trees *-------------------------

 /*
🌳 DSA Trees
--- This repository explores the Tree data structure, a fundamental component in Data Structures and Algorithms (DSA). Trees are hierarchical, 
    branching structures commonly used in applications like file systems, databases, and network routing. This guide covers types of trees, terminology, 
    and examples implemented in C.


🗂️ Table of Contents
Introduction to Trees
Tree Terminology
Types of Trees
Binary Tree
Binary Search Tree
AVL Tree
Applications of Trees
Examples and Implementations


🌱 Introduction to Trees
The Tree data structure is a non-linear structure where each node can branch out in various directions, unlike linear data structures such as Arrays, 
Linked Lists, Stacks, and Queues. The "tree" shape starts from a root node and grows upside-down with each node linking to multiple child nodes.


                      R
                     /|\
                    A B C
                   /|\   \
                  D E F   G


📚 Tree Terminology
Here are essential terms in Tree data structures:

Root Node: The first node, serving as the tree’s base.
Edges: Links between nodes.
Parent Node: A node that links to one or more child nodes.
Child Node: A node linked from a parent node.
Leaf Node: A node with no children.
Height: The longest path from the root to a leaf.
Size: The total number of nodes.

Example:
Tree Height: h = 2
Tree Size: n = 10

🌲 Types of Trees
🌳 Binary Tree
A Binary Tree is a tree where each node has up to two children, commonly referred to as the left and right children.
*/
// Example Implementation in C:

        #include <stdio.h>
        #include <stdlib.h>
        
        struct Node {
            int data;
            struct Node *left, *right;
        };
        
        struct Node* createNode(int data) {
            struct Node* node = (struct Node*)malloc(sizeof(struct Node));
            node->data = data;
            node->left = node->right = NULL;
            return node;
        }
        
        int main() {
            struct Node* root = createNode(1);
            root->left = createNode(2);
            root->right = createNode(3);
            printf("Root Node: %d\n", root->data);
            return 0;
        }

/*
Output:
Root Node: 1


🔍 Binary Search Tree (BST)
A Binary Search Tree (BST) is a type of Binary Tree where each node's left child is less than the node, and the right child is greater.


⚖️ AVL Tree
An AVL Tree is a balanced Binary Search Tree. It maintains the balance by ensuring the height difference between left and right subtrees for any node is at most one.


💻 Applications of Trees
Hierarchical Data: File systems, organizational structures.
Databases: Quick data retrieval.
Network Routing: Routing data in networking.
Priority Queues: Often implemented using trees, like binary heaps.


🔧 Examples and Implementations in C
Each type of tree will have implementations with C code for:

Insertion
Deletion
Traversal (In-order, Pre-order, Post-order)
*/

// Example: In-order Traversal of Binary Tree in C

void inOrderTraversal(struct Node* node) {
    if (node == NULL) return;
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
}
