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

class dstk{
    node* top;

public:
    dstk(){
        top = NULL;
    }

    void push(int val)
    {
        node* n = new node(val);
        if(top == NULL){
            top = n;
            return;
        }
        n->next = top;
        top->prev = n;
        top = n;
    }

    void pop(){
        if(top == NULL){
            cout << "stack is empty\n";
            return;
        }
        node* t = top;
        top = top->next;
        if(top != NULL)
         top->prev = NULL;
        delete t;
    }

    void show()
    {
        node* t = top;
        while(t != NULL){
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

int main(){
    dstk s;

    s.push(7);
    s.push(1);
    s.push(3);
    s.push(6);
    cout<<"stack: ";
    s.show();

    s.pop();
    s.pop();
    cout << "after 2 pops: ";
    s.show();

    return 0;
}
