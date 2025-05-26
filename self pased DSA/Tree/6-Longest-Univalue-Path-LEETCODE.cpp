/*Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.

*/
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
    int longestUnivaluePath(TreeNode* root) {
        int maxLen=0;
        dfs(root, maxLen);
        return maxLen;
    }

private:
    int dfs(TreeNode* root, int &maxLen){
        if(root==NULL) return 0;

        int l = dfs(root->left, maxLen);
        int r = dfs(root->right, maxLen);

        if(root->left==NULL || root->left->val!=root->val) l=0;
        if(root->right==NULL || root->right->val!=root->val) r=0;
        maxLen = max(maxLen, l+r); // updating the Longest Univalue Path
        return max(l, r) +1; // returning maximum height having same node-child value
    }

};