#include<bits/stdc++.h>
using namespace std;

//write your function here
/*
bool static comp(string &a, string &b)
{
    if(a.length() < b.length())
        return true;
    else if(a.length() == b.length())
        return a<b;
    return false;
    
}
void  sortString(vector<string> &nums)
{
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++)
        cout<< nums[i]<<" ";

    cout<<endl;
}
*/


class Solution {
public:
    // Leetcode link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/
    // if string have same length than we can sort them directally, irrespective of leading zeros
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        int n = nums.size();
        
        for(auto query: queries)
        {
            int k = query[0];
            int trim = query[1];
            vector<pair<string, int>> vp;
            for(int i=0; i<n; i++)
            {
                vp.push_back({nums[i].substr(nums[i].length()-trim), i});
            }
            sort(vp.begin(), vp.end());
            ans.push_back(vp[k-1].second);
        }
        return ans;
    }
};

int main(){
    vector<string> nums;
    nums.push_back("104");
    nums.push_back("466");
    nums.push_back("101");
    nums.push_back("003");
    nums.push_back("479");
    nums.push_back("193");
    nums.push_back("129");
    nums.push_back("134");
    nums.push_back("104");
    // sortString(nums);
    return 0;
}
/*
Input: nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
Output: [2,2,1,0]
*/