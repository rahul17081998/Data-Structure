/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level 
are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        // use level order traversel
        // bfs

        if(root==NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool f=0;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if(node->left){
                if(f==1) return false;
                q.push(node->left);
            }
            else f=1; // mark left node is not present

            if(node->right){
                if(f==1) return false; // previously left node was missing, not a complete Btree
                q.push(node->right);
            }
            else f=1;
        }
        return true;
    }
};