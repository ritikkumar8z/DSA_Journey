// -------------------*  Hash Maps *------------------




/*
# Hash Maps
--- A Hash Map is a type of hash table data structure that efficiently holds key-value pairs. It allows for fast operations such as searching, adding, modifying, 
    and removing entries.

--- Hash Maps are particularly useful for retrieving detailed information associated with unique keys. For instance, a person can be looked up using a unique 
    identifier, such as a social security number (SSN), which serves as the key, and the person's details are the value.

# Key Components
i). Entry: A key-value pair in the Hash Map.
ii). Key: A unique identifier for each entry that generates a hash code to determine its bucket.
iii). Hash Code: A number generated from the key to find the appropriate bucket for the entry.
iv). Bucket: Containers that hold entries in the Hash Map.
v). Value: Information associated with the key, such as a name, address, etc.



# Hash Code Generation
--- The hash code is generated by a hash function. For example, for an SSN, you might sum the numerical values of the characters (ignoring non-numeric characters) 
    and apply a modulo operation to determine the bucket index.

Time Complexity
Average Case: O(1) for searching, adding, and removing entries.
Worst Case: O(n) if all entries hash to the same bucket, requiring linear search through that bucket.
*/

// Simple Hash Map

          #include <stdio.h>
          #include <stdlib.h>
          #include <string.h>
          
          #define SIZE 10  // Define the size of the hash map
          
          // Define a struct to represent each entry in the hash map
          typedef struct Entry {
              char *key;
              char *value;
              struct Entry *next;  // Pointer to handle collisions via chaining
          } Entry;
          
          // Define the hash map as an array of Entry pointers
          Entry *buckets[SIZE];
          
          // Hash function to compute the bucket index
          int hash_function(const char *key) {
              int sum = 0;
              while (*key) {
                  if (*key >= '0' && *key <= '9') {
                      sum += *key - '0';  // Sum only numeric characters
                  }
                  key++;
              }
              return sum % SIZE;
          }
          
          // Function to create a new entry
          Entry *create_entry(const char *key, const char *value) {
              Entry *new_entry = (Entry *)malloc(sizeof(Entry));
              new_entry->key = strdup(key);
              new_entry->value = strdup(value);
              new_entry->next = NULL;
              return new_entry;
          }
          
          // Function to add or update a key-value pair
          void put(const char *key, const char *value) {
              int index = hash_function(key);
              Entry *entry = buckets[index];
              
              // Check if the key already exists, update if it does
              while (entry != NULL) {
                  if (strcmp(entry->key, key) == 0) {
                      free(entry->value);
                      entry->value = strdup(value);
                      return;
                  }
                  entry = entry->next;
              }
              
              // If key does not exist, create a new entry and add it to the bucket
              Entry *new_entry = create_entry(key, value);
              new_entry->next = buckets[index];
              buckets[index] = new_entry;
          }
          
          // Function to retrieve a value by key
          char *get(const char *key) {
              int index = hash_function(key);
              Entry *entry = buckets[index];
              
              while (entry != NULL) {
                  if (strcmp(entry->key, key) == 0) {
                      return entry->value;
                  }
                  entry = entry->next;
              }
              return NULL;  // Key not found
          }
          
          // Function to remove a key-value pair
          void remove_entry(const char *key) {
              int index = hash_function(key);
              Entry *entry = buckets[index];
              Entry *prev = NULL;
              
              while (entry != NULL) {
                  if (strcmp(entry->key, key) == 0) {
                      if (prev == NULL) {
                          buckets[index] = entry->next;
                      } else {
                          prev->next = entry->next;
                      }
                      free(entry->key);
                      free(entry->value);
                      free(entry);
                      return;
                  }
                  prev = entry;
                  entry = entry->next;
              }
          }
          
          // Function to print the contents of the hash map
          void print_map() {
              printf("Hash Map Contents:\n");
              for (int i = 0; i < SIZE; i++) {
                  printf("Bucket %d: ", i);
                  Entry *entry = buckets[i];
                  while (entry != NULL) {
                      printf("(%s: %s) ", entry->key, entry->value);
                      entry = entry->next;
                  }
                  printf("\n");
              }
          }
          
          int main() {
              // Initialize the hash map (buckets are already NULL initially)
              
              // Add some entries
              put("123-4567", "Charlotte");
              put("123-4568", "Thomas");
              put("123-4569", "Jens");
              put("123-4570", "Peter");
              put("123-4571", "Lisa");
              put("123-4672", "Adele");
              put("123-4573", "Michaela");
              put("123-6574", "Bob");
          
              // Print the hash map
              print_map();
          
              // Retrieve a value
              printf("\nName associated with '123-4570': %s\n", get("123-4570"));
          
              // Update a value
              printf("Updating the name for '123-4570' to 'James'\n");
              put("123-4570", "James");
          
              // Retrieve updated value
              printf("Name associated with '123-4570': %s\n", get("123-4570"));
          
              // Clean up
              for (int i = 0; i < SIZE; i++) {
                  Entry *entry = buckets[i];
                  while (entry != NULL) {
                      Entry *temp = entry;
                      entry = entry->next;
                      free(temp->key);
                      free(temp->value);
                      free(temp);
                  }
              }
          
              return 0;
          }



// # Explanation of the Code :
// 1). Initialization: We define a hash map as an array of pointers to Entry structs. Each Entry struct has a key, value, and a pointer to the next entry in 
//     case of collisions (chaining).
// 2). Hash Function: The hash_function generates an index by summing the numeric values of characters in the key and taking modulo SIZE.
// 3). Adding/Updating: The put function adds a new entry or updates an existing key-value pair. If the key is not found, a new entry is created and added to the
//     beginning of the bucket’s list.
// 4). Retrieving Values: The get function searches for a key in the appropriate bucket and returns the associated value.
// 5). Removing Entries: The remove_entry function deletes a specified entry from the hash map.
// 6). Printing the Map: The print_map function displays all entries in each bucket.








