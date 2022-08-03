
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

void vSum(Node *root, int hd,map<int,int> &m)
{
    if(root==NULL) return;
    vSum(root->left,hd-1,m);
    m[hd] +=root->key;
    vSum(root->right,hd+1,m);
}
void vSumMain(Node *root)
{
    map<int,int>m;
    vSum(root,0,m);
    cout<<" vertical sum\n";
    for(auto x:m)
        cout<<x.second<<" ";
    cout<<endl;
}

// print elements
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

    

    vSumMain(root);
    // inorder(root);
   
    return 0;
}