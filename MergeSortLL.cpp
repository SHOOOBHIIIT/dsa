// merge sort using linked list

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

class MergeSort{
    public:
    Node*head;
    Node*tail;
    MergeSort(){
        head=NULL;
        tail=NULL;
    }
    
    void push_front(int value){
        Node*newNode=new Node(value);

        if (head==NULL) head=tail=newNode;
        else{
            newNode->next=head;
            head=newNode;
        }
    }

    void push_back(int value){
        Node*newNode=new Node(value);

        if(head==NULL) head=tail=newNode;
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void printLL(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
    }
    
    Node*splitAtMid(Node*head){
        Node*slow=head;
        Node*fast=head;
        Node*prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if (prev!=NULL){
            prev->next=NULL;
        }
        return slow;
    }

    Node*merge(Node*left, Node*right){
        Node*i=left;
        Node*j=right;
        MergeSort ans;
        while(i!=NULL && j!=NULL){
            if (i->data<=j->data){
                ans.push_back(i->data);
                i=i->next;
            }
            else{
                ans.push_back(j->data);
                j=j->next;
            }
        }
        while(i!=NULL){
            ans.push_back(i->data);
            i=i->next;
        }

        while(j!=NULL){
            ans.push_back(j->data);
            j=j->next;
        }
        return ans.head;
    }

    Node*mergeSort(Node*head){
        if (head==NULL || head->next==NULL) return head;
        Node*rightHead=splitAtMid(head);

        Node*left=mergeSort(head);
        Node*right=mergeSort(rightHead);

        return merge(left, right);
    }
};

int main()
{
    MergeSort ms;
    ms.push_front(8);
    ms.push_front(1);
    ms.push_front(7);
    ms.push_front(3);
    ms.push_front(5);
    ms.push_front(3);
    ms.push_front(4);
    ms.printLL();
    ms.head=ms.mergeSort(ms.head);
    cout<<endl;
    ms.printLL();
    return 0;
} 
