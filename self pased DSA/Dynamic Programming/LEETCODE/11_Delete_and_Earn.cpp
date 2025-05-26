#include<bits/stdc++.h>
using namespace std;

// variation of housing robbry problem
class Solution {
public:
    // method 2: house robbry approach
    // TC = O(N)
    // SC = O(N)
    int solve2(vector<int> &nums)
    {
        int bucket[10001]={0};

        for(int num: nums)
            bucket[num] += num;
        // initialize the dp array
        int dp[10001];
        // base case
        dp[0]=bucket[0];
        dp[1]=bucket[1];
        
        for(int i=2; i<10001; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + bucket[i]);
        }
        
        return dp[10000];
    }
    
    // method 1: coding Decoded
    int solve1(vector<int> &nums)
    {
        // create a frequency array
        vector<int> freq(10002,0);
        vector<int> dp(10002);
        
        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        
        // base case
        dp[0]=0;
        dp[1]=1*freq[1];
        
        for(int i=2; i<10002; i++)
            dp[i] = max(dp[i-1], dp[i-2]+i*freq[i]);
        
        return dp[10001];
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        return solve2(nums);
       
    }
};

int main(){
    
    // input
    cout<<"Enter input: "<<endl;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    Solution ob;
    cout<<ob.deleteAndEarn(nums)<<endl;

    return 0;
}

/*
input:

6
2 2 3 3 3 4

here 6 is the size of input array
output:
9

*/