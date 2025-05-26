#include<bits/stdc++.h>
using namespace std;

/*
diff  = target
Let sum of subset 1 be s1 and subset 2 with s2
s1 - s2 = diff (given)
s1 + s2=sum of array (logical)
Therefore adding both eq we get :
2s1= diff + sum of array
s1= (diff + sum of array)/2;
s2 = (sum 0f array - target)/ 2  // use this equation
Problem reduces to find no of subsets with given sum**
*/

int subsetOfCount(vector<int> nums, int sum)
{
    int n = nums.size();
    int t[n+1][sum+1];
    
    t[0][0] = 1;
    for(int j=1; j<sum+1; j++) 
        t[0][j] = 0;
    
    for(int i=1; i<n+1; i++)
        for(int j=0; j<sum+1; j++)
        {
            if(nums[i-1] <= j)
                t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
            else
                t[i][j] = t[i-1][j];
        }
    return t[n][sum];
}



int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for(int i=0; i<nums.size(); i++)
        sum += nums[i];
    if((sum + target)%2 == 1 || target>sum)
            return 0;
    
    int s1 = (sum - target)/2;
    return subsetOfCount(nums, s1);
}


int main(){
    // int arr[] = {1, 6, 5, 11};
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(30);
    arr.push_back(11);
    arr.push_back(1);
    
    int target = 18;
    // cout<<countSubsetDiff(arr, n, diff);
    // cout<"Number of subsets with given difference is "<<countSubsetDiff(arr, n, diff)<<endl;
    cout<<findTargetSumWays(arr, target);
    return 0;
}