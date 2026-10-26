#include <iostream>

struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;
    
    explicit Node(int val) : data(val), leftChild(nullptr), rightChild(nullptr) {}
};

// Helper function to create a new node
Node* newNode(int val) {
    return new Node(val);
}

int main() {
    /* 
       Constructing a sample binary tree:
            10
           /  \
          20   30
         /  \
        40   50
    */

    Node* root = newNode(10);
    
    root->leftChild = newNode(20);
    root->rightChild = newNode(30);
    
    root->leftChild->leftChild = newNode(40);
    root->leftChild->rightChild = newNode(50);

    // Verifying structure
    std::cout << "Root: " << root->data << "\n";
    std::cout << "Left Child: " << root->leftChild->data << "\n";
    std::cout << "Right Child: " << root->rightChild->data << "\n";
    std::cout << "Left's Left Child: " << root->leftChild->leftChild->data << "\n";
    std::cout << "Left's Right Child: " << root->leftChild->rightChild->data << "\n";

    return 0;
}