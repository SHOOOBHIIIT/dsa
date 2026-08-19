#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class linkedlist{
    public:
    node* head;
    node* tail;
    linkedlist(){
        head=NULL;
        tail=NULL;
    }
    void insert(int val){
        node* n=new node(val);
        if(head==NULL){
            head=n;
            tail=n;
            return;
        }
        tail->next=n;
        tail=n;
    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int max(){
        node* temp=head;
        int max=INT_MIN;
        while(temp!=NULL){
            if(temp->data>max){
                max=temp->data;
            }
            temp=temp->next;
        }
        return max;
    }
};
void radix_sort(linkedlist &l){
    int m=l.max();
    for(int exp=1;m/exp>0;exp*=10){
        linkedlist buckets[10];
        node* temp=l.head;
        while(temp!=NULL){
            int index=(temp->data/exp)%10;
            buckets[index].insert(temp->data);
            temp=temp->next;
        }
        l.head=NULL;
        l.tail=NULL;
        for(int i=0;i<10;i++){
            if(buckets[i].head!=NULL){
                if(l.head==NULL){
                    l.head=buckets[i].head;
                    l.tail=buckets[i].tail;
                }
                else{
                    l.tail->next=buckets[i].head;
                    l.tail=buckets[i].tail;
                }
            }
        }
    }
}
int main(){
    linkedlist l;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        l.insert(val);
    }
    radix_sort(l);
    cout<<"After sorting: ";
    l.display();
    return 0;
}