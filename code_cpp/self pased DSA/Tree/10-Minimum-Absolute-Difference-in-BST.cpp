// Solution to find the minimum difference between any two nodes in a binary search tree (BST)
// Uses in-order traversal to visit all nodes in the tree in sorted order and calculates the minimum difference
class Solution {
public:
    int lastNodeValue=-1; // variable to store the value of the previous node visited during traversal
  
    void inorder(TreeNode* root, int &ans){
        if(root==NULL) return; //base case for recursion: if the current node is null, return
        inorder(root->left, ans); //recursively traverse left subtree
        if(lastNodeValue!=-1){
            ans = min(ans, abs(lastNodeValue-root->val)); //update minimum difference
        }
        lastNodeValue = root->val; //update lastNodeValue
        inorder(root->right, ans); //recursively traverse right subtree
    }
    //main function to be called, returns the minimum difference
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX; //initialize minimum difference as the maximum possible value
        inorder(root, ans);
        return ans;
    }
};
