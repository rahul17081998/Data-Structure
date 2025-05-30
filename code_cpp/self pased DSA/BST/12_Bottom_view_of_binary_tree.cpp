
/*  


compile:
    g++ -std=c++0x 12_Bottom_view_of_binary_tree.cpp -o 12_Bottom_view_of_binary_tree
run:
    ./12_Bottom_view_of_binary_tree  

*/
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

// Top view of binary tree
void botView(Node *root)
{
    map<int,int>mp;
    queue<pair<Node*,int> >q;
    q.push({root,0});
    while(q.empty()==false)
    {
        auto p=q.front();
        q.pop();
        Node *curr=p.first;
        int hd=p.second;
        // overWrite the previous value at the current height distance(hd) value
        mp[hd]=(curr->key);
        if(curr->left!=NULL)
            q.push({curr->left,hd-1});
        if(curr->right!=NULL)
            q.push({curr->right,hd+1});
    }
    // print map
    for(auto x:mp)
        cout<<x.second<<" ";
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
    root->left->right=new Node(16);

    
    botView(root);
    // vSumMain(root);
    // inorder(root);
   
    return 0;
}

