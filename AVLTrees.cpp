#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node*left, *right;
    int height;

    Node(int value){
        data=value;
        left=right=NULL;
        height=1;
    }
};

int height(Node*root){
    if (root==NULL) return 0;

    return root->height;
}

int balanceFactor(Node*root){
    if (root==NULL) return 0;

    return height(root->left) - height(root->right);
}

Node*rightRotation(Node*x){
    Node*y = x->left;
    Node*t = x->right;

    y->right=x;
    x->left=t;

    x->height=max(height(x->left), height(x->right)) + 1;
    y->height=max(height(y->left), height(y->right)) + 1;

    return y;
}

Node*leftRotation(Node*x){
    Node*y=x->right;
    Node*t=y->left;

    y->left=x;
    x->right=t;

    x->height=max(height(x->left), height(x->right)) + 1;
    y->height=max(height(y->left), height(x->right)) + 1;

    return y;
}

Node*insert(Node*root, int value){
    if(root==NULL) return new Node(value);

    if (value<root->data){
        root->left=insert(root->left, value);
    }

    else if (value>root->data){
        root->right=insert(root->right, value);
    }

    else{
        return root;
    }

    root->height=max(height(root->left), height(root->right))+1;

    int BF=balanceFactor(root);

    if(BF>1){ //left heavy
        if (value<root->left->data){// ll rotation
            return rightRotation(root);
        }

        else if (value>root->left->data){ // lr rotation
            root->left=leftRotation(root->left);
            return rightRotation(root);

        }
    }
    if (BF<-1){ //right heavy
        if (root->right->data<value){ //RR rotation 
            return leftRotation(root);
        }
        else if (root->right->data>value){ // rl rotation
            root->right=rightRotation(root->right);
            return leftRotation(root);
        }
    }

    return root;
}

Node*getInOrderSuccessor(Node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node*deletionOfNode(Node*root, int value){
    if (root==NULL) return NULL;

    if (value<root->data){
        root->left=deletionOfNode(root->left, value);
    }
    else if (value>root->data){
        root->right=deletionOfNode(root->right, value);
    }
    else{
        if (root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        else if(root->left==NULL || root->right==NULL){
            delete root;
            return root->left==NULL? root->right:root->left;

        }

        Node*IS=getInOrderSuccessor(root->right);
        root->data=IS->data;
        root->right=deletionOfNode(root->right, IS->data);
    }

    root->height=max(height(root->left), height(root->right))+1;

    int BF=balanceFactor(root);

    if(BF>1){ //left heavy
        if (balanceFactor(root->left) >=0 ){// ll rotation
            return rightRotation(root);
        }

        root->left = leftRotation(root->left);
        return rightRotation(root);
        
    }
    if (BF<-1){ //right heavy
        if (balanceFactor(root->right) <=0 ){ //RR rotation 
            return leftRotation(root);
        }

        root->right=rightRotation(root->right);
        return leftRotation(root);

    }
    return root;
}

void preOrder(Node*root){
    if (root==NULL) return ;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    // Your code goes here
    Node*root=NULL;
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 4);

    preOrder(root);
    cout<<endl;
    
    deletionOfNode(root, 3);
    preOrder(root);
    return 0;
}