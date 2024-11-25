#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int MaxSize = 5;  // Size of the circular queue
    int arr[MaxSize];              // Array to store queue elements
    int f;                      
    int r;                     
    int count;                      // Number of elements in the queue

public:
    // Constructor to initialize the queue
    CircularQueue() {
        f = -1;
        r = -1;
        count = 0;
    }

    // Check if the queue is empty
    bool Empty(){
        return count == 0;
    }

    // Check if the queue is full
    bool Full(){
        return count == MaxSize;
    }

    // Add an element to the rear of the queue
    void Enqueue(int value) {
        if (Full()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }

        // If the queue is empty, set front and rear to 0
        if (Empty()) {
            f = 0;
            r = 0;
        } else {
            // Move rear to the next position
            r = (r + 1) % MaxSize;
        }
        arr[r] = value;
        count++;
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
            // Reset front and rear when the last element is dequeued
            f = -1;
            r = -1;
        } else {
            // Move front to the next position
            f = (f + 1) % MaxSize;
        }
        count--;
    }

    // Get the front element without removing it
    int getFront(){
        if (Empty()){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[f];
    }

    // Display the elements of the queue
    void Display(){
        if (Empty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(f + i) % MaxSize] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Display();

    q.Enqueue(6);  

    cout << "Front element: " << q.getFront() << endl;

    q.Dequeue();
    q.Dequeue();
    q.Display();

    q.Enqueue(6);
    q.Enqueue(7);
    q.Display();

    return 0;
}
