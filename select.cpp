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
class list{
    node* head;
    node* tail;
public:
    list(){
        head = NULL;

    }
    void add(int val){
        node* n = new node(val);
        if(head == NULL){
            head = n;
            return;
        }
        node* t = head;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = n;
    }
};