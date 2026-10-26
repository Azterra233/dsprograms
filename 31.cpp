// Linked list traversal recursive
#include <iostream>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Recursive function to traverse and print the linked list
void traverseRecursive(Node* current) {
    // Base case: if the current node is null, we've reached the end
    if (current == nullptr) {
        cout << "nullptr\n";
        return;
    }
    
    // Process current node
    cout << current->data << " -> ";
    
    // Recursive step: move to the next node
    traverseRecursive(current->next);
}

int main() {
    // Create nodes: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Traverse and print the list recursively
    traverseRecursive(head);

    return 0;
}