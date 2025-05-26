/*
You are given the root of a binary tree and a positive integer k.
The level sum in the tree is the sum of the values of the nodes that are on the same level.
Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer 
than k levels in the tree, return -1.
Note that two nodes are on the same level if they have the same distance from the root.
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // we  have to do level order traversel
        vector<long long> levelSum;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            // find the sum of all the elements in a perticuler level
            long long sum=0;
            while(size-->0){
                auto node = q.front();
                q.pop();

                sum += node->val;
                // check if its has left child then push that into queue
                if(node->left!=NULL) q.push(node->left);
                // check if its has right child then push that into queue
                if(node->right!=NULL) q.push(node->right);
            }
            levelSum.push_back(sum);
        }

        if(levelSum.size()<k) return -1;
        sort(levelSum.begin(), levelSum.end(), greater<long long>());
        return levelSum[k-1];

    }
};