#include<bits/stdc++.h>
using namespace std;

// method 3: better
int jump3(vector<int>& nums) {
        
        // Method 1: BFS
        // Tc=O(N)
        // Sc=O(N)

        /*
        int n=nums.size();
            
        queue<int> q;
        q.push(0);
        int level=0;
        
        vector<int> vis(n, 0);
        while(!q.empty())
        {
            int size=q.size();
            while(size-- > 0)
            {
                int currentIndex=q.front();
                q.pop();
                // check if already visited then ignore
                if(vis[currentIndex]==1)
                    continue;
                // check if current index reaches at last index
                if(currentIndex == n-1)
                    return level;
                // maximum reaching index from current index
                int maxIndex = min(currentIndex + nums[currentIndex], n-1);
                while(maxIndex>currentIndex)
                {
                    if(!vis[maxIndex])
                        q.push(maxIndex);
                    maxIndex--;
                }
                // mark visited index
                vis[currentIndex]=1;
            }
            level++; // increase level once you poped all element of one level
        }
        return level;
        */
        
        // Method 2: Greedy
        // Tc=O(N)
        // Sc=O(1)
        
        int level=0;
        int devider=0;
        int maxRech=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            // to check wether we are able to reach n-1 the index or not
            if(maxRech < i) return -1; // you can not reach last endex
            
            if(i>devider)
            {
                level++;
                devider=maxRech;
            }
            maxRech = max(maxRech, i+nums[i]);
        }
        return level;
    }



// start from end and we will consider all those ends from which we can reach the last cell
// recursive sol
int MinJump(int arr[], int n)
{
    // base case 
    if(n==1) return 0;
    int res = INT_MAX;

    for (int i = 0; i <= n-2; i++)
    {
        if(i + arr[i] >= n-1)
        {
            int sub_res = MinJump(arr, i+1);
            if(sub_res!=INT_MAX){
                res = min(res, sub_res+1);
            }
        }
    }
    return res==INT_MAX? -1:res;
    
}
// dp
int MinJump_dp(int arr[], int n)
{
    int dp[n];
    // initiallize first cell 0, rest of cells Infinite
    for(int i=1; i<n; i++){
        dp[i] = INT_MAX;
    }
    // initiallize first cell 0
    dp[0] = 0;

    // find how many existing paths are possible to reach directally ith cell element 
    // using 0 to i-1 cells, take minimum of those path
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            // check if path is possible to reach
            if(arr[j] + j >= i){
                if(dp[j]!=INT_MAX)
                    dp[i] = min(dp[i], dp[j]+1);
            }
        }
    }
    return dp[n-1]==INT_MAX? -1: dp[n-1];
}

int main(){
    int arr[] = {1, 0, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Min jumps required / recursive = "<<MinJump(arr, n)<<endl;
    cout<<"Min jumps required / dp = "<<MinJump_dp(arr, n)<<endl;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    cout<<"Min jumps required = "<<jump3(nums)<<endl;
    return 0;
}