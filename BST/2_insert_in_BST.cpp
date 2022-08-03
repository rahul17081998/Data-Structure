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
// Insert in BST: recursive approch
Node *insert(Node *root, int x)
{
    Node *temp=new Node(x);
    Node *curr=root;
    if(curr==NULL)
        return temp;
    else if(curr->key==x)
        return curr;
    else if(curr->key>x)
        curr->left=insert(curr->left,x);
    else 
        curr->right=insert(root->right,x);
    return root;
}
// insert in BST: Iterative approch
/*
Node *insertITR(Node *root, int x)
{
    Node *temp=new Node(x);
    Node *curr=root;
    while(curr->key!=x)
    {
        // if(curr==NULL)
        //     curr=temp;
        if(curr==NULL)
            curr=temp;
        else if(curr->key>x)
            curr=curr->left;
        else if(curr->key<x)
            curr=curr->right;
        // else
        // else if(curr->key==x)
        //     return curr;
    }
}

*/
vector<int>v;
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        v.push_back(root->key);
        inorder(root->right);    
    }
} 
int main(){
    // Node *root=NULL;    // empty tree
    Node *root=new Node(15);
    root->left=new Node(5);
    root->right=new Node(20);
    root->left->left=new Node(3);
    root->right->right=new Node(80);
    root->right->left=new Node(18);
    root->right->left->left=new Node(16);

    root=insert(root,10);
    inorder(root);
    // insertITR(root,10);
    cout<<"\nprint nodes: ";
    for(auto item:v)
    {
        cout<<item<<" "; 
    }
    
    return 0;
}