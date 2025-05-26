
class Solution {
public:
    int count=0;
    void inorder(TreeNode* root, int k, int &ans){
        if(root==NULL) return;
        inorder(root->left, k, ans);
        count++;
        if(count==k) {ans = root->val; return;}
        inorder(root->right, k, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // finding kth smallest element in a bst is like finding kth elelemt in inorder of a tree
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};

