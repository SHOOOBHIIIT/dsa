#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class stk{
    node* top;

public:
    stk(){
        top = NULL;
    }

    void push(int val){
        node* n = new node(val);
        n->next = top;
        top = n;
    }

    void pop(){
        if(top == NULL){
            cout << "stack is empty\n";
            return;
        }
        node* t = top;
        cout << t->data << " popped" << endl;
        top = top->next;
        delete t;
    }

    void show(){
        if(top == NULL){
            cout << "stack empty\n";
            return;
        }
        node* t = top;
        while(t != NULL){
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

int main(){
    stk s;
    int n, x;

    cout << "how many values to push: ";
    cin >> n;
    cout << "enter values: ";
    for(int i = 0; i < n; i++){
        cin >> x;
        s.push(x);
    }

    cout << "stack now: ";
    s.show();

    s.pop();

    cout << "after one pop: ";
    s.show();

    return 0;
}
