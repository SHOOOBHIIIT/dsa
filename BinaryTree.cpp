#include <iostream>
#include <vector>
#include<queue>
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

static int idx=-1;

// building binary tree

Node*buildTree(vector<int>&nodes){
    idx++;
    if (idx>=nodes.size() || nodes[idx]==-1) return NULL;

    Node*newNode=new Node(nodes[idx]);
    newNode->left=buildTree(nodes);
    newNode->right=buildTree(nodes);

    return newNode;
}

// inOrder treversal

void inOrder(Node*root){
    if (root==NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

// preOrder treversal

void preOrder(Node*root){
    if (root==NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

// postOrder treversal

void postOrder(Node*root){
    if (root==NULL) return ;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}

// levelOrder Treversal

void levelOrder(Node*root){
    if (root==NULL) return ;
     
    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty()){
        Node*curr=Q.front();
        Q.pop();
         
        cout<<curr->data<<" ";
        
        if (curr->left!=NULL){
            Q.push(curr->left);
        }
        if (curr->right!=NULL){
            Q.push(curr->right);
        }
    }
}

// height of the tree

int heightOfTree(Node*root){
    if (root==NULL) return 0;

    int leftHt=heightOfTree(root->left);
    int rightHT=heightOfTree(root->right);

    return 1+max(leftHt, rightHT);
}

// finding no. of nodes

int countNodes(Node*root){
    if (root==NULL) return 0;

    int leftC=countNodes(root->left);
    int rightC=countNodes(root->right);

    return leftC+rightC+1;
}

// finding sum of Nodes

int sumOfNodes(Node*root){
    if (root==NULL) return 0;

    int leftSum=sumOfNodes(root->left);
    int rightSum=sumOfNodes(root->right);

    return leftSum + rightSum + root->data;
}

// finding diameter of tree
 
int diamOfTree(Node*root){
    if (root==NULL)return 0;

    int currHT=heightOfTree(root->left)+heightOfTree(root->right)+1;
    int leftDiam=diamOfTree(root->left);
    int rightDiam=diamOfTree(root->right);
    return max(currHT, max(leftDiam, rightDiam));
}

int main() {
    // Your code goes here
    vector<int> nodes={3,2,6,4,7,9,8,1,5};
    Node*root=buildTree(nodes);
    inOrder(root);
    cout<<endl;

    preOrder(root);
    cout<<endl;

    postOrder(root);
    cout<<endl;

    levelOrder(root);
    cout<<endl;

    cout<<"Height of Tree: "<<heightOfTree(root)<<endl;

    cout<<"No. of Nodes: "<<countNodes(root)<<endl;

    cout<<"Sum of Nodes: "<<sumOfNodes(root)<<endl;

    cout<<"Diameter of tree: "<<diamOfTree(root)<<endl;
    return 0;
} 
