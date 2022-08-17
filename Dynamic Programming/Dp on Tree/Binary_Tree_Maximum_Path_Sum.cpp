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
    
private:
    int maxSum=INT_MIN;
    unordered_map<TreeNode*, int> mp; // it will work as a dp array
    
    int dfs(TreeNode* node)
    {
        // base case 
        if(node==NULL)
            return 0;
        
        int leftMaxSum=0;
        int rightMaxSum=0;
        
        // Calculate left side maximum sum
        // check if alredy left path of is calculated then, take value from map
        if(mp.find(node->left)!=mp.end())
            leftMaxSum = mp[node->left];
        else // if this is first time, calculate it
            leftMaxSum = max(dfs(node->left), 0); // if you get -ve sum from dfs then consider 0 
        
        // Calculate right side maximum sum
        if(mp.find(node->right)!=mp.end())
            rightMaxSum = mp[node->right];
        else
            rightMaxSum = max(dfs(node->right), 0);
        
        // cumpute maximum sum for current node and compare with maxSum
        maxSum = max(maxSum, leftMaxSum + rightMaxSum + node->val);
        
        // store maximum sum corrosponding to current node
        mp.insert({node, maxSum});
        return node->val + max(leftMaxSum, rightMaxSum);
            
    }
public:
    int maxPathSum(TreeNode* root) {
        // time = O(N), space=O(N)
        int x =dfs(root);
        return maxSum;
    }
};
