#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lisFromLeft(vector<int>& arr)
    {
        int n= arr.size();
        vector<int> lis(n, 1);
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(arr[i]>arr[j] && lis[i] <= lis[j])
                    lis[i] = lis[j]+1;
            }
        }
        return lis;
    }
    
    vector<int> lisFromRight(vector<int>& arr)
    {
        int n= arr.size();
        vector<int> lis(n, 1);
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=n-1; j>i; j--)
            {
                if(arr[i]>arr[j] && lis[i] <= lis[j])
                    lis[i] = lis[j]+1;
            }
        }
        return lis;
    }
    void printarr(vector<int> arr){
        for(auto x: arr) cout<<x<<" ";
    }
    // main function
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> lisLeft, lisRight;
        
        lisLeft = lisFromLeft(nums); // find lis for each element from left side
        lisRight = lisFromRight(nums); // find lis for each element from right side
        /*printarr(lisLeft);
        cout<<endl;
        printarr(lisRight);*/
        
        // find maximum sum of lis from left side and right side for each ele
        int maxi=0;
        for(int i=0; i<n; i++){
            // if any element have no other previous smaller element either from
            // left or right side that element can not become a peack of Mountain Array
            if(lisLeft[i]==1 || lisRight[i]==1) continue;
            maxi = max(maxi, lisLeft[i] + lisRight[i]);
        }
        return n-(maxi-1);
    }
};


int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    Solution ob;
    cout<<ob.minimumMountainRemovals(nums)<<endl;
    return 0;
}

/*
Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making 
the array nums = [1,5,6,3,1].
*/
