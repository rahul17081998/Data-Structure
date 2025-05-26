// longest common subsequence
// Approch: binary search
// Time = theta(N*logN), Space = theta(N)
#include<bits/stdc++.h>
using namespace std;
// ceiling of a value in an array
// try to use optimised method below code is written
int ceilIdx(int tail[], int l, int r, int x)
{
    while(r>l)
    {
        int m = l+(r-l)/2;
        if(tail[m] >= x)
            r = m;
        else
            l = m+1;
    }
    return r;
}
// lis function
int LIS(int arr[], int n)
{
    int tail[n];
    tail[0] = arr[0];
    int len = 1;

    for (int i = 1; i < n; i++)
    {
        // cheak if current element is greater than
        // last element of tail array

        // if yes, then put this at the end of tail array 
        if(arr[i] > tail[len-1]){
            tail[len] = arr[i];
            len++;
        }
        // if no, find celling of element in tail array
        // and replce at their index with current element
        else
        {
            int celing = ceilIdx(tail, 0, len-1, arr[i]); // return ceiling element index
            tail[celing] = arr[i];
        }
        
    }
    return len;
    
}
/*
// Method 2: use lowerbound function 
// Time=O(N*logN)

// Leetcode
int lengthOfLIS(vector<int>& nums) 
{
    vector<int> temp;
    temp.push_back(nums[0]);

    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i] > temp.back())
            temp.push_back(nums[i]);
        else{
            // subtracting temp.beging for integer valur from iterator
            int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[index]=nums[i];
        }
    }
    return temp.size();
}
*/
int main(){
    int arr[] = {3, 4, 2, 8, 10};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Longest common subsequence length: "<<LIS(arr, n)<<endl;
    return 0;
}