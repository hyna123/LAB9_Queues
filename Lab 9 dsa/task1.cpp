#include <iostream>
using namespace std;

class LinearQueue {
private:
    static const int MaxSize = 5;  // Size of the queue
    int arr[MaxSize];              // Array to store queue elements
    int f;                      
    int r;                       

public:
    LinearQueue() {
        f = -1;  // Initialize front and rear to -1 (empty queue)
        r = -1;
    }

    // Check if the queue is empty
    bool Empty() const {
        return (f == -1 && r == -1);
    }

    // Check if the queue is full
    bool Full() const {
        return (r == MaxSize - 1);
    }

    // Add an element to the rear of the queue
    void Enqueue(int value) {
        if (Full()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        if (Empty()) {
            // If the queue is empty, set front and rear to 0
            f = 0;
            r = 0;
        } else {
            // Increment rear to add a new element
            r++;
        }
        arr[r] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Remove an element from the front of the queue
    void Dequeue() {
        if (Empty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[f] << endl;
        if (f == r) {
            // Reset front and rear to -1 when the last element is dequeued
            f = -1;
            r = -1;
        } else {
            // Move front to the next element
            f++;
        }
    }

    // Get the front element without removing it
    int getFront(){
        if (Empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[f];
    }

    // Display the elements of the queue
    void Display(){
        if (Empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = f; i <= r; i++) {
            cout << arr[i] << " ";
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
    q.Enqueue(6);  
    q.Display();

    return 0;
}
