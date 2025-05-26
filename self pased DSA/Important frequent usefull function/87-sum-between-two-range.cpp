/*
You have given an array and range[low, high]
you have to find sum from low index upto high index
include low and high index also in sum

*/ 

#include<bits/stdc++.h>
using namespace std;

//write your function here
int sumRange(vector<int> &nums, int low, int high)
{
    int n = nums.size();
    // create prefix sum array
    vector<int> prefixSum(n+1, 0);
    for(int i=0; i<n; i++)
        prefixSum[i+1] = prefixSum[i] + nums[i];

    return prefixSum[high+1] - prefixSum[low];
}

int main(){
    
    // input
    // [4 2 6 1 -4 2]
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(-4);
    nums.push_back(2);
    int low=2;
    int high=4;
    // o/p:  3
    cout<<"sumRange[low, high] = "<<sumRange(nums, low, high)<<endl;
    return 0;
}