#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
// Constructing Binary Tree
// create node of tree 
struct Node{

    int key;
    Node *left;
    Node *right;
    Node(int k){
        key=k;
        left=NULL;
        right=NULL;
    }
};
// printing doubly link list
void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->key<<" ";
        curr=curr->right;
    }cout<<endl;
}

// Convert Binary Tree to Doubly Linked List
Node *BTToDLL(Node *root){
    if(root==NULL)return root;
    static Node* prev = NULL;
    Node *head=BTToDLL(root->left);
    if(prev==NULL){head=root;}
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BTToDLL(root->right);
    return head;
}  


int main(){
    // Node *root=NULL;    // empty tree
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(25);
    root->left->right=new Node(23);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    Node *head=BTToDLL(root);
    printlist(head);
    return 0;
}