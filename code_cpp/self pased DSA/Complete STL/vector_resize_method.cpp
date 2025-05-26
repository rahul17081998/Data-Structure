#include<bits/stdc++.h>
using namespace std;

//write your function here
class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n+1, 0);
        // prefixSum.push_back(0);
        for(int i=0; i<nums.size(); i++)
            prefixSum[i+1] = prefixSum[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 */

int main(){
    
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(-5);
    nums.push_back(2);
    nums.push_back(-1);
    int left =2, right=5;
    // O/P: -1

    NumArray* obj = new NumArray(nums);
    int param_1 = obj->sumRange(left,right);
    cout<<param_1<<endl;
    return 0;
}
/*
Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]
*/