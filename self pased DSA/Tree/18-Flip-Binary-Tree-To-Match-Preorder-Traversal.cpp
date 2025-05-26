/*
You are given the root of a binary tree with n nodes, where each node is uniquely assigned a value from 1 to n. You are also given a sequence of n values voyage, which is the desired pre-order traversal of the binary tree.

Any node in the binary tree can be flipped by swapping its left and right subtrees. For example, flipping node 1 will have the following effect:


Flip the smallest number of nodes so that the pre-order traversal of the tree matches voyage.

Return a list of the values of all flipped nodes. You may return the answer in any order. If it is impossible to flip the nodes in the tree to make the pre-order traversal match voyage, return the list [-1].

*/


class Solution {
public:
    int i;
    vector<int> res;
    vector<int> v;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        i=0;
        v = voyage;
        if(dfs(root)==false)
            return {-1};
        return res;
        
    }

    bool dfs(TreeNode* root){
        if(root==NULL) return true;
        if(root->val!=v[i]) return false;
        i++;
        if(root->left!=NULL && root->left->val!=v[i]){
            res.push_back(root->val);
            return dfs(root->right) && dfs(root->left);// interchanging the node position
        }
        else 
            return dfs(root->left) && dfs(root->right);
    }
};