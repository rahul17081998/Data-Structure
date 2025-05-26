
/*
Leetcode premium question:
Given a binary tree root, a node X in the tree is named good if in the path from 
root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.
*/
#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

// structure of the tree
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


class Solution{
public:
    int ans; // variable to store the count of "good" nodes
    void preOrder(Node* root, int maxValue){
        if(root==NULL) return;
        // check if current node value is greater or equal to maximum value we get so far, then this node value is also a good node
        if(root->key >= maxValue) ans++;

        maxValue = max(maxValue, root->key); // update the maxvalue
        preOrder(root->left, maxValue);
        preOrder(root->right, maxValue);
    }
    // TC = O(N)
    int goodNode(Node *root)
    {
        if(root==NULL) return 0;
        int maxValue = root->key; // initialize maxValue to the key value of the root node
        ans = 0; // initialize ans to 0
        preOrder(root, maxValue); // call the helper function to traverse the tree
        return ans; // return the final count of "good" nodes
    }
};

int main(){
   
    // create the nodes of the tree
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right= new Node(4);
    root->left->left = new Node(3);
    // root->left->right = new Node(2);
    root->right->left= new Node(1);
    root->right->right= new Node(5);
    Solution obj;

    cout<<obj.goodNode(root)<<endl;
    return 0;
}
/*
            3
          /   \
         1      4 
        /       / \
       3       1    5
*/

