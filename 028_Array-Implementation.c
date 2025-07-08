// ---------------------* Array Implementation *---------------------



/*
# Array Implementation of Binary Trees

Key Points
a). Concept: Binary Trees can be implemented using arrays, which are ideal for "perfect" or "nearly perfect" trees.
b). Advantages:
      Reduces memory cost compared to pointer-based implementations.
      Faster traversal due to cache locality as arrays store elements contiguously in memory.
c). Indexing Rules:
      For a node at index i:
      Left Child: 2 * i + 1
      Right Child: 2 * i + 2
d). Limitations:
      Requires extra space for empty elements for trees that are not complete.


Example Binary Tree
        
                 R
               /   \
              A     B
             / \   / \
            C   D E   F
Array Representation:
['R', 'A', 'B', 'C', 'D', 'E', 'F']

*/


// Example: Array Representation of Binary Tree with Traversals

        #include <stdio.h>
        
        #define SIZE 7
        
        char binary_tree[SIZE] = {'R', 'A', 'B', 'C', 'D', 'E', 'F'};
        
        // Function to find left child index
        int left_child_index(int index) {
            return 2 * index + 1;
        }
        
        // Function to find right child index
        int right_child_index(int index) {
            return 2 * index + 2;
        }
        
        // Pre-order Traversal
        void pre_order(int index) {
            if (index >= SIZE || binary_tree[index] == '\0') return;
        
            printf("%c ", binary_tree[index]); // Visit root
            pre_order(left_child_index(index)); // Traverse left subtree
            pre_order(right_child_index(index)); // Traverse right subtree
        }
        
        // In-order Traversal
        void in_order(int index) {
            if (index >= SIZE || binary_tree[index] == '\0') return;
        
            in_order(left_child_index(index)); // Traverse left subtree
            printf("%c ", binary_tree[index]); // Visit root
            in_order(right_child_index(index)); // Traverse right subtree
        }
        
        // Post-order Traversal
        void post_order(int index) {
            if (index >= SIZE || binary_tree[index] == '\0') return;
        
            post_order(left_child_index(index)); // Traverse left subtree
            post_order(right_child_index(index)); // Traverse right subtree
            printf("%c ", binary_tree[index]); // Visit root
        }
        
        int main() {
            printf("Pre-order Traversal: ");
            pre_order(0);
            printf("\n");
        
            printf("In-order Traversal: ");
            in_order(0);
            printf("\n");
        
            printf("Post-order Traversal: ");
            post_order(0);
            printf("\n");
        
            return 0;
        }


// Output

// Pre-order Traversal: R A C D B E F 
// In-order Traversal: C A D R E B F 
// Post-order Traversal: C D A E F B R

// This implementation highlights efficient traversal in an array-based Binary Tree.



