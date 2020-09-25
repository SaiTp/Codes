#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};

Node* sortedMerge(Node* a, Node* b);
void frontBackSplit(Node* source, Node** frontRef, Node** backRef);
void mergeSort(Node** headRef){
    Node* head = *headRef;
    Node* a;
    Node* b;
    if((head==NULL)||(head->next==NULL)) return;

    frontBackSplit(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}
Node* sortedMerge(Node *a, Node *b){
    Node* dummy = new Node();
    dummy->data = 0;
    dummy->next = NULL;
    Node* last = dummy;
    while(a!=NULL && b!=NULL){
        if(a->data<b->data){
            last->next = a;
            a = a->next;
            last = last->next;
        }
        else{
            last->next = b;
            b = b->next;
            last = last->next;
        }
    }
    if(a!=NULL){
        last->next = a;
    }
    if(b!=NULL){
        last->next = b;
    }
    return dummy->next;
}
void frontBackSplit(Node* source, Node** frontRef, Node** backRef){
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            slow  = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
void printList(Node* node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
}
void push(Node** headRef, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*headRef);
    *headRef = newNode;
}
int main(){

    Node* a = NULL;

    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    mergeSort(&a);
    cout<<"Sorted linked list is:"<<endl;
    printList(a);

    return 0;
}
