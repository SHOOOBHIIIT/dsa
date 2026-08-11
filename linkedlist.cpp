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

class ll{
    node* head;

public:
    ll(){
        head = NULL;
    }

    void pushfront(int val){
        node* n = new node(val);
        n->next = head;
        head = n;
    }

    void pushback(int val){
        node* n = new node(val);

        if(head == NULL){
            head = n;
            return;
        }
        node* t = head;
        while(t->next != NULL)
            t = t->next;
        t->next = n;
    }

    void insert(int val, int pos){
        if(pos == 0){
            pushfront(val);
            return;
        }
        node* t = head;
        for(int i = 0; i < pos-1 && t != NULL; i++)
         t = t->next;

        if(t == NULL){
            cout<<"position out of range\n";
            return;
        }
        node* n = new node(val);
        n->next = t->next;
        t->next = n;
    }

    void popfront(){
        if(head == NULL){
            cout << "list is empty\n";
            return;
        }
        node* t = head;
        head = head->next;
        delete t;
    }

    void popback(){
        if(head == NULL){
            cout<<"list is empty\n";
            return;
        }
        if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }
        node* t = head;
        while(t->next->next != NULL)
            t = t->next;
        delete t->next;
        t->next = NULL;
    }

    int search(int val){
        int i = 0;
        for(node* t = head; t != NULL; t = t->next){
            if(t->data == val)
                return i;
            i++;
        }
        return -1;
    }

    void delpos(int pos){
        if(head == NULL){
            cout << "list is empty\n";
            return;
        }
        if(pos == 0){
            popfront();
            return;
        }
        node* t = head;
        for(int i = 0; i < pos-1 && t->next != NULL; i++)
            t = t->next;

        if(t->next == NULL){
            cout << "position out of range\n";
            return;
        }
        node* d = t->next;
        t->next = d->next;
        delete d;
    }

    void print(){
        node* t = head;
        while(t != NULL){
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main()
{
    ll l;
    int ch, x, p;

    do{
        cout << "\n1.push front 2.push back 3.insert 4.pop front 5.pop back 6.search 7.delete at position 8.print 9.exit\n";
        cout << "choice: ";
        cin >> ch;

        switch(ch)
        {
        case 1: cout << "value: ";
                cin >> x;
                l.pushfront(x);
                l.print();
                break;

        case 2: cout << "value: ";
                cin >> x;
                l.pushback(x);
                l.print();
                break;

        case 3: cout << "value and position: ";
                cin >> x >> p;
                l.insert(x, p);
                l.print();
                break;

        case 4: l.popfront();
                l.print();
                break;

        case 5: l.popback();
             l.print();
             break;

        case 6: cout << "value to search: ";
                cin >> x;
                p = l.search(x);
                if(p == -1)
                    cout << "not found\n";
                else
                    cout << "found at index " << p << endl;
                break;

        case 7: cout << "position: ";
                cin >> p;
                l.delpos(p);
                l.print();
                break;

        case 8: l.print();
                break;
        }

    }while(ch != 9);

    return 0;
}
