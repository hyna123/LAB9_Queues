#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
// Constructor
    Node(int value){
        data = value;
        next = nullptr;
        }  
};

// LinearQueue class using a linked list
class LinearQueue {
private:
    Node* f;  // Points to the front of the queue
    Node* r;   // Points to the rear of the queue

public:
    // Constructor to initialize an empty queue
    LinearQueue() {
        f = nullptr;
        r = nullptr;
    }

    // Check if the queue is empty
    bool Empty(){
        return (f == nullptr);
    }

    // Enqueue operation 
    void Enqueue(int value) {
        Node* newNode = new Node(value);
        if (Empty()) {
            // If the queue is empty, both front and rear point to the new node
            f = r = newNode;
        } else {
            // Add the new node at the rear and update the rear pointer
            r->next = newNode;
            r = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation 
    void Dequeue() {
        if (Empty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        Node* temp = f;  // Store the current front node
        cout << "Dequeued: " << f->data << endl;
        f = f->next;  // Move front to the next node
        delete temp;          // Free the memory of the dequeued node

        if (f == nullptr) {
            // If the queue becomes empty, update rear to nullptr
            r = nullptr;
        }
    }

    // Get the front element without removing it
    int getFront(){
        if (Empty()) {
            cout << "Queue is empty!" << endl;
            return -1;  // Return -1 if the queue is empty
        }
        return f->data;
    }

    // Display the elements of the queue
    void Display(){
        if (Empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = f;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinearQueue q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Display();

    cout << "Front element: " << q.getFront() << endl;

    q.Dequeue();
    q.Display();

    q.Enqueue(4);
    q.Enqueue(5);
    q.Display();

    return 0;
}
