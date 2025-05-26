/*
A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.
*/

#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    // VVI: for circular array type question
    // TC = O(N), SC = O(N)       
    int minSwaps(vector<int>& nums) {
        
        /*
        APPROACH: we will using sliding window concept and two pointer approach here.
        At first we ll count how many one's are in the array then make a duplicate of nums
        and add both basically to counter circular array we just add one more same array with 
        prexisting array than array length becomes 2n.
        Now we will make a window of size = number of ones in original array, with back pointing 
        with 'start' and forward part pointing with 'end'. then every time check how many zeros 
        contaning inside of sliding window that much times we need to make swapping to make 
        all elements inside window 1. 
        So minimum zero in a perticulaer window is representing that we requires minimum swapping to make all 1's 
        together and that will be our answer.
        */

        int countOnes =0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==1) countOnes++;
            nums.push_back(nums[i]); // add the same value at the last
        }
        // make a window of size countOnes and check how many zeros we have
        int ans= INT_MAX;
        int zeros=0;
        for(int i=0; i<countOnes; i++){
            if(nums[i]==0)
                zeros++;
        }

        ans = zeros;
        int s=0, e=countOnes;
        // /*
        while(e<nums.size()){
            if(nums[e]==0)
                zeros++;

            if(nums[s]==0){
                zeros--;
            }
            ans = min(ans,zeros);
            e++;
            s++;
            
        }
        // */
       
        return ans;

    }
};

int main(){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);

    Solution obj;
    cout<<obj.minSwaps(nums)<<endl;
    return 0;
}

/*
Input: nums = [0,1,0,1,1,0,0]
Output: 1
*/