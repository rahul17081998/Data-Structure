   // 1-Calculate Region
 vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        // method 2:
        vector<long long> res(n, -1);
        stack<long long> st;
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[i] >= st.top())
                st.pop();
            res[i]= st.empty() ? -1:st.top();
            st.push(arr[i]);
        }
        return res;
 }

 #include<bits/stdc++.h>
using namespace std;

// Naive solution: Tc= (n^2)
void nextGreEle(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i+1; j<n; j++)
        {
            if(arr[j]>=arr[i])
            {
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j==n)
            cout<<-1<<" ";
    }
}

// Efficient solution: Tc=𝜃(n), Aux space=O(n)
void Eff_nextGreele(int arr[], int n)
{
    stack<int> s;
    int temp[n];
    temp[n-1]=-1;
    s.push(arr[n-1]);
    for (int i = n-2; i >= 0; i--)
    {
        while(s.empty()==false && arr[i]>=s.top())
        {
            s.pop();
        }
        int pq=s.empty()?-1:s.top();
        temp[i]=pq;
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<temp[i]<<" ";
    }
    
    
}
int main()
{
    int arr[]={15,10,18,12,4,6,2,8};
    // int arr[]={8,12,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    nextGreEle(arr,n);
    cout<<endl;
    Eff_nextGreele(arr,n);
    return 0;
}



// previous greater element

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Naive approch
void prGreEle(int arr[], int n)
{
    cout<<-1<<" ";
    for(int i=1; i<n; i++)
    {
        int j;
        for (j = i-1; j>=0; j--)
        {
            if(arr[j]>=arr[i])
            {
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j==-1)
            cout<<-1<<" ";
        
    }
}
// Efficient solution
void Eff_prevGreEle(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout<<-1<<" ";
    for (int i = 1; i < n; i++)
    {
        while(s.empty()==false && arr[i]>=s.top())
        {
            s.pop();
        }
        if(s.empty()==false)
        {
            cout<<s.top()<<" ";
        }
        else
        {
            cout<<-1<<" ";
        }
        
        s.push(arr[i]);
    }
    
}
int main(){
    int arr[]={15,10,18,12,4,6,2,8,55};
    // int arr[]={8,12,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    prGreEle(arr, n);
    cout<<endl;
    Eff_prevGreEle(arr, n);
    return 0;
}


// 2-inversion-count
// returns count of inversion of size 3
int getInvCount(int arr[], int n)
{
    int invcount = 0; // initialize result
     
    for (int i=0 ; i< n-1; i++)
    {
        // count all smaller elements on right of arr[i]
        int small=0;
        for (int j=i+1; j<n; j++)
            if (arr[i] > arr[j])
                small++;
                 
        // count all greater elements on left of arr[i]
        int great = 0;
        for (int j=i-1; j>=0; j--)
                    if (arr[i] < arr[j])
                        great++;
                 
        // update inversion count by adding all inversions
        // that have arr[i] as middle of three elements
        invcount += great*small;
    }
    return invcount;
}


// 3-coin-change// umbrella
// Coin Change
class Solution {
public:
    int solve(vector<int>& coins, int amount, int i, vector<vector<int>> &dp)
    {
        // base case
        if(i >= coins.size() || amount<=0)
            return amount==0 ? 0:INT_MAX-1;
        
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        int res=-1;
        // check if coins value is higher than amount than you can not take that coin, you have to skip that
        if(coins[i] > amount){
            int skipKro = 0 + solve(coins, amount, i+1, dp);
            res = skipKro;
        }
        else{
            int includeKro = 1 + solve(coins, amount-coins[i], i, dp);
            int skipKro = 0 + solve(coins, amount, i+1, dp);
            res = min(includeKro, skipKro);
        }
        return dp[i][amount]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        // memoization
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        
        int ans = solve(coins, amount, 0, dp);
        return ans==INT_MAX-1? -1:ans;
    }
};


// 4-cherry-pickup
class Solution {
public:
    const int inf=(int)(-1e7);
    int solve(vector<vector<int> >&grid,int i1,int j1,int i2,vector<vector<vector<
              int> > >&dp,int n)
    {
        int j2=i1+j1-i2;
        if(i1==n || i2==n || j1==n || j2==n || grid[i1][j1]==-1 ||grid[i2][j2]==-1)
            return inf;
        if(i1==n-1 && j1==n-1 && i2==n-1 && j2==n-1)
            return grid[i1][j1];
        if(dp[i1][j1][i2]!=-1)
            return dp[i1][j1][i2];
        int cnt=0;
        if(i1==i2 && j1==j2)
            cnt+=grid[i1][j1];
        else
            cnt+=grid[i1][j1]+grid[i2][j2];
        int opt1=solve(grid,i1+1,j1,i2+1,dp,n);// hh
        int opt2=solve(grid,i1+1,j1,i2,dp,n);// hv
        int opt3=solve(grid,i1,j1+1,i2+1,dp,n);// vh
        int opt4=solve(grid,i1,j1+1,i2,dp,n);// vv
        return dp[i1][j1][i2]=cnt+max(opt1,max(opt2,max(opt3,opt4)));
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int i1=0,j1=0,i2=0,j2=0;
        vector<vector<vector<int> > >dp(n,vector<vector<int> >(n,vector<int>(n,-1)));
        int p= solve(grid,i1,j1,i2,dp,n);
        if(p<0)
            return 0;
        else
            return p;
    }
};




// 5-Tree-based-question
// given edges in (parent,child) form. Return Lexicographically least Preorder traversal.

/*
5
5 6
5 4
4 8
4 9
6 7
*/

string getpre(int root,unordered_map<int,pair<int,int>> &g){
    string preorder="",c1,c2="";
    preorder+=to_string(root);
    if(g.find(root)==g.end()){
        return preorder;
    }
    c1=getpre(g[root].first,g);
    if(g[root].second!=-1){
        c2=getpre(g[root].second,g);
    }
    if(c1.compare(c2)<0){
        preorder+=c1;
        preorder+=c2;
    }
    else{
        preorder+=c2;
        preorder+=c1;        
    }
    return preorder;
}
void smallestPreorder(int a[][2],int n,unordered_set<int> &s){
    unordered_map<int,pair<int,int>> g;
    int p,c,root;
    for(int i=0;i<n;i++){
        p=a[i][0],c=a[i][1];
        if(g.find(p)==g.end()){
            g[p].first=c;
            g[p].second=-1;
        }
        else{
            g[p].second=c;
        }
        s.erase(c);
    }
    if(s.size()==1){
        root=*s.begin();
    }   
    else{
        cout<<s.size();
        return;
    }
    cout<<getpre(root,g);
}
int main() {
    int n,i=0;
    cin>>n;
    int tree[n][2];
    unordered_set<int> s;
    while(n--){
        cin>>tree[i][0]>>tree[i++][1];
        s.insert(tree[i-1][0]);
        s.insert(tree[i-1][1]);
    }
    smallestPreorder(tree,i,s);
}

// 6-Activity-selection
// activity-selection-problem-grefaceedy-algo-1
class Solution
{
    public:
    
    static bool cmp(pair<int,int> a, pair<int,int> b)
    {
        return a.second < b.second;
    }
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> jobs;
        for(int i=0; i<n; i++){
            jobs.push_back({start[i], end[i]});
        }
        // sort the jobs array on the basis of end time 
        sort(jobs.begin(), jobs.end(), cmp);
        
        int ans=1;
        int prev=0;
        for(int curr=1; curr<jobs.size(); curr++)
        {
            if(jobs[curr].first > jobs[prev].second){
                ans++;
                prev = curr;
            }
        }
        return ans;
    }
};