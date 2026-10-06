#include <iostream>
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

Node*insert(Node*root, int value){
    if (root==NULL) return new Node(value);

    if (value < root->data){
        root->left=insert(root->left, value);
    }
    else if (value > root->data){
        root->right=insert(root->right, value);
    }
    
    return root;
}

Node*buildBST(int arr[], int n){
    Node*root=NULL;
    for (int i=0; i<n; i++){
        root=insert(root, arr[i]);
    }
    return root;
}

void inOrder(Node*root){
    if (root==NULL) return ;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

void preOrder(Node*root){
    if(root==NULL)return ;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node*root){
    if (root==NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

bool search(Node*root, int value){
    if(root==NULL) return false;

    if (value==root->data) return true;
    if (value<root->data){
        return search(root->left, value);
    }

    else if (value>root->data){
        return search(root->right, value);
    }
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
       root->right= deletionOfNode(root->right, value);
    }
    else{
        if (root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        if(root->left==NULL || root->right==NULL){
            return root->left==NULL? root->right:root->left;
        }

        Node*IS= getInOrderSuccessor(root->right);
        root->data=IS->data;
        root->right=deletionOfNode(root->right, IS->data);
        return root;

    }
}

int main() {
    // Your code goes here
    int arr[5]={3,5,7,2,8};
    Node*root=buildBST(arr, 5);

    inOrder(root);
    cout<<endl;
    
    cout<<"Searching the value: "<<search(root, 9);
    
    deletionOfNode(root, 5);
    cout<<endl;
    inOrder(root);
    
    return 0;
}
#include <iostream>
 
