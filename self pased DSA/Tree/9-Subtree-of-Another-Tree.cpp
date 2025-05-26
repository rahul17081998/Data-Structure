
class Solution {
public:
    bool flag=false;
    // check two trees are same(structually and value wise)
    bool isSameTree(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;

        return root1->val==root2->val && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
        
    }

    void preOrderTrev(TreeNode* root, TreeNode* subroot){
        if(root==NULL) return;
        // check if current root node subtree is same as of subroot tree
        if(isSameTree(root, subroot)){
            flag=true;
            return;
        }
        // call left and right recursive call
        preOrderTrev(root->left, subroot);
        preOrderTrev(root->right, subroot);

    }
    // main function
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        preOrderTrev(root, subRoot);
        return flag;
    }
};