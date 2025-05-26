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

// floor
Node *floor(Node *root, int x)
{
    Node *res=NULL;
    while(root!=NULL)
    {
        if (root->key==x)
        {
            return root;
        }
        else if (root->key>x)
        {
            root=root->left;
        }
        else if (root->key<x)
        {
            res=root;
            root=root->right;
        }
    }
    return res;
}

// traversal
vector<int>v;
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        // v.push_back(root->key);
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

    cout<<"Floor of 17 is: "<<(floor(root,17)->key)<<endl;
    // inorder(root);
    // insertITR(root,10);
    // cout<<"\nprint nodes: ";
    // for(auto item:v)
    // {
    //     cout<<item<<" "; 
    // }
    
    return 0;
}