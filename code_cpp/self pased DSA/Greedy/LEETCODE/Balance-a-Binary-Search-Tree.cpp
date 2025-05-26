/*Given the root of a binary search tree, return a balanced binary search tree with the same node values. 
If there is more than one answer, return any of them.
A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.*/

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &v){
        if(root==NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    TreeNode* help2(vector<int> &v, int s, int e){
        if(s>e) return NULL;
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = help2(v, s, mid-1);
        root->right = help2(v, mid+1, e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return help2(v, 0, v.size()-1);
    }
};