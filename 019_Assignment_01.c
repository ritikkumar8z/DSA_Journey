// # Question 1 : Arrays - Operations and Properties


          #include <stdio.h>
          #define SIZE 10
          
          void insert(int arr[], int *n, int pos, int val);
          void delete(int arr[], int *n, int pos);
          void search(int arr[], int n, int val);
          void sort(int arr[], int n, int order);
          void display(int arr[], int n);
          
          int main() {
              int arr[SIZE] = {0}, n = 5;
              arr[0] = 20; arr[1] = 15; arr[2] = 30; arr[3] = 5; arr[4] = 10;
          
              printf("Initial Array: ");
              display(arr, n);
          
              insert(arr, &n, 2, 25);
              delete(arr, &n, 1);
              search(arr, n, 15);
              sort(arr, n, 1); // 1 for ascending
              sort(arr, n, 0); // 0 for descending
          
              return 0;
          }
          
          void insert(int arr[], int *n, int pos, int val) {
              if (*n >= SIZE) {
                  printf("Array is full.\n");
                  return;
              }
              for (int i = *n; i > pos; i--)
                  arr[i] = arr[i - 1];
              arr[pos] = val;
              (*n)++;
              printf("Array after insertion: ");
              display(arr, *n);
          }
          
          void delete(int arr[], int *n, int pos) {
              if (*n <= 0) {
                  printf("Array is empty.\n");
                  return;
              }
              for (int i = pos; i < *n - 1; i++)
                  arr[i] = arr[i + 1];
              (*n)--;
              printf("Array after deletion: ");
              display(arr, *n);
          }
          
          void search(int arr[], int n, int val) {
              for (int i = 0; i < n; i++) {
                  if (arr[i] == val) {
                      printf("Element %d found at position %d.\n", val, i);
                      return;
                  }
              }
              printf("Element %d not found.\n", val);
          }
          
          void sort(int arr[], int n, int order) {
              for (int i = 0; i < n - 1; i++) {
                  for (int j = i + 1; j < n; j++) {
                      if ((order == 1 && arr[i] > arr[j]) || (order == 0 && arr[i] < arr[j])) {
                          int temp = arr[i];
                          arr[i] = arr[j];
                          arr[j] = temp;
                      }
                  }
              }
              printf("Array after %s sorting: ", order == 1 ? "ascending" : "descending");
              display(arr, n);
          }
          
          void display(int arr[], int n) {
              for (int i = 0; i < n; i++)
                  printf("%d ", arr[i]);
              printf("\n");
          }


// # OUTPUT #
// Initial Array: 20 15 30 5 10 
// Array after insertion: 20 15 25 30 5 10 
// Array after deletion: 20 25 30 5 10 
// Element 15 not found.
// Array after ascending sorting: 5 10 20 25 30 
// Array after descending sorting: 30 25 20 10 5 

// === Code Execution Successful ===








# Question 2: Singly Linked List - Traversal, Insertion, and Deletion

          #include <stdio.h>
          #include <stdlib.h>
          
          struct Node {
              int data;
              struct Node* next;
          };
          
          void insertAtBeginning(struct Node** head, int data);
          void insertAtEnd(struct Node** head, int data);
          void insertAtPosition(struct Node** head, int data, int position);
          void deleteAtPosition(struct Node** head, int position);
          void search(struct Node* head, int data);
          void display(struct Node* head);
          
          int main() {
              struct Node* head = NULL;
          
              insertAtBeginning(&head, 10);
              insertAtEnd(&head, 20);
              insertAtPosition(&head, 15, 1);
              deleteAtPosition(&head, 2);
              search(head, 20);
              display(head);
          
              return 0;
          }
          
          void insertAtBeginning(struct Node** head, int data) {
              struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
              newNode->data = data;
              newNode->next = *head;
              *head = newNode;
          }
          
          void insertAtEnd(struct Node** head, int data) {
              struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
              newNode->data = data;
              newNode->next = NULL;
              if (*head == NULL) {
                  *head = newNode;
              } else {
                  struct Node* temp = *head;
                  while (temp->next != NULL)
                      temp = temp->next;
                  temp->next = newNode;
              }
          }
          
          void insertAtPosition(struct Node** head, int data, int position) {
              struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
              newNode->data = data;
              if (position == 0) {
                  newNode->next = *head;
                  *head = newNode;
              } else {
                  struct Node* temp = *head;
                  for (int i = 0; temp != NULL && i < position - 1; i++)
                      temp = temp->next;
                  newNode->next = temp->next;
                  temp->next = newNode;
              }
          }
          
          void deleteAtPosition(struct Node** head, int position) {
              if (*head == NULL) return;
              struct Node* temp = *head;
              if (position == 0) {
                  *head = temp->next;
                  free(temp);
              } else {
                  for (int i = 0; temp != NULL && i < position - 1; i++)
                      temp = temp->next;
                  struct Node* nextNode = temp->next->next;
                  free(temp->next);
                  temp->next = nextNode;
              }
          }
          
          void search(struct Node* head, int data) {
              int position = 0;
              while (head != NULL) {
                  if (head->data == data) {
                      printf("Element %d found at position %d.\n", data, position);
                      return;
                  }
                  head = head->next;
                  position++;
              }
              printf("Element %d not found.\n", data);
          }
          
          void display(struct Node* head) {
              while (head != NULL) {
                  printf("%d -> ", head->data);
                  head = head->next;
              }
              printf("NULL\n");
          }


