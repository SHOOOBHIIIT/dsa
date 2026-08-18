#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class dque{
    node* front;
    node* rear;

public:
    dque(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val){
        node* n = new node(val);
        if(rear == NULL){
            front = rear = n;
            return;
        }
        rear->next = n;
        n->prev = rear;
        rear = n;
    }

    void dequeue(){
        if(front == NULL){
            cout << "queue is empty" << endl;
            return;
        }
        node* t = front;
        front = front->next;
        if(front != NULL)
            front->prev = NULL;
        else
            rear = NULL;
        delete t;
    }

    void show(){
        node* t = front;
        while(t != NULL){
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

int main(){
    dque q;

    q.enqueue(3);
    q.enqueue(9);
    q.enqueue(5);
    q.enqueue(7);
    cout << "queue: ";
    q.show();

    q.dequeue();
    q.dequeue();
    cout << "after 2 dequeues: ";
    q.show();

    return 0;
}
