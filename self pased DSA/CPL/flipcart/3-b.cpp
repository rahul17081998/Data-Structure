#include<bits/stdc++.h>
using namespace std;

// Code 
// this code fails for below test case

int dp[201][201][1001][2][2];

string change(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] == 'a' || s[i] == 'o') s[i] = '$';
        else if(s[i] == 't' || s[i] == 'i') s[i] = '#';
    }
    return s;
}

int f(int i,int j,int k,string &str,string &draw,bool start,bool erase){
    if(i == str.size())
        return true;
    if(!erase && j == draw.size())
        return f(i+1,j,k,str,draw,start,true);
    if(j == draw.size())
        return false;
    
    if(dp[i][j][k][start][erase] != -1) return dp[i][j][k][start][erase];
        
    bool ret = false;
  
    if(!start)
        ret |= f(i,j+1,k,str,draw,start,erase);
    if(str[i] == draw[j])
        ret |= f(i+1,j+1,k,str,draw,true,erase);
    if(!erase)
        ret |= f(i+1,j,k,str,draw,start,true);
    if(start && k>0)
        ret |= f(i,j+1,k-1,str,draw,start,erase);
    
    return dp[i][j][k][start][erase] = ret;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    string draw;
    cin>>draw;
    draw = change(draw);
    
    int count = 0;
    
    for(int i=0;i<n;i++){
        string s = change(arr[i]);
        memset(dp,-1,sizeof(dp));
        if(f(0,0,k,s,draw,false,false)) count++;
    }
    cout<<endl;
    cout<<count;
    return 0;
}



/*
3
ac zb yhja
xyzabc
1

correct O/P: 2
but this code gives 3
*/


///////

// N-cehf

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int solve(vector<int> &v) {
    int n = v.size();
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        um[v[i]]++;
    }
    int pos_sum = 0, neg_sum = 0;
    for (auto &x : um) {
        if (x.second == 1) {
            if (x.first > 0) pos_sum += x.first;
            else neg_sum += x.first;
        }
    }
    int diff = abs(pos_sum - neg_sum);
    return diff;
}

int solve2(vector<int> scores){
    int n = scores.size();
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[scores[i]]++;
    }

    int posSum=0, negSum=0;
    for(auto it: mp){
        if(it.second==1){
            if(it.first>0)
                posSum += it.first;
            else
                negSum += it.first;
        }
    }
    return abs(posSum-negSum);
}

int main(){
  
    vector<int> scores;
    // scores.push_back(5);
    // scores.push_back(8);
    // scores.push_back(-1);
    // scores.push_back(7);
    scores.push_back(-10);
    scores.push_back(-20);
    scores.push_back(-30);
    // cout<<solve(scores)<<endl;
    cout<<solve2(scores)<<endl;
    return 0;
}
/*
Ex1:
4
5 8 -1 7
o/p: 21

Ex2:
3
-10 -20 -30
o/p: 60
*/

//
// n-employes
#include<bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

void dfs(int i, int par, vector<bool>&visited, vector<vector<int> > &adj)
{
    if(visited[i] == true)
    {
        visited[par] = true;
        return;
    }
    for(int j : adj[i])
    {
        dfs(j,i,visited,adj);
    }
}


void solve(){
    int n, p, projects, temp;
    cin >> n >> p;
    vector<vector<int> > adj(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> temp;
        adj[i].push_back(temp);
    }

    vector<bool>visited(n+1,false);
    visited[0] = true;
    
    for(int i=0; i<p; i++)
    {
        cin >> projects;
        dfs(projects,projects,visited,adj);
    }

    for(int i=1; i<=n; i++)
    {
        if(visited[i] == false)
            cout << i << " ";
    }
}


/********/
// rev
void dfs1(int i, int par, vector<bool > &vis, vector<vector<int> > &adj){
    if(vis[i]){
        vis[par]=true;
        return;
    }
    for(auto child: adj[i]){
        dfs1(child, i, vis, adj);
    }
}

void solve2(vector<int> a, vector<int> projects, int n)
{
    // adjacency matrix
    vector<vector<int> > adj(n+1);
    for(int i=1; i<=n; i++){ 
        adj[i].push_back(a[i-1]);
    }
    vector<bool> vis(n+1, false);
    vis[0]=true;

    for(int i=0; i<projects.size(); i++){
        dfs1(projects[i], projects[i], vis, adj);
    }
    for(int i=1; i<=n; i++){
        if(!vis[i])
            cout<<i<<" ";
    }
}
int main()
{    
    // std::ios::sync_with_stdio(false);
    // int T=1; 
    // // cin >> T;
    // while(T--){
    //     solve();
    // }

    int N=8;
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(3);
    a.push_back(4);
    a.push_back(4);
    vector<int> projects;
    projects.push_back(8);
    projects.push_back(4);
    projects.push_back(6);
    projects.push_back(5);

    solve2(a, projects, N);
    return 0;
}



/*
8 4
0 1 1 2 3 3 4 4
8 4 6 5

*/

// secret code
#include <iostream>
using namespace std;

int power(int base, int exponent)
{
  int mul=1;
  for(int i=0; i<exponent; i++) mul *= base;
  return mul;
}
int main() 
{
    int s,n,m; cin>>s>>n>>m;
  	int res = power( power(s,n)%10, m) % 1000000007;
  	cout<<res;
    return 0;
}