# OUTPUT #
Pushed 10 onto stack
Pushed 20 onto stack
Pushed 30 onto stack
Popped 30 from stack
Top element is 20

=== Code Execution Successful ===







# Question 3: Stack - Implementation Using Array

          #include <stdio.h>
          #define SIZE 5
          
          int stack[SIZE], top = -1;
          
          void push(int val);
          void pop();
          void peek();
          int isEmpty();
          int isFull();
          
          int main() {
              push(10);
              push(20);
              push(30);
              pop();
              peek();
              return 0;
          }
          
          void push(int val) {
              if (isFull())
                  printf("Stack Overflow\n");
              else {
                  stack[++top] = val;
                  printf("Pushed %d onto stack\n", val);
              }
          }
          
          void pop() {
              if (isEmpty())
                  printf("Stack Underflow\n");
              else
                  printf("Popped %d from stack\n", stack[top--]);
          }
          
          void peek() {
              if (isEmpty())
                  printf("Stack is empty\n");
              else
                  printf("Top element is %d\n", stack[top]);
          }
          
          int isEmpty() {
              return top == -1;
          }
          
          int isFull() {
              return top == SIZE - 1;
          }


# OUTPUT #
Pushed 10 onto stack
Pushed 20 onto stack
Pushed 30 onto stack
Popped 30 from stack
Top element is 20

=== Code Execution Successful ===







# Question 4: Queue - Implementation Using Array

          #include <stdio.h>
          #define SIZE 5
          
          int queue[SIZE], front = -1, rear = -1;
          
          void enqueue(int val);
          void dequeue();
          void peek();
          int isEmpty();
          int isFull();
          
          int main() {
              enqueue(10);
              enqueue(20);
              enqueue(30);
              dequeue();
              peek();
              return 0;
          }
          
          void enqueue(int val) {
              if (isFull())
                  printf("Queue Overflow\n");
              else {
                  if (front == -1) front = 0;
                  queue[++rear] = val;
                  printf("Enqueued %d into queue\n", val);
              }
          }
          
          void dequeue() {
              if (isEmpty())
                  printf("Queue Underflow\n");
              else {
                  printf("Dequeued %d from queue\n", queue[front]);
                  if (front == rear) {
                      front = rear = -1;  // reset queue when empty
                  } else {
                      front++;
                  }
              }
          }
          
          void peek() {
              if (isEmpty())
                  printf("Queue is empty\n");
              else
                  printf("Front element is %d\n", queue[front]);
          }
          
          int isEmpty() {
              return front == -1;
          }
          
          int isFull() {
              return rear == SIZE - 1;
          }



# OUTPUT #

Enqueued 10 into queue
Enqueued 20 into queue
Enqueued 30 into queue
Dequeued 10 from queue
Front element is 20

=== Code Execution Successful ===






