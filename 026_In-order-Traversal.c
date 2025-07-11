// # DSA: In-order Traversal of Binary Trees

/*
# In-order Traversal Overview
--- In-order Traversal is a type of Depth-First Search (DFS) where each node of the Binary Tree is visited in a specific order. 
    This traversal follows these steps:

a). Recursively traverse the left subtree.
b). Visit the root node.
c). Recursively traverse the right subtree.

The result of an In-order Traversal for Binary Search Trees (BST) is always the node values in ascending order, as it processes nodes in 
a "left, root, right" manner.

# Why is it Called "In-order"?
--- The term "in-order" refers to the fact that the root node is visited in between the recursive function calls:
      The left subtree is visited first.
      The root node is visited second.
      The right subtree is visited last.
    */

// Below is the C code for performing an In-order Traversal on a Binary Tree.

          #include <stdio.h>
          #include <stdlib.h>
          
          // Define the structure for the tree node
          struct Node {
              char data;
              struct Node* left;
              struct Node* right;
          };
          
          // Function to create a new node
          struct Node* newNode(char data) {
              struct Node* node = (struct Node*)malloc(sizeof(struct Node));
              node->data = data;
              node->left = node->right = NULL;
              return node;
          }
          
          // Function for In-order Traversal
          void inOrderTraversal(struct Node* node) {
              if (node == NULL) {
                  return;
              }
              // Traverse the left subtree
              inOrderTraversal(node->left);
              
              // Visit the root node
              printf("%c, ", node->data);
              
              // Traverse the right subtree
              inOrderTraversal(node->right);
          }
          
          // Driver code
          int main() {
              // Creating a simple binary tree
              struct Node* root = newNode('R');
              root->left = newNode('A');
              root->right = newNode('B');
              root->left->left = newNode('C');
              root->left->right = newNode('D');
              root->right->left = newNode('E');
              root->right->right = newNode('F');
              root->right->right->right = newNode('G');
              
              printf("In-order Traversal: ");
              inOrderTraversal(root);
              return 0;
          }


/*
Explanation of the Code:
1). Node Structure :- We define a Node structure to represent each node of the tree, containing:
    a). data: The value of the node.
    b). left: Pointer to the left child node.
    c). right: Pointer to the right child node.

2). Creating a Node :- The newNode() function allocates memory for a new node and assigns it the provided data value. 
    It also sets the left and right pointers to NULL.

3). In-order Traversal :- The function inOrderTraversal() takes a node as input and performs a recursive traversal:
    --- First, it calls itself on the left child (node->left).
    --- Then, it prints the node's data.
    --- Finally, it calls itself on the right child (node->right).
4). Driver Code :- In the main() function, a binary tree is created manually by linking nodes together. 
    The inOrderTraversal() function is called to print the result of the traversal.

Expected Output:
For the binary tree structure:
        
                R
               / \
              A   B
             / \ / \
            C  D E  F
                     \
                      G


The output of the in-order traversal will be:

In-order Traversal: C, A, D, R, E, B, F, G,


# Key Points:
  In-order traversal ensures that the nodes are visited in ascending order for Binary Search Trees (BST).
  The recursion starts from the leftmost node and traverses all the way to the rightmost node.
  This traversal method is particularly useful for operations like searching, sorting, and printing the elements of a BST in order.

*/

