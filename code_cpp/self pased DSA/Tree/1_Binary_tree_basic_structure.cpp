#include<iostream>
#include<queue>
#include<math.h>
#include<vector>
using namespace std;
// Constructing Binary Tree
// create node of tree 
struct Node{

    int key;
    Node *left;
    Node *right;
    Node(int k){
        key=k;
        left=NULL;
        right=NULL;
    }
};
//*****************************************


// Inorder traversal
// left,root,right
void inorder(Node *root, int &nodec)
    {
        if(root!=NULL)
        {
            inorder(root->left,nodec);
            cout<<root->key<<" ";
            nodec++;
            inorder(root->right,nodec);
        }
    }
// Preorder traversal
// root,left,right
void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
// Postorder traversal
// left,right,root
void postorder(Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}
// Height of binary tree
int height(Node *root)
{
    if(root==NULL)
        return 0;
    else 
        return max(height(root->left),height(root->right))+1;
}
// Print Nodes at distance k
void printkDist(Node *root,int k)
{
    if(root==NULL)
        return;
    if(k==0)
        cout<<(root->key)<<" ";
    else
    {
        printkDist(root->left,k-1);
        printkDist(root->right,k-1);
    }
    
}
// Level Traversal: Approch 1
void levelTrav(Node *root)
{
    if(root==NULL)
        return;
    int h=height(root);
    int i=0;
    while(i<=h)
    {
        printkDist(root,i);
        i++;
        
    }
}
// Level Traversal: Approch 2
// use queue data structure
void printLevel(Node *root)
{
    if(root==NULL)
        return;
    queue<Node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        Node *curr=q.front();
        q.pop();
        cout<<(curr->key)<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}
// Level order traversal line by line: Method 1
void printLevelorderLine(Node *root)
{
    if(root==NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size()>1)
    {
        Node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            cout<<"\n";
            q.push(NULL);
            continue;
        }
        cout<<(curr->key)<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}
// Level order traversal line by line: Method 2
void printLevelByLevel(Node *root)
{
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr=q.front();
            q.pop();
            cout<<(curr->key)<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        cout<<"\n";
        
    }
}
//Size of Binary Tree
//Size of Binary Tree is the total numbers of nodes present in that Tree.
int getSize(Node *root)
{
    if(root==NULL)
        return 0;
    return 1+getSize(root->left)+getSize(root->right);
}
//Maximum in Binary Tree.
//Largest node(key) in a Tree is the maximum of the Tree.
int maxi=INT_MIN;
int maxNode(Node *root)
{
    if(root==NULL)
        return INT_MIN;

    // if(root!=NULL)
    // {
    //     maxNode(root->left);
    //     maxNode(root->right);
    //     maxi=max(maxi,(root->key));
    // }
    // return maxi;

    // OR  
    else
        return max(root->key,max(maxNode(root->left),maxNode(root->right)));
}
// left view
int maxlevel = 0;
void printLeft(Node* root, int level)
{
    if(root==NULL) return;
    if(maxlevel<level)
    {
        cout<<(root->key)<<" ";
        maxlevel=level;
    }
    printLeft(root->left, level+1);
    printLeft(root->right, level+1);
}
// Print Left View of Binary Tree
// To Print Left View of Binary Tree we need to print the leftmost node at every level of the Binary Tree.
// Method-1: we use Recursive method 
void printLeftView(Node *root)
{
    printLeft(root,1);
}
// Print Left View of Binary Tree
// To Print Left View of Binary Tree we need to print the leftmost node at every level of the Binary Tree.
// Method-1: we use the Iterative method approach by using queue datastructure. 
void printLeftM2(Node *root)
{
   if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr=q.front();
            q.pop();
            if(i==0)
                cout<<(curr->key)<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        // cout<<"\n";
        
    } 
}

// Children Sum Property
bool isCSum(Node *root)
{
    if(root==NULL)
        return true;
    if(root->left==NULL && root->right==NULL)
        return true;
    int sum=0;
    if(root->left!=NULL)
        sum=sum+root->left->key;
    if(root->right!=NULL)
        sum=sum+root->right->key;
    return (root->key==sum) && isCSum(root->left) && isCSum(root->right);
}
// count total nodes in complete binary tree ---> Naive method: O(N)
int countNode(Node *root)
{
    if(root==NULL)
        return 0;
    else 
        return countNode(root->left)+countNode(root->right)+1;
}
// count total nodes in complete binary tree ---> Effective method: O(logN*logN)
int countNodeEff1(Node *root)
{
    int lh=0,rh=0;
    Node *curr=root;
    while(curr!=NULL){
        lh++;
        curr=curr->left;
    }
    curr=root;
    while (curr!=NULL){
        rh++;
        curr=curr->right;
    }
    if(lh==rh){
        return pow(2,lh)-1;
    }
    else{
        return 1+countNodeEff1(root->left)+countNodeEff1(root->right); 
    }
    
}
// serialization
const int EMPTY = -1;
void serialize(Node* root, vector<int> &arr)
{
    if(root==NULL)
    {
        arr.push_back(EMPTY);
        return;
    }
    else
    {
        arr.push_back(root->key);
    }
    serialize(root->left,arr);
    serialize(root->right,arr);
    
}

//*****************************************
int main(){
    
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);

    //
    // Node *root=new Node(15);
    // root->left=new Node(5);
    // root->right=new Node(20);
    // root->left->left=new Node(3);
    // root->right->right=new Node(80);
    // root->right->left=new Node(18);
    // root->right->left->left=new Node(16);

    int count1=0;
    cout<<"\nInrder Traversal: ";
    inorder(root,count1);
    cout<<"\ncount node: "<<count1<<endl;
    /*
    cout<<"\nPreorder Traversal: ";
    preorder(root);
    cout<<"\nPostorder Traversal: ";
    postorder(root);
    cout<<"\nHeight of Binary tree: "<<height(root);
    cout<<"\nNodes at k=2 distance: ";
    printkDist(root,2);
    cout<<"\nLevel Traversal: Approch 1: ";
    levelTrav(root);
    cout<<"\nLevel Traversal: Approch 2: ";
    printLevel(root);
    cout<<"\nLevel order traversal line by line: Method 1: \n ";
    printLevelorderLine(root);
    cout<<"\nLevel order traversal line by line: Method 2: \n ";
    printLevelByLevel(root);
    cout<<"\nSize of Binary Tree: "<<getSize(root);
    cout<<"\nMaximum in Binary Tree: "<<maxNode(root);
    cout<<"\nPrint Left View of Binary Tree: Method1 (Recursive Method): ";
    printLeftView(root);
    cout<<"\nPrint Left View of Binary Tree: Method2 (Iterative Method): ";
    printLeftM2(root);
    cout<<"\nDo the Binary tree follow Children Sum Property--> yes(1) ,No(1): "<<isCSum(root)<<endl;
    */
    // cout<<"\ncount node: "<<countNode(root)<<endl;
    // cout<<"\ncount node: "<<countNodeEff1(root)<<endl;
    vector<int> v;
    serialize(root,v);
    for(auto item:v)
    {
        cout<<item<<" ";
    }
    return 0;
}