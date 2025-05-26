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
bool searchITR(Node *root, int x)
{
    // base case
    if(root==NULL)
        return false;
    while(root!=NULL)
    {
        if(root->key==x)
            return true;
        else if(root->key>x)
            return search(root->left,x);
        else
            return search(root->right,x);
    }
    return false;
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
    cout<<search(root,2)<<endl;
    cout<<searchITR(root,2)<<endl;
    return 0;
}