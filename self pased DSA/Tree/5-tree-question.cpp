/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

/******** Inorder Traversal ********/

void inorder(vector<int> &v, Node *root)
{
    if(root!=NULL){
        inorder(v, root->left);
        v.push_back(root->data);
        inorder(v, root->right);
    }
    
}
  
/******** Preorder Traversal ********/

void preOrder(vector<int> &ans, Node*root){
     if(root==NULL) return;
     // insert data first
     ans.push_back(root->data);
     // call left and right child
     preOrder(ans, root->left);
     preOrder(ans, root->right);
}

/******** Preorder Traversal ********/

void postoredr(vector<int> &ans, Node *root){
    if(root==NULL) return;
    
    postoredr(ans, root->left);
    postoredr(ans, root->right);
    ans.push_back(root->data);

}

/******** Height of Binary Tree ********/
int height(struct Node* node)
{
        // code here 
        if(node==NULL)
            return 0;
        return max(height(node->left),height(node->right))+1;
}

/******** Node at K distance from root ********/
vector<int> ans;
void printAtk(Node *root, int k)
{
    if(root==NULL) return;
    if(k==0){
        ans.push_back(root->data);
        return;
    }
    printAtk(root->left, k-1);
    printAtk(root->right, k-1);
}

/******** Left View of Binary Tree ********/
// initially keep level at 0
void printLeftView(Node *root, int level, vector<int> &ans)
{
    if(root==NULL) return;
    if(ans.size()== level){
        ans.push_back(root->data);
    }
    
    printLeftView(root->left, level+1, ans);
    printLeftView(root->right, level+1, ans);
}

/******** Diameter of a Binary Tree ********/
int height(Node* root, int &diameter)
    {
        if(root==NULL)  return 0;
        int lh,rh;
        lh=height(root->left,diameter);
        rh=height(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
// Function to return the diameter of a Binary Tree.
int diameter(Node* root) {
    // Your code here
    int diameter=0;
    height(root,diameter);
    return diameter+1;
}
/******** Lowest Common Ancestor of a Binary Tree ********/
TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==NULL || root==p || root==q) return root;
    TreeNode* left = LCA(root->left, p, q);
    TreeNode* right = LCA(root->right, p, q);
    
    if(left==NULL) return right;
    else if(right==NULL) return left;
    else return root; // you found the LCA here
}
    
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return LCA(root, p, q);
}

/******** Burning Tree ********/

class Solution {
  public:
    // parent child mapping
    // target node find
    
    Node* level(Node* root, unordered_map<Node*, Node*> &nodeToParent, int target) 
    {p
        Node *targetNode=NULL;
        
        queue<Node*> q;
        q.push(root);
        nodeToParent[root]=NULL;
        
        while(!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            
            // check for target node
            if(curr->data==target)
            {
                targetNode = curr;
            }
            
            // check if node have left child
            if(curr->left!=NULL)
            {
                nodeToParent[curr->left]=curr;
                q.push(curr->left);
            }
            // check if node have right child
            if(curr->right!=NULL)
            {
                nodeToParent[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }
    
    
    // step 3: Burning tree
    int burnTree(Node* root, unordered_map<Node*, Node*> nodeToParent)
    {
        unordered_map<Node*, bool> vis;
        queue<Node*> q;
        q.push(root);
        vis[root]=1;
        
        int ans=0;
        
        while(!q.empty())
        {
            int size = q.size();
            bool flag=false; // if any node added into queue it turns into true
           
            for(int i=0; i<size; i++){
                // process the neighbouring node
                Node *front = q.front();
                q.pop();
                
                // left
                if(front->left!=NULL && !vis[front->left]){
                    flag=true;
                    q.push(front->left);
                    vis[front->left]=1;
                }
                // right
                if(front->right!=NULL && !vis[front->right]){
                    flag=true;
                    q.push(front->right);
                    vis[front->right]=1;
                }
                // parent
                
                if(nodeToParent[front]!=NULL && !vis[nodeToParent[front]]){
                    flag=true;
                    q.push(nodeToParent[front]);
                    vis[nodeToParent[front]]=1;
                }
                
            }
            if(flag==true){
                ans++;
            }
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*, Node*> nodeToParent; // cild-parent mapping
        Node* tNode=level(root, nodeToParent, target);
        
        // step 3: burning tree
        int ans= burnTree(tNode, nodeToParent);
        return ans;
        
    }
};

