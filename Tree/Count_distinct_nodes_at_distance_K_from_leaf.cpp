//Node Structure
/*struct Node
{
	int data;
	Node *left, *right;
};*/
void pathFind(int k, Node* root, vector<Node*> currpath, unordered_set<Node*> &s)
{
    if(root==NULL)
        return;
    currpath.push_back(root);
    
    // if current node is a leaf then 
    if(root->left==NULL && root->right==NULL){
        // start you work now from hear
        // you find a leaf
        int size=currpath.size();
        if(size < k+1)
            return;
        s.insert(currpath[size-(k+1)]);
    }
    pathFind(k, root->left, currpath, s);
    pathFind(k, root->right, currpath, s);
    
}

//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* root, int k)
{
	//Add your code here.
	// time =O(N)
	// space=O(H)
	unordered_set<Node*> s;
	vector<Node*>currpath;
	pathFind(k, root, currpath, s);
	return s.size();
}
	
