/*
Traversals in Binary Tree

Traversal refers to the process of visiting every node of a binary tree in a specific order. Different traversal techniques are used depending on the order in which nodes need to be processed.

Common Traversal Techniques

    Inorder Traversal (Left -> Root -> Right): Visits the left subtree first, then the root node, and finally the right subtree
    Preorder Traversal (Root -> Left -> Right): Visits the root node first, followed by the left and right subtrees
    Postorder Traversal (Left -> Right -> Root): Visits both subtrees before processing the root node
    Level Order Traversal : Visits nodes level by level from top to bottom, moving from left to right within each level
*/
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

// Preorder Traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (!root) return;
    std::cout << root->data << " ";
    preorder(root->leftChild);
    preorder(root->rightChild);
}

// Inorder Traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (!root) return;
    inorder(root->leftChild);
    std::cout << root->data << " ";
    inorder(root->rightChild);
}

// Postorder Traversal: Left -> Right -> Root
void postorder(Node* root) {
    if (!root) return;
    postorder(root->leftChild);
    postorder(root->rightChild);
    std::cout << root->data << " ";
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

    // Traversals
    std::cout << "Preorder:  ";
    preorder(root);
    std::cout << "\n";

    std::cout << "Inorder:   ";
    inorder(root);
    std::cout << "\n";

    std::cout << "Postorder: ";
    postorder(root);
    std::cout << "\n";

    return 0;
}