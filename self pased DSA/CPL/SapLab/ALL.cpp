// 1-Calculate-region
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

// 2-Job-Sequencing-Problem
// Given a set of N jobs where each jobi has a deadline and profit associated with it.
// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
// We earn the profit associated with job if and only if the job is completed by its deadline.
// Find the number of jobs done and the maximum profit.
// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that 
// Job.


/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
        
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, cmp);
        vector<int> vis(n, 0);
        int maxprofit = 0;
        int countJob=0;
        for(int i=0; i<n; i++)
        {
            int dline = arr[i].dead;
               // Find a free slot for this job (Note that we start
                // from the last possible slot)
            for(int r=min(dline, n)-1; r>=0; r--){
                if(vis[r]==0)
                {
                    maxprofit += arr[i].profit;
                    vis[r]=1;
                    countJob++;
                    break;
                }
            }
            
        }
        
        vector<int> ans;
        ans.push_back(countJob);
        ans.push_back(maxprofit);
        return ans;
        
    } 
};

// 3-coin-change
// 3-coin-change umbrella
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

// 6-Activity-selection
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

// 7
// CPP program to find maximum points that can
// be collected in a journey from top to bottom
// and then back from bottom to top,
#include <bits/stdc++.h>
#define MAX 5
#define N 5
#define M 5
#define inf 100000
using namespace std;

// Calculating the points at a (row1, col1) &&
// (row2, col2) from path1 && path2
int cost(char grid[][M], int row1, int col1,
						int row2, int col2)
{
	// If both path is at same cell
	if (row1 == row2 && col1 == col2) {

		// If the cell contain *, return 1
		if (grid[row1][col1] == '*')
			return 1;

		// else return 0.
		return 0;
	}

	int ans = 0;

	// If path 1 contain *, add to answer.
	if (grid[row1][col1] == '*')
		ans++;

	// If path contain *, add to answer.
	if (grid[row2][col2] == '*')
		ans++;

	return ans;
}

// Calculate the maximum points that can be
// collected.
int solve(int n, int m, char grid[][M],
		int dp[MAX][MAX][MAX], int row1,
					int col1, int row2)
{
	int col2 = (row1 + col1) - (row2);

	// If both path reach the bottom right cell
	if (row1 == n - 1 && col1 == m - 1 &&
		row2 == n - 1 && col2 == m - 1)
		return 0;

	// If moving out of grid
	if (row1 >= n || col1 >= m ||
		row2 >= n || col2 >= m)
		return -1 * inf;

	// If already calculated, return the value
	if (dp[row1][col1][row2] != -1)
		return dp[row1][col1][row2];

	// Variable for 4 options.
	int ch1 = -1 * inf, ch2 = -1 * inf;
	int ch3 = -1 * inf, ch4 = -1 * inf;

	// If path 1 is moving right and path 2
	// is moving down.
	if (col1 + 1 < m && row2 + 1 < n && grid[row1][col1 + 1] != '#' &&
		grid[row2 + 1][col2] != '#')
	ch1 = cost(grid, row1, col1 + 1, row2 + 1, col2) +
		solve(n, m, grid, dp, row1, col1 + 1, row2 + 1);

	// If path 1 is moving right and path 2 is moving
	// right.
	if (col2 + 1 < m && col1 + 1 < m && grid[row1][col1 + 1] != '#' &&
		grid[row2][col2 + 1] != '#')
	ch2 = cost(grid, row1, col1 + 1, row2, col2 + 1) +
			solve(n, m, grid, dp, row1, col1 + 1, row2);

	// If path 1 is moving down and path 2 is moving right.
	if (col2 + 1 < m && row1 + 1 < n && grid[row1 + 1][col1] != '#' &&
		grid[row2][col2 + 1] != '#')
	ch3 = cost(grid, row1 + 1, col1, row2, col2 + 1) +
		solve(n, m, grid, dp, row1 + 1, col1, row2);

	// If path 1 is moving down and path 2 is moving down.
	if (row1 + 1 < n && row2 + 1 < n && grid[row1 + 1][col1] != '#' &&
		grid[row2 + 1][col2] != '#')
	ch4 = cost(grid, row1 + 1, col1, row2 + 1, col2) +
		solve(n, m, grid, dp, row1 + 1, col1, row2 + 1);

	// Returning the maximum of 4 options.
	return dp[row1][col1][row2] = max({ch1, ch2, ch3, ch4});
}

// Wrapper Function
int wrapper(int n, int m, char grid[N][M])
{
	int ans = 0;
	int dp[MAX][MAX][MAX];
	memset(dp, -1, sizeof dp);

	// If last bottom right cell is blocked
	if (grid[n - 1][m - 1] == '#' || grid[0][0] == '#')
		ans = -1 * inf;

	// If top left cell contain *
	if (grid[0][0] == '*')
		ans++;
	grid[0][0] = '.';

	// If bottom right cell contain *
	if (grid[n - 1][m - 1] == '*')
		ans++;
	grid[n - 1][m - 1] = '.';

	ans += solve(n, m, grid, dp, 0, 0, 0);
	return max(ans, 0);
}

// Driven Program
int main()
{
	int n = 5, m = 5;

	char grid[N][M] = {
		{ '.', '*', '.', '*', '.' },
		{ '*', '#', '#', '#', '.' },
		{ '*', '.', '*', '.', '*' },
		{ '.', '#', '#', '#', '*' },
		{ '.', '*', '.', '*', '.' }
	};

	
    
    cout << wrapper(n, m, grid) << endl;
	return 0;
}
