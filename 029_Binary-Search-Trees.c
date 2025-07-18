// ----------------------* Binary Search Trees *------------------------


/*
Binary Search Trees (BST)
Definition: A Binary Search Tree is a binary tree with the following properties:
    Each node has at most two children.
    The left subtree of a node contains only nodes with values less than the node's value.
    The right subtree of a node contains only nodes with values greater than the node's value.
    Left and right subtrees are also BSTs.

Properties
Efficient Search: Average time complexity for search, insertion, and deletion is O(logn), but in the worst case (skewed tree), it is O(n).
In-order Traversal: Retrieves elements in sorted order.

Operations on BST
Insertion: Adds a new element while maintaining the BST property.
Search: Locates an element in the tree.
Deletion: Removes an element and rebalances the tree if necessary.
// */
// Example Implementation in C
// BST Structure

          #include <stdio.h>
          #include <stdlib.h>
          
          // Define a node
          struct Node {
              int data;
              struct Node* left;
              struct Node* right;
          };
          
          // Create a new node
          struct Node* createNode(int data) {
              struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
              newNode->data = data;
              newNode->left = newNode->right = NULL;
              return newNode;
          }
          
          // Insert a node into the BST
          struct Node* insert(struct Node* root, int data) {
              if (root == NULL) return createNode(data);
          
              if (data < root->data)
                  root->left = insert(root->left, data);
              else if (data > root->data)
                  root->right = insert(root->right, data);
          
              return root;
          }
          
          // Search for a value in the BST
          struct Node* search(struct Node* root, int key) {
              if (root == NULL || root->data == key) return root;
          
              if (key < root->data)
                  return search(root->left, key);
              else
                  return search(root->right, key);
          }
          
          // In-order Traversal
          void inOrder(struct Node* root) {
              if (root != NULL) {
                  inOrder(root->left);
                  printf("%d ", root->data);
                  inOrder(root->right);
              }
          }
          Main Function
          c
          Copy code
          int main() {
              struct Node* root = NULL;
          
              // Insert elements into the BST
              root = insert(root, 50);
              root = insert(root, 30);
              root = insert(root, 70);
              root = insert(root, 20);
              root = insert(root, 40);
              root = insert(root, 60);
              root = insert(root, 80);
          
              printf("In-order Traversal of BST: ");
              inOrder(root);
              printf("\n");
          
              // Search for a key
              int key = 40;
              struct Node* found = search(root, key);
              if (found != NULL)
                  printf("Key %d found in BST.\n", key);
              else
                  printf("Key %d not found in BST.\n", key);
          
              return 0;
          }

// Output

// In-order Traversal of BST: 20 30 40 50 60 70 80 
// Key 40 found in BST.

// This example demonstrates basic BST operations: insertion, search, and in-order traversal.

 
