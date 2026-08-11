#include<iostream>
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

class dll{
    node* head;
    node* tail;

public:
    dll(){
        head = NULL;
        tail = NULL;
    }

    void pushfront(int val){
        node* n = new node(val);
        if(head == NULL){
            head = tail = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void pushback(int val)
    {
        node* n = new node(val);
        if(tail == NULL){
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void insert(int val, int pos){
        if(pos == 0){
            pushfront(val);
            return;
        }
        node* t = head;
        for(int i = 0; i < pos-1 && t != NULL; i++)
            t = t->next;

        if(t == NULL || t->next == NULL){
            pushback(val);
            return;
        }

        node* n = new node(val);
        n->next = t->next;
        n->prev = t;
        t->next->prev = n;
        t->next = n;
    }

    void popfront(){
        if(head == NULL){
            cout << "list is empty\n";
            return;
        }
        node* t = head;
        head = head->next;
        if(head != NULL)
         head->prev = NULL;
        else
         tail = NULL;
        delete t;
    }

    void popback(){
        if(tail == NULL){
            cout << "list is empty" << endl;
            return;
        }
        node* t = tail;
        tail = tail->prev;
        if(tail != NULL)
            tail->next = NULL;
        else
            head = NULL;
        delete t;
    }

    void print(){
        node* t = head;
        while(t != NULL){
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

int main()
{
    dll d;

    d.pushfront(4);
    d.pushfront(7);
    d.pushfront(9);
    cout<<"after 3 push front: ";
    d.print();

    d.pushback(1);
    d.pushback(5);
    cout << "after 2 push back: ";
    d.print();

    d.insert(10, 2);
    cout << "after insert at pos 2: ";
    d.print();

    d.popfront();
    d.popfront();
    cout << "after 2 pop front: ";
    d.print();

    d.popback();
    d.popback();
    cout << "after 2 pop back: ";
    d.print();

    return 0;
}
