// -----------------------* Hash Tables *----------------------


/*
# Hash Tables

# Introduction
--- A Hash Table is a data structure optimized for fast data access. Unlike arrays and linked lists, where searching, adding, or deleting 
    elements can take time, hash tables can perform these operations swiftly, even with large datasets. This speed is achieved through hashing: 
    a process that allows direct access to elements using a hash function.


In this tutorial, we’ll build a simple Hash Set (a version of a Hash Table that stores unique elements) in C, covering the following steps:

1. Starting with an array.
2. Storing values using a hash function.
3. Looking up values.
4. Handling collisions with chaining.
5. Complete Hash Set code example.



Step 1: Starting with an Array
--- We begin with an array to store unique names. Let’s assume a maximum of 10 names, resulting in an array of fixed size 10. 
    Each element of the array is referred to as a bucket.

    char* hash_set[10] = {NULL}; // Initial empty hash set

Example Output:
    hash_set = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}


Step 2: Storing Values Using a Hash Function
--- A hash function determines the bucket where each name is stored. For simplicity, our hash function will:

    Sum the Unicode values of the characters in the name.
    Apply modulo 10 to limit the result to 0–9 (the array indices).


Code Example:
*/
          #include <stdio.h>
          #include <string.h>
          
          int hash_function(char *value) {
              int sum = 0;
              for (int i = 0; i < strlen(value); i++) {
                  sum += value[i];
              }
              return sum % 10;
          }
          
          int main() {
              printf("'Bob' has hash code: %d\n", hash_function("Bob"));
              return 0;
          }

// Example Output:
// 'Bob' has hash code: 5


// Step 3: Looking Up a Value
// --- Instead of scanning the array, we can go directly to a bucket using the hash function to check if a name exists in the hash set.

// Code Example:

        #include <stdio.h>
        #include <string.h>
        
        char* hash_set[10] = {NULL};
        
        int hash_function(char *value) {
            int sum = 0;
            for (int i = 0; i < strlen(value); i++) {
                sum += value[i];
            }
            return sum % 10;
        }
        
        void add(char *value) {
            int index = hash_function(value);
            hash_set[index] = value; // Assuming no collision handling for now
        }
        
        int contains(char *value) {
            int index = hash_function(value);
            return hash_set[index] != NULL && strcmp(hash_set[index], value) == 0;
        }
        
        int main() {
            add("Pete");
            printf("Contains 'Pete': %s\n", contains("Pete") ? "Yes" : "No");
            printf("Contains 'Bob': %s\n", contains("Bob") ? "Yes" : "No");
            return 0;
        }


// Example Output:

// Contains 'Pete': Yes
// Contains 'Bob': No



// Step 4: Handling Collisions with Chaining
// --- Collisions occur when two values hash to the same index. To handle these, we’ll implement chaining by using an array of linked lists for each bucket. 
//     This allows multiple elements to coexist in the same bucket.

// Code Example:

          #include <stdio.h>
          #include <stdlib.h>
          #include <string.h>
          
          #define TABLE_SIZE 10
          
          typedef struct Node {
              char* value;
              struct Node* next;
          } Node;
          
          Node* hash_table[TABLE_SIZE] = {NULL};
          
          int hash_function(char *value) {
              int sum = 0;
              for (int i = 0; i < strlen(value); i++) {
                  sum += value[i];
              }
              return sum % TABLE_SIZE;
          }
          
          void add(char *value) {
              int index = hash_function(value);
              Node* new_node = malloc(sizeof(Node));
              new_node->value = value;
              new_node->next = hash_table[index];
              hash_table[index] = new_node;
          }
          
          int contains(char *value) {
              int index = hash_function(value);
              Node* current = hash_table[index];
              while (current != NULL) {
                  if (strcmp(current->value, value) == 0) {
                      return 1;
                  }
                  current = current->next;
              }
              return 0;
          }
          
          int main() {
              add("Lisa");
              add("Stuart"); // Causes a collision with Lisa
          
              printf("Contains 'Lisa': %s\n", contains("Lisa") ? "Yes" : "No");
              printf("Contains 'Stuart': %s\n", contains("Stuart") ? "Yes" : "No");
          
              return 0;
          }



// Example Output:
// Contains 'Lisa': Yes
// Contains 'Stuart': Yes



// Step 5: Complete Hash Set Code Example
// --- Here’s the full code for adding, searching, and displaying the hash set using chaining for collision handling.

            #include <stdio.h>
            #include <stdlib.h>
            #include <string.h>
            
            #define TABLE_SIZE 10
            
            typedef struct Node {
                char* value;
                struct Node* next;
            } Node;
            
            Node* hash_table[TABLE_SIZE] = {NULL};
            
            int hash_function(char *value) {
                int sum = 0;
                for (int i = 0; i < strlen(value); i++) {
                    sum += value[i];
                }
                return sum % TABLE_SIZE;
            }
            
            void add(char *value) {
                int index = hash_function(value);
                Node* new_node = malloc(sizeof(Node));
                new_node->value = value;
                new_node->next = hash_table[index];
                hash_table[index] = new_node;
            }
            
            int contains(char *value) {
                int index = hash_function(value);
                Node* current = hash_table[index];
                while (current != NULL) {
                    if (strcmp(current->value, value) == 0) {
                        return 1;
                    }
                    current = current->next;
                }
                return 0;
            }
            
            void display() {
                for (int i = 0; i < TABLE_SIZE; i++) {
                    printf("Bucket %d: ", i);
                    Node* current = hash_table[i];
                    while (current != NULL) {
                        printf("%s -> ", current->value);
                        current = current->next;
                    }
                    printf("NULL\n");
                }
            }
            
            int main() {
                add("Lisa");
                add("Stuart");
                add("Jones");
                
                printf("Contains 'Lisa': %s\n", contains("Lisa") ? "Yes" : "No");
                printf("Contains 'Stuart': %s\n", contains("Stuart") ? "Yes" : "No");
            
                display();
                return 0;
            }


// Example Output:

// Contains 'Lisa': Yes
// Contains 'Stuart': Yes
// Bucket 0: NULL
// Bucket 1: Jones -> NULL
// Bucket 2: NULL
// Bucket 3: Lisa -> Stuart -> NULL
// ...



// Key Points and Summary :
// --- Hash Tables are efficient for searching, inserting, and deleting, with an average O(1) time complexity.
// --- Hash Sets store unique elements, ideal for quick membership tests.
// --- Hash Maps use key-value pairs, where each key is unique, allowing fast retrieval based on the key.
// --- Collision Handling is essential. Chaining and Open Addressing are two methods; we used chaining here.

