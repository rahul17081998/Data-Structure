/**
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes 
p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant 
of itself).”
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Do preOrder traversel, you will get path from root to target node
    void preOrder(TreeNode* root, TreeNode *target, vector<TreeNode*> path, vector<TreeNode*> &ans){
        if(root==NULL) return;
        path.push_back(root);
        if(root==target){
            ans = path;
            return;
        }
        preOrder(root->left, target, path, ans);
        preOrder(root->right, target, path, ans);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2, path;
        preOrder(root, p, path, path1);
        preOrder(root, q, path, path2);
        // now take a set and insert all node of path into set
        unordered_set<TreeNode*> st;
        for(auto node: path1){
            st.insert(node);
        }
        // now start from last node of path2 and check if it is present into the set or not.
        // whoever you find first present into set that will be our LCA of our problem.
        // reverse the path2
        reverse(path2.begin(), path2.end());
        for(auto node: path2){
            if(st.find(node)!=st.end()){
                return node;
            }
        }
        return NULL; // this will not execute
    }
};