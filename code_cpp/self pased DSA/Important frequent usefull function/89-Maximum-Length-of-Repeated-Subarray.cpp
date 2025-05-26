#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    // longest common array
    int lca(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        // create a rd vector for dp
        // initialize with 0
        vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
        int res=0;
        // base case if any of the array have no element then we have 0 common array
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                // check if current value matches
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        return lca(nums1, nums2);
        
    }
};

int main(){
    // input
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(2);
    nums1.push_back(1);
    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(2);
    nums2.push_back(1);
    nums2.push_back(4);
    nums2.push_back(7);

    Solution ob;
    cout<<ob.findLength(nums1, nums2);
    return 0;
}
/*
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
*/