// Write a cppp to create and display a linked list
#include<iostream>                      // Preprocessor directive that includes the standard Input/Output Stream library for using cout and cin
using namespace std;                    // Allows access to standard identifiers like cin, cout, and NULL without prefixing them with std::

class Linkedlist {                      // Declares a class named Linkedlist encapsulating the data structure and operations.
    struct node {                       // Defines a custom structure node representing a single element of the linked list. Private by default within the class.
        int data;                       // Integer variable storing data inside node
        node *link;                     // Self-referential pointer that stores the memory address of the next node in the sequence.
    } *start, *newnode, *temp;          // structure variables declaration 
// closes the struct definition and declares three member pointers to node:
// *start: Points to the first node (head) of the list.
// *newnode: Holds the address of newly allocated nodes.
// *temp: Temporary pointer used for traversing and building the list.
    public:                                 // Access specifier making subsequent members accessible outside the class.
        Linkedlist();                       // Default constructor; Constructor prototype called automatically when an object is instantiated.
        void insert();                      // Member function prototype to accept input and append nodes to the list.
        void display();                     // Member function prototype to traverse and print the elements.
};                                          // Terminates class definition

Linkedlist::Linkedlist() {                  //constructor definition using scope resolution operator
    start = NULL;                           //Initializes the head pointer to NULL, marking the list as initially empty.
    newnode = NULL;                         //Initializes the pointer to NULL to avoid dangling references.
    temp = NULL;                            //Initializes the helper pointer to NULL
}                                           //Closes the constructor block

void Linkedlist::insert() {                 //function definition for adding nodes
    int num;
    char ch = 'y';
    do {
        cout << "Enter the number: ";
        cin >> num;
        newnode = new node;                 //Dynamically allocates memory on the heap for a single node and assigns its address to newnode
        newnode->data = num;                //Assigns num to the data field of the new node
        newnode->link = NULL;               //Sets the new node's next pointer to NULL since it will be appended to the end
        if (start == NULL) {                //Checks whether the list is currently empty
            start = temp = newnode;         //If empty, points both start and temp to this first node.
        } else {                            //Runs if the list already contains at least one node.
            temp->link = newnode;           //Connects the current last node (temp) to the newly created node.
            temp = newnode;                 //Updates temp to point to the new end of the list.
        }      
        cout << "Do you wanna continue (y/n): ";        //Prompts the user whether to continue inserting nodes.
        cin >> ch;                                      //Reads the response character into ch.
    } while (ch == 'y');                                //Continues the loop if ch is 'y'.
}                                                       //Closes the insert() function.

void Linkedlist::display() {                            //Defines the traversal and display function.
    temp = start;
    if (start == NULL) {
        cout << "Linked list is empty\n";
    } else {
        cout<<"\nLinked List:\n";
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->link;
            if (temp != NULL) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

int main() {
    Linkedlist list;
    list.insert();
    list.display();
    return 0;
}

/*
Line by line explanation:

Header and Setup

#include<iostream>: Preprocessor directive that includes the standard Input/Output Stream library for using cout and cin.

using namespace std;: Allows access to standard identifiers like cin, cout, and NULL without prefixing them with std::.

Class Definition: Linkedlist

class Linkedlist {: Declares a class named Linkedlist encapsulating the data structure and operations.

struct node {: Defines a custom structure node representing a single element of the linked list. Private by default within the class.

int data;: Integer variable storing the payload or value inside the node.

node *link;: Self-referential pointer that stores the memory address of the next node in the sequence.

} *start, *newnode, *temp;: Closes the struct definition and declares three member pointers to node:

*start: Points to the first node (head) of the list.

*newnode: Holds the address of newly allocated nodes.

*temp: Temporary pointer used for traversing and building the list.

public:: Access specifier making subsequent members accessible outside the class.

Linkedlist();: Constructor prototype called automatically when an object is instantiated.

void insert();: Member function prototype to accept input and append nodes to the list.

void display();: Member function prototype to traverse and print the elements.

};: Terminates the class definition.

Constructor Definition

Linkedlist::Linkedlist() {: Definition of the constructor using the scope resolution operator ::.

start = NULL;: Initializes the head pointer to NULL, marking the list as initially empty.

newnode = NULL;: Initializes the pointer to NULL to avoid dangling references.

temp = NULL;: Initializes the helper pointer to NULL.

}: Closes the constructor block.

Insertion Logic: insert()

void Linkedlist::insert() {: Defines the function for adding nodes.

int num;: Stores the user's numeric input.

char ch = 'y';: Character variable controlling the continuation of the insertion loop, initialized to 'y'.

do {: Starts a do-while loop that executes at least once.

cout << "Enter the number: ";: Prompts the user to enter an integer.

cin >> num;: Reads the entered integer into num.

newnode = new node;: Dynamically allocates memory on the heap for a single node and assigns its address to newnode.

newnode->data = num;: Assigns num to the data field of the new node.

newnode->link = NULL;: Sets the new node's next pointer to NULL since it will be appended to the end.

if (start == NULL) {: Checks whether the list is currently empty.

start = temp = newnode;: If empty, points both start and temp to this first node.

} else {: Runs if the list already contains at least one node.

temp->link = newnode;: Connects the current last node (temp) to the newly created node.

temp = newnode;: Updates temp to point to the new end of the list.

}: Closes the if-else branch.

cout << "Do you wanna continue (y/n): ";: Prompts the user whether to continue inserting nodes.

cin >> ch;: Reads the response character into ch.

} while (ch == 'y');: Continues the loop if ch is 'y'.

}: Closes the insert() function.

Display Logic: display()

void Linkedlist::display() {: Defines the traversal and display function.

temp = start;: Points temp to the beginning of the list (start).

if (start == NULL) {: Checks if the list has no nodes.

cout << "Linked list is empty\n";: Informs the user that there is nothing to show.

} else {: Executes if the list has one or more nodes.

cout<<"\nLinked List:\n";: Prints a header message.

while (temp != NULL) {: Loops through the list node-by-node until reaching the end (NULL).

cout << temp->data;: Outputs the data value of the current node.

temp = temp->link;: Advances temp to point to the next node.

if (temp != NULL) {: Checks if there is another node ahead.

cout << " -> ";: Prints an arrow separator between elements.

}: Closes the inner conditional.

}: Closes the traversal loop.

cout << endl;: Prints a newline and flushes the output stream.

}: Closes the else block.

}: Closes the display() function.

Execution Entry Point: main()

int main() {: Main function where program execution starts.

Linkedlist list;: Instantiates an object named list, invoking the constructor.

list.insert();: Calls the insert() method on list to take user inputs.

list.display();: Calls the display() method to print the final linked list.

return 0;: Returns 0 to the operating system, indicating successful execution.

}: Closes the main() function.

*/
