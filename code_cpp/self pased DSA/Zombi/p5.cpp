#include<bits/stdc++.h>
using namespace std;

// Constructing Binary Tree
// create node of tree 
struct Node{

    int key;
    int dp;
    Node *left;
    Node *right;
    Node(int k){
        key=k;
        dp=-1;
        left=NULL;
        right=NULL;
    }
};
///

int countCamera=0;
int dfs(Node* root, vector<int> &cam)
{
    // check if node is null
    if(root==NULL)
        return 0; // monitored
    
    int left=dfs(root->left, cam);
    int right=dfs(root->right, cam);
    
    // check if any child is not monitoed
    if(left==-1 || right==-1){
        cam.push_back(root->key);
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

int minCameraCover(Node* root, vector<int> &cam) {
    
    // Time complexity = O(N)
    // Space Complexity = O(H)    H=height of tree
    
    
    // 1: camera installed at current node
    // 0: current node is monitored
    // -1: camera is not installed at this node
    
    // check if camera at root is not installed it means root is not monitored
    if(dfs(root, cam)==-1)
    {
        cam.push_back(root->key);
        return countCamera+1;
    }
    
    return countCamera;
    
}


///
// This is not a corrent code 
// it gives some wrong answer
int vertexCover(Node* root)
{
    // if root is null 
    if(root==NULL)
        return 0;
    
    // check if root is a leaf node
    if(root->left==NULL && root->right==NULL)
        return 0;

    // check if value is already present in dp 
    if(root->dp!=-1)
        return root->dp;
    
    // computer size of vertex cover when root is included
    int size1 = 1 + vertexCover(root->left) + vertexCover(root->right);

    // computer size of vertex cover when root is not include in vertex cover
    int size2=0;
    if(root->left!=NULL)
        size2 += 1 + vertexCover(root->left->left) + vertexCover(root->left->right);
    if(root->right!=NULL)
        size2 += 1 + vertexCover(root->right->left) + vertexCover(root->right->right);

    // take minimum of above two case
    root->dp=min(size1, size2);
    return root->dp;


}

int main(){
    Node *root=new Node(2);
    root->left=new Node(18);
    root->left->left=new Node(20);
    root->left->right=new Node(12);
    root->left->right->left=new Node(10);
    root->left->right->right=new Node(14);
    root->right=new Node(24);
    root->right->right=new Node(25);

    cout<<"Minimum vertex cover size: "<<vertexCover(root)<<endl;
    vector<int>cam; // camera
    cout<<"Minimum camera required: "<<minCameraCover(root, cam)<<endl;

    cout<<"\nCamera position node's are: ";
    for(int i=0; i<cam.size(); i++)
        cout<<cam[i]<<" ";
    return 0; 
}