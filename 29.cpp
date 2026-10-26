// Menu driven operations on doubly LL
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev = nullptr, *next = nullptr;
    Node(int val) : data(val) {} 
};

// Insert at the beginning of the list
void insert_beg(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    cout << val << " inserted at the beginning.\n";
}

// Insert at the end of the list
void insert_end(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << val << " inserted at the end.\n";
}

// Delete from the beginning of the list
void delete_beg(Node*& head, Node*& tail) {
    if (!head) {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    cout << temp->data << " deleted from the beginning.\n";
    delete temp;
}

// Delete from the end of the list
void delete_end(Node*& head, Node*& tail) {                         //Node*& pass by reference(change fr), Node* pass by value(only copy change)
    if (!tail) {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }
    Node* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    cout << temp->data << " deleted from the end.\n";
    delete temp;
}

// Display the list forward
void displayForward(Node* head) {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }
    cout << "Forward: [ ";
    for (Node* curr = head; curr; curr = curr->next) {
        cout << curr->data;
        if (curr->next) cout << " <-> ";
    }
    cout << " <-> nullptr]\n";
}

// Display the list backward using the tail and prev pointers
void displayBackward(Node* tail) {
    if (!tail) {
        cout << "List is empty!\n";
        return;
    }
    cout << "Backward: [nullptr <-> ";
    for (Node* curr = tail; curr; curr = curr->prev) {
        cout << curr->data;
        if (curr->prev) cout << " <-> ";
    }
    cout << " ]\n";
}

int main() {
    Node *head = nullptr, *tail = nullptr;
    int choice, val;

    do {
        cout << "\n--- Doubly Linked List Operations ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display Forward\n";
        cout << "6. Display Backward\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                insert_beg(head, tail, val);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                insert_end(head, tail, val);
                break;
            case 3:
                delete_beg(head, tail);
                break;
            case 4:
                delete_end(head, tail);
                break;
            case 5:
                displayForward(head);
                break;
            case 6:
                displayBackward(tail);
                break;
            case 7:
                cout << "Exiting program. Cleaning up memory...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 7.\n";
        }
    } while (choice != 7);

    // Free remaining allocated memory to avoid memory leaks
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}