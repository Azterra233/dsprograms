// Operations on linked list - Insertion at beginning:
#include<iostream>
using namespace std;
int main(){
    class Linkedlist{
        struct Node{
            int data;
            Node *next;
        }*start=nullptr;
        
        // Insert at beginning
        void insert_beg(int item){
            Node* new_node = new Node;
            new_node -> data = item;
            new_node -> next = nullptr;
            new_node -> next = start;
            start = new_node;
        }

        // Insert at end
        void insert_end(int item){
            Node* new_node = new Node;              // Node creation
            new_node -> data = item;                // Node creation
            new_node -> next = nullptr;             // Node creation
            
            Node ;

        }

    };
}