# Question 5: Applications of Stacks and Queues
----- Stack Application - Parentheses Matching & Queue Application - Ticket Booking Simulation -----

          #include <stdio.h>
          #include <string.h>
          
          #define STACK_SIZE 100
          #define QUEUE_SIZE 5
          
          // Stack for parentheses matching
          char stack[STACK_SIZE];
          int top = -1;
          
          void push(char c);
          void pop();
          int isEmpty();
          int isBalanced(char* expr);
          
          // Queue for ticket booking simulation
          int queue[QUEUE_SIZE], front = -1, rear = -1;
          
          void enqueue(int customerID);
          void dequeue();
          void displayQueue();
          int isQueueEmpty();
          int isQueueFull();
          
          int main() {
              int choice, customerID;
              char expr[STACK_SIZE];
          
              while (1) {
                  printf("\nMenu:\n");
                  printf("1. Check Balanced Parentheses\n");
                  printf("2. Ticket Booking Queue Simulation\n");
                  printf("3. Exit\n");
                  printf("Enter your choice: ");
                  scanf("%d", &choice);
          
                  switch (choice) {
                      case 1:
                          printf("Enter an expression with parentheses: ");
                          scanf(" %[^\n]%*c", expr);  // To handle spaces in input
                          if (isBalanced(expr))
                              printf("The expression is balanced.\n");
                          else
                              printf("The expression is not balanced.\n");
                          break;
          
                      case 2:
                          printf("\nTicket Booking Queue Menu:\n");
                          printf("1. Add Customer to Queue\n");
                          printf("2. Serve Customer\n");
                          printf("3. Display Queue\n");
                          printf("4. Go Back to Main Menu\n");
          
                          int queueChoice;
                          while (1) {
                              printf("Enter choice for queue operations: ");
                              scanf("%d", &queueChoice);
          
                              if (queueChoice == 1) {
                                  printf("Enter customer ID to add to queue: ");
                                  scanf("%d", &customerID);
                                  enqueue(customerID);
                              } else if (queueChoice == 2) {
                                  dequeue();
                              } else if (queueChoice == 3) {
                                  displayQueue();
                              } else if (queueChoice == 4) {
                                  break;
                              } else {
                                  printf("Invalid choice. Try again.\n");
                              }
                          }
                          break;
          
                      case 3:
                          printf("Exiting program.\n");
                          return 0;
          
                      default:
                          printf("Invalid choice. Try again.\n");
                  }
              }
              return 0;
          }
          
          // Stack operations for parentheses matching
          void push(char c) {
              if (top < STACK_SIZE - 1) {
                  stack[++top] = c;
              }
          }
          
          void pop() {
              if (!isEmpty()) {
                  top--;
              }
          }
          
          int isEmpty() {
              return top == -1;
          }
          
          int isBalanced(char* expr) {
              top = -1; // Reset the stack for new expression
              for (int i = 0; i < strlen(expr); i++) {
                  if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
                      push(expr[i]);
                  } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
                      if (isEmpty())
                          return 0;
                      char open = stack[top];
                      if ((expr[i] == ')' && open == '(') ||
                          (expr[i] == '}' && open == '{') ||
                          (expr[i] == ']' && open == '[')) {
                          pop();
                      } else {
                          return 0;
                      }
                  }
              }
              return isEmpty();
          }
          
          // Queue operations for ticket booking
          void enqueue(int customerID) {
              if (isQueueFull()) {
                  printf("Queue is full. No more customers can join.\n");
              } else {
                  if (front == -1) front = 0;
                  queue[++rear] = customerID;
                  printf("Customer %d joined the queue\n", customerID);
              }
          }
          
          void dequeue() {
              if (isQueueEmpty()) {
                  printf("Queue is empty. No customers to serve.\n");
              } else {
                  printf("Customer %d is served and leaves the queue\n", queue[front]);
                  if (front == rear) {
                      front = rear = -1; // Reset queue when empty
                  } else {
                      front++;
                  }
              }
          }
          
          void displayQueue() {
              if (isQueueEmpty()) {
                  printf("Queue is empty.\n");
              } else {
                  printf("Current queue: ");
                  for (int i = front; i <= rear; i++)
                      printf("%d ", queue[i]);
                  printf("\n");
              }
          }
          
          int isQueueEmpty() {
              return front == -1;
          }
          
          int isQueueFull() {
              return rear == QUEUE_SIZE - 1;
          }



# OUTPUT #

Menu:
1. Check Balanced Parentheses
2. Ticket Booking Queue Simulation
3. Exit
Enter your choice: 1
Enter an expression with parentheses: (a+b
The expression is not balanced.

Menu:
1. Check Balanced Parentheses
2. Ticket Booking Queue Simulation
3. Exit
Enter your choice: 1
Enter an expression with parentheses: a(a+b)
The expression is balanced.

Menu:
1. Check Balanced Parentheses
2. Ticket Booking Queue Simulation
3. Exit
Enter your choice: 2

Ticket Booking Queue Menu:
1. Add Customer to Queue
2. Serve Customer
3. Display Queue
4. Go Back to Main Menu
Enter choice for queue operations: 1
Enter customer ID to add to queue: 121
Customer 121 joined the queue
Enter choice for queue operations: 1
Enter customer ID to add to queue: 122
Customer 122 joined the queue
Enter choice for queue operations: 1
Enter customer ID to add to queue: 123
Customer 123 joined the queue
Enter choice for queue operations: 3
Current queue: 121 122 123 
Enter choice for queue operations: 2
Customer 121 is served and leaves the queue
Enter choice for queue operations: 3
Current queue: 122 123 
Enter choice for queue operations: 2
Customer 122 is served and leaves the queue
Enter choice for queue operations: 3
Current queue: 123 
Enter choice for queue operations: 








