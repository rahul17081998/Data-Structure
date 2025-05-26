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
 
 
 I solve this question using two method
 
 */



class Solution {
public:
    /*
    // Method 1: time O(N^2), space=O(1)
    void checkTarget(TreeNode* root, int targetSum, long currentSum, int &count)
    {
        if(root==NULL)
            return;
        currentSum += root->val;
        if(currentSum==targetSum)
            count++;
        
        checkTarget(root->left, targetSum, currentSum, count);
        checkTarget(root->right, targetSum, currentSum, count);
    }
    
    
    void perorder(TreeNode* root, int targetSum, int &count)
    {
        if(root==NULL)
            return;
        // check if current sum is equal to targetSum
        long currentSum=0;
        checkTarget(root, targetSum, currentSum, count);
        
        perorder(root->left, targetSum , count);
        perorder(root->right, targetSum , count);
    }
    */
    
    void countPathSum(TreeNode* root, unordered_map<long, int> mp, int targetSum, long currentSum, int &count)
    {
        if(root==NULL)
            return;
        currentSum += root->val;
        if(currentSum == targetSum)
            count++;
        // check if map have already currentSum-target
        if(mp.find(currentSum-targetSum)!=mp.end())
            count += mp[currentSum-targetSum];
        
        mp[currentSum]++; // need not to backtrack it will automatically backtrack through recur
        countPathSum(root->left, mp, targetSum, currentSum, count);
        countPathSum(root->right, mp, targetSum, currentSum, count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        
        /*
         // Method 2: 
         // Tc =O(N^2), space=O(N)
        int count=0;
        perorder(root, targetSum , count);
        return count;
        */
        
        
        // Method 2: Efficient solution
        // Tc =O(N), space=O(N)
        int count=0;
        unordered_map<long, int> mp;
        long currentSum=0;
        countPathSum(root, mp, targetSum, currentSum, count);
        return count;
    }
};
