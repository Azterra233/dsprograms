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
    for (int i = 0; i < n; ++i) {
        std::cin >> val;
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Printing forward
    std::cout << "Forward:  ";
    for (Node* curr = head; curr; curr = curr->next)
        std::cout << curr->data << " <-> ";
    std::cout << "nullptr\n";

    // Printing backward
    std::cout << "Backward: ";
    for (Node* curr = tail; curr; curr = curr->prev)
        std::cout << curr->data << " <-> ";
    std::cout << "nullptr\n";

    return ;
}