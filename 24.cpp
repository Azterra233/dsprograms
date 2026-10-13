// Dequeue using array

#include <iostream>
using namespace std;

#define MAX 5 // Maximum size of the dequeue

class Dequeue {
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    Dequeue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isFull() {
        return (size == MAX);
    }

    bool isEmpty() {
        return (size == 0);
    }

    // Insert element at the front
    void insertFront(int key) {
        if (isFull()) {
            cout << "Overflow! Dequeue is full.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = MAX - 1; // Wrap around
        } else {
            front = front - 1;
        }

        arr[front] = key;
        size++;
        cout << "Inserted " << key << " at the front.\n";
    }

    // Insert element at the rear
    void insertRear(int key) {
        if (isFull()) {
            cout << "Overflow! Dequeue is full.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0; // Wrap around
        } else {
            rear = rear + 1;
        }

        arr[rear] = key;
        size++;
        cout << "Inserted " << key << " at the rear.\n";
    }

    // Delete element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow! Dequeue is empty.\n";
            return;
        }

        cout << "Deleted " << arr[front] << " from the front.\n";

        if (front == rear) {
            // Queue has only one element
            front = -1;
            rear = -1;
        } else if (front == MAX - 1) {
            front = 0; // Wrap around
        } else {
            front = front + 1;
        }
        size--;
    }

    // Delete element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow! Dequeue is empty.\n";
            return;
        }

        cout << "Deleted " << arr[rear] << " from the rear.\n";

        if (front == rear) {
            // Queue has only one element
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1; // Wrap around
        } else {
            rear = rear - 1;
        }
        size--;
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // Get the rear element
    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    // Display elements of the circular dequeue from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Dequeue is empty!\n";
            return;
        }

        cout << "\nDequeue elements (Front to Rear): ";
        int i = front;
        cout<<"[";
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
            break;
            i = (i + 1) % MAX; // Circular increment
        }
        cout<<"]\n";
    }
};

int main() {
    Dequeue dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    
    dq.display(); 

    dq.deleteFront();
    dq.display(); 

    dq.insertRear(30);
    dq.insertRear(40);
    dq.display(); 

    return 0;
}