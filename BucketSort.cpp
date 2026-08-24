// bucket sort

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;

    LinkedList(){
        head = tail = NULL;
    }
    void push(int value){
        Node* newNode = new Node(value);
        if (head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void sort(){
        for (Node* i = head; i != NULL; i = i->next){
            for (Node* j = i->next; j != NULL; j = j->next){
                if (i->data > j->data){
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
};

void bucketSort(int arr[], int n){
    LinkedList bucket[10];
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max)
            max = arr[i];
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++){
        int index = (arr[i] * 10) / (max + 1);
        bucket[index].push(arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < 10; i++){
        bucket[i].sort();
    }

    // Combine buckets
    int index = 0;

    for (int i = 0; i < 10; i++){
        Node* temp = bucket[i].head;

        while (temp != NULL){
            arr[index++] = temp->data;
            temp = temp->next;
        }
    }
}

int main(){
    int arr[] = {42, 23, 4, 16, 8, 15, 9};
    int n = 7;
    bucketSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}