// Menu driven operations on LL
#include <iostream>
using namespace std;

class Linkedlist {
private:
    struct Node {
        int data;
        Node *next;
    } *start = nullptr;

public:
    // --- INSERTION OPERATIONS ---
    // Insert at beginning
    void insert_beg(int item) {
        Node* new_node = new Node;
        new_node->data = item;
        new_node->next = start;
        start = new_node;
        cout << "Inserted " << item << " at the beginning.\n";
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
        cout << "Inserted " << item << " at the end.\n";
    }

    // Insert at a specific position (1-based index)
    void insert_pos(int item, int pos) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 1) {
            insert_beg(item);
            return;
        }

        Node* temp = start;
        // Traverse to the (pos - 1)-th node
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds!\n";
            return;
        }

        Node* new_node = new Node;
        new_node->data = item;
        new_node->next = temp->next;
        temp->next = new_node;
        cout << "Inserted " << item << " at position " << pos << ".\n";
    }

    // --- DELETION OPERATIONS ---
    // Delete from beginning
    void delete_beg() {
        if (start == nullptr) {
            cout << "List is empty! Nothing to delete.\n";
            return;
        }
        Node* temp = start;
        start = start->next;
        cout << "Deleted element: " << temp->data << " from the beginning.\n";
        delete temp;
    }

    // Delete from end
    void delete_end() {
        if (start == nullptr) {
            cout << "List is empty! Nothing to delete.\n";
            return;
        }

        // If there's only one node
        if (start->next == nullptr) {
            cout << "Deleted element: " << start->data << " from the end.\n";
            delete start;
            start = nullptr;
            return;
        }

        // Traverse to the second-to-last node
        Node* temp = start;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        Node* last = temp->next;
        cout << "Deleted element: " << last->data << " from the end.\n";
        temp->next = nullptr;
        delete last;
    }

    // Delete from a specific position (1-based index)
    void delete_pos(int pos) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }
        if (start == nullptr) {
            cout << "List is empty! Nothing to delete.\n";
            return;
        }

        if (pos == 1) {
            delete_beg();
            return;
        }

        Node* temp = start; 
        // Traverse to the (pos - 1)th node
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds!\n";
            return;
        }

        Node* target = temp->next;
        temp->next = target->next;
        cout << "Deleted element: " << target->data << " from position " << pos << ".\n";
        delete target;
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
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Specific Position\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insert_beg(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insert_end(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position (1-based): ";
                cin >> pos;
                list.insert_pos(value, pos);
                break;
            case 4:
                list.delete_beg();
                break;
            case 5:
                list.delete_end();
                break;
            case 6:
                cout << "Enter position (1-based) to delete: ";
                cin >> pos;
                list.delete_pos(pos);
                break;
            case 7:
                cout << "Current Linked List: ";
                list.display();
                break;
            case 8:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}