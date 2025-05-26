/*  


compile:
    g++ -std=c++0x 10_vertical_traversal_of_binary_tree.cpp -o 10_vertical_traversal_of_binary_tree
run:
    ./10_vertical_traversal_of_binary_tree  

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
void vTraversal(Node *root){
    map<int,vector<int> > mp;
    queue<pair<Node*,int> > q;
    q.push({root,0});
    while(q.empty()==false){
        auto p=q.front();
        Node *curr=p.first;
        int hd=p.second;
        if(mp.find(hd)==mp.end())
            mp[hd].push_back(curr->key);
        q.pop();
        if(curr->left!=NULL)
            q.push({curr->left,hd-1});
        if(curr->right!=NULL)
            q.push({curr->right,hd+1});
    }
    // print value of map
    for(auto x:mp){
        vector<int> v=x.second;
        for(int y:v)
            cout<<y<<" ";
    }
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

    
    vTraversal(root);
    // vSumMain(root);
    // inorder(root);
   
    return 0;
}

