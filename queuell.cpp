#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class que{
    node* front;
    node* rear;

public:
    que(){
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
        rear = n;
    }

    void dequeue(){
        if(front == NULL)
        {
            cout << "queue is empty" << endl;
            return;
        }
        node* t = front;
        front = front->next;

        if(front == NULL)
            rear = NULL;

        delete t;
    }

    void printq(){
        node* t = front;
        while(t != NULL)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

int main(){
    que q;
    int n, x;

    cout << "how many values: ";
    cin >> n;
    cout << "enter values: ";
    for(int i=0; i<n; i++){
        cin >> x;
        q.enqueue(x);
    }

    cout << "queue is: ";
    q.printq();

    q.dequeue();
    q.dequeue();

    cout << "after 2 dequeues: ";
    q.printq();

    return 0;
}
