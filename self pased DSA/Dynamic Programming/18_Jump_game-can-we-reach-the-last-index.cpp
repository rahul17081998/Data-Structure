#include<bits/stdc++.h>
using namespace std;

/*Return true if you can reach the last index, or false otherwise.*/
// method 2: 
class Solution {
public:

    bool canJump2(vector<int>& nums) {
        int n = nums.size();
        int maxReach=nums[0];// maximum reach from 0th index = 0 + nums[0]

        for(int i=0; i<n; i++)
        {
            // At any point, if you find that current index is greater than maximum reach index
            // it means you can not reach to last index.
            if(maxReach<i) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }

    // method 1:Greedy solution tc=O(N), sc=O(1)
    bool canJump1(vector<int>& nums) {
     
        int n = nums.size();
        if(n==1) return true; // corner case
        
        int maxReach = nums[0];
        int i=1;
        while(maxReach >= i)
        {
            // check if you reach at last index
            if(maxReach >= n-1)
                return true;
            // check if current index and value sum is greater than maxReach point, if yes
            // then maxReach is equal index + value
            if(i + nums[i] > maxReach)
                maxReach = i+nums[i];
            i++;
        }
        return false;
    }
};


int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(4);
    // o/p: 0 --> can not reach 
    Solution ob;
    cout<<ob.canJump1(nums)<<endl;
    cout<<ob.canJump1(nums)<<endl;
    return 0;
}
/*
Input: nums = [3,2,1,0,4]
Output: false
*/