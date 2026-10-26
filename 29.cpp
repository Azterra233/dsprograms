// Linked list traversal iterative
#include <iostream>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to traverse and print the linked list
void traverseLinkedList(Node* head) {
    Node* temp = head;
    cout<<"[ ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr]\n";
}

int main() {
    cout<<"Linked List:\n";
    // Create nodes: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Traverse and print the list
    traverseLinkedList(head);

    return 0;
}