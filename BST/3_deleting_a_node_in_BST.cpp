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
// successor of a node
// used to find when we delete a node which have both side subtree
Node *getSuccessor(Node *curr)
{
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}
Node *delNode(Node *root, int x)
{
    if(root==NULL) return root;
    if (root->key>x)
    {
        root->left=delNode(root->left,x);
    }
    else if (root->key<x)
    {
        root->right=delNode(root->left,x);
    }
    else    // Node found, which we will be deleting.
    {
        // to delete bottom node or node having left part null 
        // but have right part some subtree
        if(root->left==NULL)
        {
            Node *temp=root->right;
            delete(root);
            return temp;
        }
        // to delete bottom node or node having right part null 
        // but have left part some subtree
        else if (root->right==NULL)
        {
            Node *temp=root->left;
            delete(root);
            return temp;
        }
        else    // if deleting node which have left and right both part available
        {
            Node *succ=getSuccessor(root);
            root->key=succ->key;// replace deleting node with successor node
            root->right=delNode(root->right,succ->key); // delete successor node now which a leaf node
        }
        
        
    }
    return root;
    
    
    
}
// Search in Binary search tree: recursive approch---> time=O(log N)
bool search(Node *root, int x)
{
    // base case
    if(root==NULL)
        return false;
    else if(root->key==x)
        return true;
    else if(root->key>x)
        return search(root->left,x);
    else
        return search(root->right,x);
}
// traversal
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
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
    // cout<<search(root,2)<<endl;
    int x=15;
	
	root=delNode(root,x);
	inorder(root);
   
    return 0;
}