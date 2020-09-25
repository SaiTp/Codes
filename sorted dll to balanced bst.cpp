#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
};

Node* sortedListToBSTUtil(Node** head_ref, int n){

    if(n<=0) return NULL;

    Node* left = sortedListToBSTUtil(head_ref, n/2);

    Node* root = *head_ref;
    root->prev = left;
    *head_ref = (*head_ref)->next;

    root->next = sortedListToBSTUtil(head_ref, n-n/2-1);

    return root;
}

int countNodes(Node* head){
    int count=0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}
Node* sortedListToBST(Node* head){
    int n = countNodes(head);
    return sortedListToBSTUtil(&head, n);
}


void push(Node** head_ref, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = (*head_ref);
    if((*head_ref)!=NULL) (*head_ref)->prev = newNode;
    (*head_ref) = newNode;
}
void print(Node* node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node= node->next;
    }
}
void preOrder(Node* node){
    if(node==NULL) return;
    cout<<node->data<<" ";
    preOrder(node->prev);
    preOrder(node->next);
}
int main(){
    Node* head = NULL;
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout<<"Given Linked List"<<endl;
    print(head);

    Node* root = sortedListToBST(head);
    cout<<endl<<"PreOrder Traversal of constructed BST"<<endl;
    preOrder(root);

    return 0;
}
