// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    // child parent mapping
    void levelorder(Node *root, unordered_map<Node*,Node*> &parent_track)
    {
        
        queue<Node*> q;
        q.push(root);
        
        while(q.empty() == false)
        {
            Node* curr = q.front();
            q.pop();
            
            if(curr->left!=NULL){
                parent_track[curr->left] =curr;
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }       
        }
    }
    
    // find target node address
    Node *findTarget(Node *root, int target)
    {
        if(root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        
        while(q.empty() == false)
        {
            Node* curr = q.front();
            q.pop();
            // target pointer finding
            if(curr->data == target){
                cout<<curr->data<<endl;
                return curr;
            }
            
            if(curr->left!=NULL)
                q.push(curr->left);
            
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
    
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        unordered_map<Node*, Node*> parent_track;
        
        levelorder(root, parent_track);
        // findig target
        Node *Target = findTarget(root, target);
        
        unordered_map<Node*, bool> visited;
        queue<Node*> queue;
        
        queue.push(Target);
        visited[Target] = true;
        
        int curr_level = 0;
        
        while(!queue.empty())
        {
            int size = queue.size();
            if(curr_level == k) break;
            curr_level++;
            
            for(int i=0; i<size; i++)
            {
                Node* current = queue.front();
                queue.pop();
                
                // if a left exit and if the are not visited
                if(current->left && !visited[current->left])
                {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                // if a right exist and if the are not visited
                if(current->right && !visited[current->right])
                {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                // if a parent exist and if the are not visited
                if(parent_track[current] && !visited[parent_track[current]])
                {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                } 
            }
            
        }
        
        
        vector<int> ans;
        while(queue.empty() == false)
        {
            Node* current = queue.front();
            queue.pop();
            
            ans.push_back(current->data);
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends