#include <iostream>
using namespace std;

class LinearQueue {
    int arr[10];
    int cap;
    int front;
    int rear;

public:
    LinearQueue(int size) : cap(size), front(-1), rear(-1) {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    void enQueue(int value) {
        if (rear == cap - 1) {
            cout << "Queue is full" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = value;
    }

    void deQueue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }
};

int main() {
    LinearQueue lq(10);

    lq.enQueue(4);
    lq.enQueue(3);
    lq.enQueue(6);
    lq.enQueue(9);
    lq.enQueue(5);

    while (!lq.isEmpty()) {
        cout << lq.peek() << " ";
        lq.deQueue();
    }

    return 0;
}