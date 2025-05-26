#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

/*
Approach:
Let's first understand this property:

If (a*b)%k==0, then
gcd(a,k) * gcd(b,k) % k is also 0.
*/

class Solution {
public:

    long long gcd(int x, int y)
    {
        // check if x is smaller than y, then change the order
        if(x < y)
            return gcd(y, x);
        // check if y becomes 0, then return x else return gcd(y, x%y)
        return y==0? x : gcd(y, x%y);
    }
    long long countPairs(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        long long ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            long long gcd1 = gcd(nums[i], k);
            // find all those gcd2, when we multiply gcd1 * gcd2 it can be dividable by k then they will make pairs 
            for(auto x: mp)
            {
                long long gcd2 = x.first;
                long long count = x.second;
                if((gcd1 * gcd2) % k ==0)
                    ans = ans + count;
            }
            // push the gcd1 and there count into map
            mp[gcd1]++;
        }
        return ans;
    }
};


int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    int k = 2;

    Solution ob;
    cout<<ob.countPairs(nums, k)<<endl;
    return 0;
}
/*
Input: nums = [1,2,3,4,5], k = 2
Output: 7
*/