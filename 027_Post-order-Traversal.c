/*
# Post-order Traversal of Binary Trees
    In Post-order Traversal, each node is visited in a "Left, Right, Root" sequence. It’s another type of Depth-First Search (DFS) traversal, 
    commonly used for tasks that involve deleting nodes or evaluating expressions represented in tree form.

Steps for Post-order Traversal
  Traverse the left subtree recursively.
  Traverse the right subtree recursively.
  Visit the root node.


# Key Points
Post-order is useful in situations where nodes need to be processed after their subtrees.
This traversal is often used in deleting nodes in a tree since it clears child nodes before the parent node.
In an expression tree, Post-order Traversal gives a postfix expression (used in evaluating expressions without needing parentheses).
*/
          #include <stdio.h>
          #include <stdlib.h>
          
          // Structure definition for tree node
          struct Node {
              int data;
              struct Node* left;
              struct Node* right;
          };
          
          // Function to create a new tree node
          struct Node* newNode(int data) {
              struct Node* node = (struct Node*)malloc(sizeof(struct Node));
              node->data = data;
              node->left = node->right = NULL;
              return node;
          }
          
          // Function to perform Post-order Traversal
          void postOrderTraversal(struct Node* node) {
              if (node == NULL) {
                  return;
              }
              // Traverse the left subtree
              postOrderTraversal(node->left);
              
              // Traverse the right subtree
              postOrderTraversal(node->right);
              
              // Visit the root node
              printf("%d ", node->data);
          }
          
          // Driver code
          int main() {
              // Creating a binary tree
              struct Node* root = newNode(10);
              root->left = newNode(5);
              root->right = newNode(15);
              root->left->left = newNode(3);
              root->left->right = newNode(7);
              root->right->left = newNode(13);
              root->right->right = newNode(18);
              
              printf("Post-order Traversal: ");
              postOrderTraversal(root);
              return 0;
          }

/*
Explanation of the Code
a). Node Structure: The Node structure represents each tree node.
b). Creating Nodes: The newNode() function creates nodes with the given data.

Post-order Traversal Logic:
--- The postOrderTraversal() function first traverses the left subtree.
--- It then traverses the right subtree before visiting the node (root).
--- Driver Code: The main() function initializes a binary tree and calls postOrderTraversal() to print the result.

Expected Output
For the tree structure:
      
              10
             /  \
            5    15
           / \   / \
          3   7 13 18

The output of the post-order traversal will be:
Post-order Traversal: 3 7 5 13 18 15 10


# Key Takeaways

Post-order Traversal processes nodes after their children, making it ideal for deletion tasks in binary trees.
This traversal also helps in generating postfix expressions for expression trees.

*/


    

