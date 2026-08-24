#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node* parent;
};

node* create_node(int data){
    node* temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

node* insert(node*& root, int data){
    if(root == NULL){
        root = create_node(data);
        return root;
    }
    else if(data < root->data){
        insert(root->left, data);
        root->left->parent = root;
    }
    else{
        insert(root->right, data);
        root->right->parent = root;
    }
}

node* create_bt(){
    node* root = NULL;
    bool a = 1;

    while(a){
        cout<<"ENTER THE VALUE OF THE NODE: ";
        int val;
        cin>>val;

        insert(root, val);

        cout<<"DO YOU WANT TO ADD ANOTHER NODE (1/0): ";
        cin>>a;
    }

    return root;
}

void delete_node(node*& root, int data){
    if(root == NULL){
        return;
    }

    if(data < root->data){
        delete_node(root->left, data);
    }
    else if(data > root->data){
        delete_node(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL){
                if(root->parent->left == root)
                    root->parent->left = NULL;
                else
                    root->parent->right = NULL;
                    delete root;
            
        }
        else if(root->left == NULL){
                if(root->parent->left == root){
                    root->parent->left = root->right;
                    root->right->parent = root->parent;}
                else{
                    root->parent->right = root->right;
                    root->right->parent = root->parent;
                }
               delete root;
        }
        else if(root->right == NULL){
                   if(root->parent->left == root){
                    root->parent->left = root->left;
                    root->left->parent = root->parent;}
                else{
                    root->parent->right = root->left;
                    root->left->parent = root->parent;
                }
               delete root;
        }
        else{
            node* minr = root->right;
            while(minr->left != NULL)
                minr = minr->left;

            root->data = minr->data;
            delete_node(minr, minr->data);
        }
    }
}

void inorder(node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node* root = create_bt();
    cout<<"showing data: ";
    inorder(root);
    int a;
    cout<<"ENTER YOUR CHOICE: |1 - Delete Node|2 - Insert Node|3 - Show Data|: ";
    cin>>a;
    switch (a)
    {
    case 1:{
        int val;
        cout<<"ENTER THE VALUE OF THE NODE TO BE DELETED: ";
        cin>>val;
        delete_node(root, val);
        cout<<"showing data: ";
        inorder(root);
        break;
    }
    case 2:{
        int val;
        cout<<"ENTER THE VALUE OF THE NODE TO BE INSERTED: ";
        cin>>val;
        insert(root, val);
        cout<<"showing data: ";
        inorder(root);
        break;
    }
    case 3:{
        cout<<"showing data: ";
        inorder(root);
        break;
    }
    default:
        cout<<"INVALID CHOICE";
        break;
    }
    return 0;
}  
