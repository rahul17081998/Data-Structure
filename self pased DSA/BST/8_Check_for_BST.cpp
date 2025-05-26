
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
// Leet code solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int x=-2342;
    // inorder traversal
    void inorder(TreeNode* root, bool &flag)
    {
        if(root==NULL)
            return;
        // left call 
        inorder(root->left, flag);
        
        // check if current value smaller than last value means it is voilating the inorder traversal rule that it should be sorted in bst
        if(x != -2342 && root->val <= x)
        {
            flag=false;
            return;
        }
        x = root->val; // store current value into prev(x) variable
        // right call
        inorder(root->right, flag);
    }
        
        
        
    bool isValidBST(TreeNode* root) {
        bool flag=true;
        
        inorder(root, flag);
        return flag;
    }
};
/****** End: Letcode Solution ******/


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