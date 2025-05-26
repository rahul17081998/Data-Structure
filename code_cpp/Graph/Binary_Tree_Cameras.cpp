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
    int countCamera=0;
    int dfs(TreeNode* root)
    {
        // check if node is null
        if(root==NULL)
            return 0; // monitored
        
        int left=dfs(root->left);
        int right=dfs(root->right);
        
        // check if any child is not monitoed
        if(left==-1 || right==-1){
            countCamera++;
            return 1; // camera insatalled at current node
        }
        // check if any child have camera
        if(left==1 || right==1)
            return 0; // current node is monitored by child
        
        // check if both child is monitord then then we will not installing camera
        // then camera will install to the parent of current node [just above node]
        // if(left==0 && right==0)  
        return -1;
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        // Time complexity = O(N)
        // Space Complexity = O(H)    H=height of tree
        
        
        // 1: camera installed at current node
        // 0: current node is monitored
        // -1: camera is not installed at this node
        
        // check if camera at root is not installed it means root is not monitored
        if(dfs(root)==-1)
            return countCamera+1;
        
        return countCamera;
        
    }
};
