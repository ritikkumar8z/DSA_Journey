// -----------------------* Pre-order Traversal *----------------------------


/*
1. Introduction to Pre-order Traversal
Definition: Pre-order Traversal is a type of Depth First Search (DFS) in binary trees, where each node is visited in the following order:
 
Visit the root node.
  Traverse the left subtree.
  Traverse the right subtree.

Applications:
  Copying a tree.
  Creating a prefix notation for an expression tree.
  */
  


// 2. Binary Tree Structure in C
// To perform Pre-order Traversal, let's define the structure of a binary tree in C.

          #include <stdio.h>
          #include <stdlib.h>
          
          // Structure for a node in a binary tree
          struct Node {
              int data;
              struct Node* left;
              struct Node* right;
          };
          
          // Function to create a new node
          struct Node* createNode(int data) {
              struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
              newNode->data = data;
              newNode->left = NULL;
              newNode->right = NULL;
              return newNode;
          }




// 3. Pre-order Traversal Implementation in C
// The pre-order traversal function will print each node's data following the root-left-right order.


          // Function for pre-order traversal
          void preOrderTraversal(struct Node* node) {
              if (node == NULL) return;
          
              // Visit the root node
              printf("%d ", node->data);
              
              // Traverse the left subtree
              preOrderTraversal(node->left);
              
              // Traverse the right subtree
              preOrderTraversal(node->right);
          }


/*
4. Example Tree Structure
Here’s an example binary tree:

                  1
                 / \
                2   3
               / \ / \
              4  5 6  7

*/

// 5. Code Example and Output
// This code constructs the above tree and performs a pre-order traversal.


          int main() {
              // Creating nodes
              struct Node* root = createNode(1);
              root->left = createNode(2);
              root->right = createNode(3);
              root->left->left = createNode(4);
              root->left->right = createNode(5);
              root->right->left = createNode(6);
              root->right->right = createNode(7);
          
              // Performing Pre-order Traversal
              printf("Pre-order Traversal: ");
              preOrderTraversal(root);
              
              return 0;
          }

/*
# Expected Output
  The expected output for the pre-order traversal of this binary tree is:

Pre-order Traversal: 1 2 4 5 3 6 7


6. Explanation of the Output
Step-by-Step Traversal:
Start with the root (1).
Move to the left subtree of 1, visiting 2.
Continue to the left subtree of 2, visiting 4.
Move back up and visit the right subtree of 2, visiting 5.
Go back to the root's right subtree (3), visiting 3.
Traverse the left subtree of 3, visiting 6.
Finally, visit the right subtree of 3, visiting 7.


7. Key Points to Remember
Pre-order Traversal: Root ➔ Left ➔ Right.
Used in applications like tree copying or evaluating prefix expressions.
This method is recursive but can also be implemented iteratively with a stack.


*/
