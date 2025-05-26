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
// Level order traversal line by line: Method 2
int MaxWidth(Node *root)
{
    if(root==NULL)
        return 0;
    queue<Node*> q;
    q.push(root);
    
    int res;
    while(q.empty()==false)
    {
        int temp=0;
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr=q.front();
            q.pop();
            // cout<<(curr->key)<<" ";
            temp++;
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
            res=max(res,temp);
        }
        // cout<<"\n";
        
    }
    return res;
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
    cout<<MaxWidth(root)<<endl;
    return 0;
}