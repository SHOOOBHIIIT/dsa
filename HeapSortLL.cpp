#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left, *right;

    Node(int value){
        data=value;
        left=right=NULL;
    }
};

Node* insert(Node*root, int value){
    if (root==NULL) return new Node(value);

    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty()){
        Node*curr=Q.front();
        Q.pop();

        if (curr->left==NULL){
            curr->left = new Node(value);
            return root;
        }
        Q.push(curr->left);

        if (curr->right==NULL){
            curr->right = new Node(value);
            return root;
        }
        Q.push(curr->right);
    }
}

void maxHeapify(Node*root){
    if (root==NULL) return ;

    maxHeapify(root->left);
    maxHeapify(root->right);

    Node*largest=root;

    if (root->left != NULL && root->left->data > largest->data){
        largest = root->left;
    }

    if (root->right != NULL && root->right->data > largest->data){
        largest = root->right;
    }

    if (largest != root){
        swap(root->data, largest->data);
        maxHeapify(largest);
    }
}

void preOrder(Node*root){
    if (root==NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

void inOrder(Node*root){
    if (root==NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main() {
    // Your code goes here
    Node*root=NULL;
    root=insert(root, 5);
    root=insert(root, 9);
    root=insert(root, 8);
    root=insert(root, 7);
    root=insert(root, 6);
    root=insert(root, 2);
    root=insert(root, 1);

    maxHeapify(root);

    preOrder(root);
    cout<<endl;

    inOrder(root);

    return 0;
} 
