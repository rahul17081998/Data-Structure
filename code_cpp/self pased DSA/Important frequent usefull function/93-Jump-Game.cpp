#include<bits/stdc++.h>
using namespace std;

//write your function here

bool canJump(vector<int>& nums) {
    
    int n = nums.size();
    if(n==1) return true;
    
    int maxReach = nums[0];
    int i=1;
    while(maxReach >= i)
    {
        // check if you reached at last index
        if(maxReach >= n-1)
            return true;
        // if 
        if(i + nums[i] > maxReach)
            maxReach = i+nums[i];
        i++;
    }
    return false;
}
// revision
bool solve(vector<int> nums)
{
    int n = nums.size();
    if(n==1) return true;

    int maxR=nums[0];
    for (int i = 0; i < n; i++)
    {
        if(maxR >= n-1) return true;
        if(i>maxR) return false;
        maxR = max(maxR, i+nums[i]);
    }
    return true;
    
}

int main(){
    vector<int> nums;
    // Input: nums = [2,3,1,1,4]
    // Output: true
    // Input: nums = [3,2,1,0,4]
    // Output: false
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    cout<<canJump(nums)<<endl;
    cout<<solve(nums)<<endl;
    return 0;
}