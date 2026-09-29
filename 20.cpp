// Menu driven insertion operation on LL
#include <iostream>
using namespace std;

class Linkedlist {
private:
    struct Node {
        int data;
        Node *next;
    } *start = nullptr;

public:
    // Insert at beginning
    void insert_beg(int item) {
        Node* new_node = new Node;
        new_node->data = item;
        new_node->next = start;
        start = new_node;
    }

    // Insert at end
    void insert_end(int item) {
        Node* new_node = new Node;              
        new_node->data = item;                
        new_node->next = nullptr;             

        if (start == nullptr) {
            start = new_node;
        } else {
            Node* temp = start;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    // Insert at a specific position (1-based index)
    void insert_pos(int item, int pos) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }

        // Inserting at position 1 is equivalent to insert_beg
        if (pos == 1) {
            insert_beg(item);
            return;
        }

        Node* temp = start;
        // Traverse to the (pos - 1)-th node
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        // If position is out of bounds
        if (temp == nullptr) {
            cout << "Position out of bounds!\n";
            return;
        }

        Node* new_node = new Node;
        new_node->data = item;
        new_node->next = temp->next;
        temp->next = new_node;
    }

    // Display function
    void display() {
        Node* temp = start;
        cout << "[";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << "]\n";
    }
};

int main() {
    Linkedlist list;
    int choice, value, pos;

    while (true) {
        cout << "\n--- Linked List Operations ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Specific Position\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            list.insert_beg(value);
        } else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            list.insert_end(value);
        } else if (choice == 3) {
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position (1-based): ";
            cin >> pos;
            list.insert_pos(value, pos);
        } else if (choice == 4) {
            cout << "Current Linked List: ";
            list.display();
        } else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}