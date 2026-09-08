// Write a cppp to create and display a linked list
#include<iostream>
using namespace std;

class Linkedlist {
    struct node {
        int data;
        node *link;
    } *start, *newnode, *temp;                // structure variables
    
    public:
        Linkedlist();                       // default constructor
        void insert();                      // function prototype
        void display();
};

// Fixed constructor definition
Linkedlist::Linkedlist() {
    start = NULL;
    newnode = NULL;
    temp = NULL;
}

// Fixed scope resolution syntax for insert
void Linkedlist::insert() {
    int num;
    char ch = 'y';
    do {
        cout << "Enter the number: ";
        cin >> num;
        newnode = new node;
        newnode->data = num;  
        newnode->link = NULL;
        
        // Fixed assignment (=) to comparison (==)
        if (start == NULL) {
            start = temp = newnode;
        } else {
            temp->link = newnode;
            temp = newnode;
        }
        
        cout << "Do you wanna continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

// Fixed scope resolution syntax for display
void Linkedlist::display() {
    temp = start;
    if (start == NULL) {
        cout << "Linked list is empty\n";
    } else {
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->link;
        }
        cout << "\nEND\n";
    }
}

int main() {
    Linkedlist list;
    list.insert();
    list.display();
    return 0;
}