// second
#include<stdio.h>
#include<math.h>
int main()
{
long int s,n,m,ans;
scanf(“%ld %ld %ld”,&s,&n,&m);
ans=pow(s,n);
ans=ans%10;
ans=pow(ans,m);
ans=ans%1000000007;
printf(“%ld”,ans);
return 0;
}

Testcase 1:
Input:
2, 3, 4

Expected Return Value:
4096

More questions and answers in Wipro elite Winning Test Series.

// devide the groop
/*
Question:
The Teacher wants to divide the group of students for singing competition . Each group will have 
one mic . If the number of mic is greater than the number of groups then teacher can select group 
and divide it such that the largest group among all groups is as small as possible .
Test case 1 :
n = 5 , k =7 ; k is number of groups mics and n is number of groups initially
[10 , 8 , 6 , 3 ,2 ] – > initially number of students in each group .
Output = 6 ;
we can divide the group of 10 into 5 ,5 —> [5,5, 8 ,6 ,3, 2]
again we divide the group of 8 into 4, 4 – > [5 ,5 , 4 ,4 ,6,3 ,2]
The numbers of groups equals to the number of mics Hence the largest group is of size 6 .

Test case 2 :
n = 5 ,k =9
[100 , 80 , 60 ,40 , 30] – > initially number of students in each group .
Output = 40
First divide the group of 100 into 80 , 20 – > [80 ,20 ,80 , 60 , 40 ,30]
Now divide the group of 80 into 40 ,40 --> [40 , 40 , 20 , 80 , 60 ,40 ,30]
again divide the group of 80 into 40, 40 – > [40 , 40 ,20 ,40 ,40 ,60 ,40 ,30]
divide the group of 60 into 30 ,30 --> [40, 40 , 20 , 40 ,40 , 30 ,30 ,40 ,30]
The numbers of groups equals to the number of mics Hence the largest group is of size 40 .



Approach:
This problem can be solved by normal binary search, you can divide the groups (k-n) times.
Now do a binary search on your answer values, first i would try the value 1 , i would count the 
number of divisions required over the array, if it is >(n-k), it is not a possible ans, now search 
on mid value that is 50 as max is 100 in your case,it is possible, next try 25 , not possible, 
next 37 not possible, next 43 possible, next 40 ,possible, next 41 not possible, so 40 will be 
your ans.

Time complexity , O(n logn).
*/
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &groups, int mics, int n)
{
    // hi can be write as the maximum of groups element
    int lo = 1, hi = 1e10;
    while(lo < hi){
        int mid = (lo + hi)/2; // find a mid val
        int r = 0;
        for(int i=0; i<n; i++){
            r += ceil((double)groups[i]/mid);
        }
        if(r<= mics)
            hi = mid;
        else
            lo = mid+1;
    }
    return hi;
}


int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> groups(n);
    for(int i=0; i<n; i++){
        cin >> groups[i];
    }

    /*
    int n =5;
    vector<int> groups;
    groups.push_back(100);
    groups.push_back(80);
    groups.push_back(60);
    groups.push_back(40);
    groups.push_back(30);
    int k = 9;
    */
    cout<<solve(groups, k, n)<<endl;
    return 0;
}
/*

Test case 2 :
n = 5
k = 9
[100 80 60 40 30]


Test case 1 :
n = 5 , k =7 ; k is number of groups mics and n is number of groups initially
[10 , 8 , 6 , 3 ,2 ] – > initially number of students in each group .
Output = 6 ;


5 7
10 8 6 3 2





5 9
100 80 60 40 30


*/

// 6-Count-pairs-of-leaf-nodes-in-a-Binary-Tree-which-are-at-most-K-distance-apart.cpp

#include <bits/stdc++.h>
using namespace std;

// Structure of a Node
struct Node
{
	int data;
	Node* left, *right;

	// Constructor of the class
	Node(int item)
	{
		data = item;
		left = right = NULL;
	}
};

// Stores the count of required pairs
int result = 0;

// Function to perform dfs to find pair of
// leaf nodes at most K distance apart
vector<int> dfs(Node* root, int distance)
{
	
	// Return empty array if node is NULL
	if (root == NULL)
	{
		vector<int> res(distance + 1, 0);
		return res;
	}

	// If node is a leaf node and return res
	if (root->left == NULL &&
	root->right == NULL)
	{
		vector<int> res(distance + 1, 0);
		res[1]++;
		return res;
	}

	// Traverse to the left
	vector<int> left = dfs(root->left,
						distance);

	// Traverse to the right
	vector<int> right = dfs(root->right,
							distance);

	vector<int> res(distance + 1, 0);

	// Update the distance between left
	// and right leaf node
	for(int i = res.size() - 2;
			i >= 1; i--)
		res[i + 1] = left[i]+ right[i];

	// Count all pair of leaf nodes
	// which are at most K distance apart
	for(int l = 1;l < left.size(); l++)
	{
		for(int r = 0;r < right.size(); r++)
		{
			if (l + r <= distance)
			{
				result += left[l] * right[r];
			}
		}
	}

	// Return res to parent node
	return res;
}

// Driver Code
int main()
{
	
	/*
		1
		/ \
	  2     3
	/  \
	4   14
	*/

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(14);
	// root->right->left = new Node(9);

	// Given distance K
	int K = 3;

	// Function call
	dfs(root, K);

	cout << result;
}

// This code is contributed by mohit kumar 29

// pair of node at k-distance
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

