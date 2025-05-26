#include<iostream>
#include<queue>
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

// Height of binary tree
int height(Node *root)
{
    if(root==NULL)
        return 0;
    else 
        return max(height(root->left),height(root->right))+1;
}
// Check is Binary tree is Balanced binary tree
// Naive approch: O(n^2) time
bool isBalanced(Node *root)
{
    int lh,rh;
    if(root==NULL)  return true;
    lh=height(root->left);
    rh=height(root->right);
    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}
// Effective approch
int isBalanced_eff(Node *root)
{
    if(root==NULL)  return 0;
    int lh,rh;
    lh=isBalanced_eff(root->left);
    if(lh==-1)  return -1;
    rh=isBalanced_eff(root->right);
    if(rh==-1)  return -1;
    if(abs(lh-rh)>1) return -1;
    return max(lh,rh)+1;
}
bool check(Node *root)
{
    int x=isBalanced_eff(root);
    return (x!=-1);
}
int main(){
    
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    
    // cout<<"Height of Binary tree: "<<height(root);
    cout<<"is Binary tree is Balanced binary tree(Naive method): "<<isBalanced(root)<<endl;

    cout<<"is Binary tree is Balanced binary tree(Effective method): "<<isBalanced_eff(root)<<endl;
    cout<<"is Binary tree is Balanced binary tree(Effective method): "<<check(root)<<endl;
    
    return 0;
}