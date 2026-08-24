#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

Node* create_node() {
    Node* temp = new Node();

    int val;
    cout << "ENTER THE VALUE OF THE NODE: ";
    cin >> val;

    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

void create_BT(Node* root) {
    bool a;

    cout << "IS THERE A LEFT NODE (1/0): ";
    cin >> a;

    if (a) {
        root->left = create_node();
        root->left->parent = root;
        create_BT(root->left);
    }

    cout << "IS THERE A RIGHT NODE (1/0): ";
    cin >> a;

    if (a) {
        root->right = create_node();
        root->right->parent = root;
        create_BT(root->right);
    }
}

inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
post orer(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void insertion(int val,node*root){
    traverse(root){
        while 
    }
    
}

int main() {
    Node* root = create_node();
    create_BT(root);
    return 0;
}