class Solution {
public:
    /*
    problem: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
    
    Intuition
    To find the frequency of the longest increasing sequence, we need
    First, know how long is the longest increasing sequence
    Second, count the frequency
    Thus, we create 2 lists with length n
    dp[i]: meaning length of longest increasing sequence
    cnt[i]: meaning frequency of longest increasing sequence
    If dp[i] < dp[j] + 1 meaning we found a longer sequence and dp[i] need to be updated, 
    then cnt[i] need to be updated to cnt[j]
    If dp[i] == dp[j] + 1 meaning dp[j] + 1 is one way to reach longest increasing sequence 
    to i, so simple increment by cnt[j] like this cnt[i] = cnt[i] + cnt[j]
    Finally, sum up cnt of all longest increase sequence will be the solution
    This is a pretty standard DP question. Just like most sequence type of DP question, 
    we need to loop over each element and check all previous stored information to update 
    current.
    Time complexity is O(n*n)*/
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lis(n, 1), cnt(n, 1);
        int maxlen=1;
        
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    
                    if(lis[j]+1 > lis[i]){
                        lis[i] = lis[j]+1;
                        cnt[i] = cnt[j];
                    } 
                    // this means there are more subsequences which have same length 
                    else if(lis[j]+1 == lis[i])
                        cnt[i] += cnt[j];
                }
            }
            maxlen = max(maxlen, lis[i]);
        }
        
        // find max
        int count=0;
         for(int i=0; i<n; i++){
             if(lis[i]==maxlen)
                 count += cnt[i];
         }
        return count;
    }
};