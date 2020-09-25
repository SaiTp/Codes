#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
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

void push(Node** root, int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = *root;
    *root = temp;
}

void print(Node* root){
    while(root!=NULL){
        cout<<root->data<<" ";
        root = root->next;
    }
}
int main(){
	Node* a = NULL;
	Node* b = NULL;
    push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 6);
	push(&b, 2);

	/* Remove duplicates from linked list */
	Node* res = sortedMerge(a, b);

	cout << "Merged Linked List is: \n";
	print(res);

	return 0;
}
