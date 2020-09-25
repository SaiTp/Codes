#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left  = NULL;
        this->right = NULL;
    }
};
void morisTraversal(Node* root){
    if(root==NULL) return;
    Node* current = root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<" ";
            current= current->right;
        }
        else{
            //find inorder predecessor of current
            Node* pre = current->left;
            while(pre->right!=NULL && pre->right!=current){
                pre = pre->right;
            }
            //make current as the right child of its inorder predecessor
            if(pre->right==NULL){
                pre->right = current;
                current = current->left;
            }
            //restore the changes you made in the tree to get
            //the original tree
            else{
                pre->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->right = new Node(6);
    morisTraversal(root);
    return 0;
}
