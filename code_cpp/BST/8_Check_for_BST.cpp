
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

bool isBST(Node*root,int min,int max)
{
    if(root==NULL)
        return true;
    return ((root->key>min) && (root->key<max) && isBST(root->left,min,root->key) &&
    isBST(root->right,root->key,max));
      
    
    
}

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

    

    cout<<"tree is bst or not: "<<isBST(root,INT_MIN,INT_MAX)<<endl;
    inorder(root);
    // insertITR(root,10);
    // cout<<"\nprint nodes: ";
    // for(auto item:v)
    // {
    //     cout<<item<<" "; 
    // }
    
    return 0;
}