#include <iostream>
using namespace std;

class node {
public:
    int data;
    int index;
    node* next;

    node(int val) {
        data = val;
        index = 0;
        next = NULL;
    }
};

class list {
    node* head;

public:
    node* tail;

    list() {
        head = NULL;
        tail = NULL;
    }

    void add(int val) {
        node* n = new node(val);

        if (head == NULL) {
            head = n;
            tail = n;
            n->index = 1;
            return;
        }

        n->index = tail->index + 1;

        tail->next = n;
        tail = n;
    }

    node* goto_index(int index) {
        node* t = head;

        while (t != NULL) {
            if (t->index == index) {
                return t;
            }

            t = t->next;
        }

        return NULL;
    }

    int val(node* n) {
        if (n == NULL) {
            cout << "Node is null\n";
            return -1;
        }

        return n->data;
    }

    void swap(node* a, node* b) {
        if (a == NULL || b == NULL) {
            cout << "One of the nodes is null\n";
            return;
        }

        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    void print() {
        node* t = head;

        while (t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }

        cout << "\n";
    }
};

int main() {
    list l;
    int val;

    do {
        cout << "Enter value to add (or enter 0 to stop): ";
        cin >> val;

        if (val == 0)
            break;

        l.add(val);

    } while (val != 0);



    int n = l.tail->index;

    cout << "Before swapping: ";
    l.print();

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {

            if (l.val(l.goto_index(i)) > l.val(l.goto_index(j))) {
                l.swap(l.goto_index(i), l.goto_index(j));
            }
        }
    }

    cout << "After swapping: ";
    l.print();

    return 0;
}