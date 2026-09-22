#include <iostream>
using namespace std;

class Linkedlist {
private:
    struct Node {                       //creation
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
        
        // If the list is empty, make the new node the start
        if (start == nullptr) {
            start = new_node;
        } else {
            Node* temp = start;
            // Traverse to the last node
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // Attach new_node at the end
            temp->next = new_node;
        }
    }

    // Display function to test the list
    void display() {
        Node* temp = start;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
};

int main() {
    Linkedlist list;
    
    list.insert_end(10);
    list.insert_end(20);
    list.insert_beg(5);
    
    cout << "Linked List: ";
    list.display();
    
    return 0;
}