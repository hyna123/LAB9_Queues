#include <iostream>
using namespace std;

class PriorityQueue {
private:
    static const int MaxSize = 5;  
    int arr[MaxSize];              
    int r;                       // Points to the last element

public:
    // Constructor to initialize an empty queue
    PriorityQueue() {
        r = -1;  //the queue is empty
    }

    // Check if the queue is empty
    bool Empty(){
        return r == -1;
    }

    // Check if the queue is full
    bool Full(){
        return r == MaxSize - 1;
    }

    // Enqueue operation (add element at the rear)
    void Enqueue(int value) {
        if (Full()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        // Add the new element at the rear
        r++;
        arr[r] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation (remove the minimum element)
    void Dequeue() {
        if (Empty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        // Find the index of the minimum element
        int minIndex = 0;
        for (int i = 1; i <= r; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }

        // Remove the minimum element and shift others to the left
        cout << "Dequeued: " << arr[minIndex] << endl;
        for (int i = minIndex; i < r; i++) {
            arr[i] = arr[i + 1];
        }
        r--;  // Update rear
    }

    // Display the elements of the queue
    void Display(){
        if (Empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i <= r; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.Enqueue(6);
    pq.Enqueue(4);
    pq.Enqueue(2);
    pq.Enqueue(10);
    pq.Display();

    pq.Dequeue();  // Should remove the minimum element (2)
    pq.Display();

    return 0;
}
