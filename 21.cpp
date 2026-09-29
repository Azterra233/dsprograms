// Doubly Linked List
#include <iostream>

struct Node {
    int data;
    Node *prev = nullptr, *next = nullptr;
    Node(int val) : data(val) {}
};

int main() {
    int n, val;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    Node *head = nullptr, *tail = nullptr;

    // Reading elements
    std::cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        std::cin >> val;
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;                          //if head isn't nullptr, i.e this is the first node then....
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Printing 
    std::cout << "\nDoubly Linked list:\n ";
    std::cout<<"[";
    for (Node* curr = head; curr; curr = curr->next)
    std::cout << curr->data << " <-> ";
    std::cout << "nullptr";
    std::cout<<"]\n";
    
    return 0;
}

/*

Here is a detailed, line-by-line explanation of your C++ Doubly Linked List program:

---

### **1. Includes and Structure Definition**

* `// Doubly Linked List`
* A comment indicating that the program implements a doubly linked list data structure.


* `#include <iostream>`
* Includes the standard input/output stream library, allowing the program to use `std::cin` and `std::cout`.


* `struct Node {`
* Defines a custom data type named `Node` which represents a single element (or node) in the doubly linked list.


* `int data;`
* A member variable that stores the actual integer value inside the node.


* `Node *prev = nullptr, *next = nullptr;`
* Pointers to neighboring nodes: `prev` points to the previous node, and `next` points to the next node. Both are initialized to `nullptr` by default.


* `Node(int val) : data(val) {}`
* A constructor for the `Node` struct. When you create a new node, it automatically assigns the passed value (`val`) to `data`.



---

### **2. Main Function & Initialization**

* `int main() {`
* The main execution entry point where the program starts running.


* `int n, val;`
* Declares two integer variables: `n` for the total number of elements the user wants to input, and `val` to temporarily hold each element's value.


* `std::cout << "Enter number of elements: ";`
* Displays a prompt asking the user how many nodes they want to create.


* `std::cin >> n;`
* Reads the user's input and stores it in `n`.


* `Node *head = nullptr, *tail = nullptr;`
* Declares and initializes two pointers: `head` tracks the beginning of the list, and `tail` tracks the end. Both start as `nullptr` because the list is initially empty.



---

### **3. Reading and Building the List**

* `// Reading elements`
* A comment marking the input phase.


* `std::cout << "Enter values: ";`
* Prompts the user to type in the values for the elements.


* `for (int i = 0; i < n; i++) {`
* A loop that runs `n` times to read each value and insert it into the doubly linked list.


* `std::cin >> val;`
* Reads the current element value from the user into `val`.


* `Node* newNode = new Node(val);`
* Dynamically allocates memory in the heap to create a new `Node` containing the entered value.


* `if (!head) {`
* Checks if the list is currently empty (`head` is `nullptr`).


* `head = tail = newNode;`
* If it is the first node, both `head` and `tail` are pointed to this new node.


* `} else {`
* Executes if the list already contains one or more nodes.


* `tail->next = newNode;`
* Links the current last node (`tail`) forward to the new node.


* `newNode->prev = tail;`
* Links the new node backward to the previous tail node, completing the two-way connection.


* `tail = newNode;`
* Updates the `tail` pointer to point to the newly added node since it is now the last element.


* `}`
* Closes the `else` block and the `for` loop.



---

### **4. Printing the List**

* `// Printing`
* A comment marking the output phase.


* `std::cout << "\nDoubly Linked list:\n ";`
* Prints a label header for the final list visualization.


* `std::cout<<"[";`
* Prints an opening bracket to format the list nicely.


* `for (Node* curr = head; curr; curr = curr->next)`
* A traversal loop: starts at `head`, continues as long as `curr` is not `nullptr`, and moves forward using `curr = curr->next` at each iteration.


* `std::cout << curr->data << " <-> ";`
* Prints the current node's data followed by `<->` to show the bidirectional linking.


* `std::cout << "nullptr";`
* Prints `nullptr` at the end of the chain to show where the list terminates.


* `std::cout<<"]\n";`
* Prints a closing bracket and adds a newline.


* `return 0;`
* Signals that the program has executed successfully.


* `}`
* Closes the `main` function.

*/