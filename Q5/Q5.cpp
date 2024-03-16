// Q5 implementing queue as an ADT
#include <iostream>
#include <stdio.h>
using namespace std;

const int queueSize = 5;

template <class T>
class Queue {
private:
    int front = -1;
    int rear = -1;
    T queue[queueSize];

public:
    bool isQueueEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        } else {
            return false;
        }
    }

    bool isQueueFull() {
        if ((rear + 1) % queueSize == front) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(T element) {
        if (!isQueueFull()) {
            if (isQueueEmpty()) {
                front = 0;
                rear = 0;
            } else {
                rear = (rear + 1) % queueSize;
            }
            queue[rear] = element;
        } else {
            cout << "Queue Overflow error" << endl;
        }
    }

    void dequeue() {
        if (!isQueueEmpty()) {
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % queueSize;
            }
        } else {
            cout << "Queue Underflow error" << endl;
        }
    }

    void display() {
        if (!isQueueEmpty()) {
            int i = front;
            cout << "[ ";
            while (i != rear) {
                cout << queue[i] << ", ";
                i = (i + 1) % queueSize;
            }
            cout << queue[rear] << " ]" << endl;
        } else {
            cout << "The queue is empty, so no elements to display." << endl;
        }
    }

    T getFront() {
        if (!isQueueEmpty()) {
            return queue[front];
        } else {
            cout << "The queue is empty." << endl;
            return -1; // Return -1 for an empty queue (assuming T is int)
        }
    }
};

int main() {
    cout << "Program to implement the queue and its various operations" << endl;
    Queue<int> queueObject;
    char ans = 'y';
    while (ans == 'y' || ans == 'Y') {
        cout << "Available queue operations are:" << endl << endl;
        cout << "Check whether the queue is empty or not (1)" << endl;
        cout << "Check whether the queue is full or not (2)" << endl;
        cout << "Add an element to the queue (3)" << endl;
        cout << "Remove an element from the queue (4)" << endl;
        cout << "Display the front element of the queue (5)" << endl;
        cout << "Display the queue (6)" << endl << endl;
        cout << "Which operation do you want to perform -> ";
        char operation;
        cin >> operation;
        switch (operation) {
            case '1':
                if (queueObject.isQueueEmpty()) {
                    cout << "The queue is empty" << endl;
                } else {
                    cout << "The queue is not empty" << endl;
                }
                break;
            case '2':
                if (queueObject.isQueueFull()) {
                    cout << "The queue is full" << endl;
                } else {
                    cout << "The queue is not full" << endl;
                }
                break;
            case '3':
                int element;
                cout << "Enter the element you want to add: ";
                cin >> element;
                queueObject.enqueue(element);
                break;
            case '4':
                queueObject.dequeue();
                break;
            case '5':
                if (!queueObject.isQueueEmpty()) {
                    cout << "Front element is " << queueObject.getFront() << endl;
                }
                break;
            case '6':
                queueObject.display();
                break;
            default:
                cout << "Invalid queue operation" << endl;
                break;
        }
        do {
            cout << "Do you want to continue the program (Y/N): ";
            cin >> ans;
        } while (ans != 'n' && ans != 'N' && ans != 'y' && ans != 'Y');
        cout << endl;
    }
    if (ans == 'n' || ans == 'N') {
        cout << "-----------* Program Over *-----------" << endl;
    }
    return 0;
}
