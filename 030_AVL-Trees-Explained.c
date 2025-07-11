 // -----------------------* AVL Trees Explained *----------------------


   
// # AVL Trees Explained
// # --- An AVL Tree is a self-balancing binary search tree (BST) named after its inventors, Georgy Adelson-Velsky and Evgenii Landis. 
// #     It ensures that the height of the tree remains balanced, which significantly improves the efficiency of search, insert, and delete operations. 
// #     The time complexity for these operations in AVL trees is O(log n).
  

/*  Characteristics of AVL Trees
a). Balance Factor:
   --- Each node stores a balance factor, which is the difference in heights of its left and right subtrees:
       Balance Factor = Height(Left Subtree) − Height(Right Subtree)
   --- A node is balanced if its balance factor is -1, 0, or 1.
   --- If the balance factor goes outside this range, rotations are used to restore balance.
b). Rotations:
--- Single Rotation:
      Left-Left (LL): Right rotation.
      Right-Right (RR): Left rotation.
--- Double Rotation:
      Left-Right (LR): Left rotation followed by right rotation.
      Right-Left (RL): Right rotation followed by left rotation.
  */



// AVL Tree Implementation in C 

        #include <stdio.h>
        #include <stdlib.h>
        
        // Define the structure for tree nodes
        typedef struct Node {
            int key;
            struct Node* left;
            struct Node* right;
            int height;
        } Node;
        
        // Function to get the height of a node
        int height(Node* node) {
            return node == NULL ? 0 : node->height;
        }
        
        // Function to get the balance factor of a node
        int getBalance(Node* node) {
            return node == NULL ? 0 : height(node->left) - height(node->right);
        }
        
        // Utility function to create a new node
        Node* createNode(int key) {
            Node* node = (Node*)malloc(sizeof(Node));
            node->key = key;
            node->left = NULL;
            node->right = NULL;
            node->height = 1;
            return node;
        }
        
        // Right rotation
        Node* rightRotate(Node* y) {
            Node* x = y->left;
            Node* T2 = x->right;
        
            x->right = y;
            y->left = T2;
        
            y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
            x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
        
            return x;
        }
        
        // Left rotation
        Node* leftRotate(Node* x) {
            Node* y = x->right;
            Node* T2 = y->left;
        
            y->left = x;
            x->right = T2;
        
            x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
            y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
        
            return y;
        }
        
        // Insert a key into the AVL Tree
        Node* insert(Node* node, int key) {
            // Perform regular BST insertion
            if (node == NULL) 
                return createNode(key);
        
            if (key < node->key)
                node->left = insert(node->left, key);
            else if (key > node->key)
                node->right = insert(node->right, key);
            else
                return node; // Duplicates are not allowed
        
            // Update the height of the node
            node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
        
            // Get the balance factor to check for unbalance
            int balance = getBalance(node);
        
            // Perform rotations to balance the tree
            // Left Left Case
            if (balance > 1 && key < node->left->key)
                return rightRotate(node);
        
            // Right Right Case
            if (balance < -1 && key > node->right->key)
                return leftRotate(node);
        
            // Left Right Case
            if (balance > 1 && key > node->left->key) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        
            // Right Left Case
            if (balance < -1 && key < node->right->key) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        
            return node;
        }
        
        // Function to find the node with the smallest key
        Node* minValueNode(Node* node) {
            Node* current = node;
            while (current->left != NULL)
                current = current->left;
            return current;
        }
        
        // Delete a node from the AVL Tree
        Node* deleteNode(Node* root, int key) {
            if (root == NULL)
                return root;
        
            if (key < root->key)
                root->left = deleteNode(root->left, key);
            else if (key > root->key)
                root->right = deleteNode(root->right, key);
            else {
                if (root->left == NULL || root->right == NULL) {
                    Node* temp = root->left ? root->left : root->right;
                    if (temp == NULL) {
                        temp = root;
                        root = NULL;
                    } else
                        *root = *temp;
        
                    free(temp);
                } else {
                    Node* temp = minValueNode(root->right);
                    root->key = temp->key;
                    root->right = deleteNode(root->right, temp->key);
                }
            }
        
            if (root == NULL)
                return root;
        
            root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
        
            int balance = getBalance(root);
        
            // Balance the tree
            if (balance > 1 && getBalance(root->left) >= 0)
                return rightRotate(root);
        
            if (balance > 1 && getBalance(root->left) < 0) {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        
            if (balance < -1 && getBalance(root->right) <= 0)
                return leftRotate(root);
        
            if (balance < -1 && getBalance(root->right) > 0) {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        
            return root;
        }
        
        // Function to perform in-order traversal
        void inOrderTraversal(Node* root) {
            if (root != NULL) {
                inOrderTraversal(root->left);
                printf("%d ", root->key);
                inOrderTraversal(root->right);
            }
        }
        
        int main() {
            Node* root = NULL;
        
            // Insert nodes
            root = insert(root, 10);
            root = insert(root, 20);
            root = insert(root, 30);
            root = insert(root, 40);
            root = insert(root, 50);
            root = insert(root, 25);
        
            printf("In-order Traversal after Insertions:\n");
            inOrderTraversal(root);
        
            // Delete a node
            root = deleteNode(root, 40);
            printf("\n\nIn-order Traversal after Deleting 40:\n");
            inOrderTraversal(root);
        
            return 0;
        }



// Output :
// In-order Traversal after Insertions:
// 10 20 25 30 40 50 

// In-order Traversal after Deleting 40:
// 10 20 25 30 50


/*

AVL Tree Operations
--- Insertion
      Insert the node as in a BST.
      Update the height of the ancestor nodes.
      Check the balance factor.
      Perform necessary rotations to restore balance.
--- Deletion
      Use the BST delete operation.
      Retrace the path back to the root, updating heights and balance factors.
      Perform rotations to restore balance.
      


Comparison with BST
BST: Can become unbalanced, leading to worst-case O(n) operations.
AVL Tree: Always balanced, ensuring O(logn) operations.


*/





