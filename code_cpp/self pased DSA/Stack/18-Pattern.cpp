#include<bits/stdc++.h>
using namespace std;
/*
Problem: 
Given an array of n integers nums, a 132 pattern is a subsequence of three 
integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
Return true if there is a 132 pattern in nums, otherwise, return false.

 

Approach: 
let we have and array [a1, a2, a3, a4, a5, a6, a6]
consider each element as an peak element of lets say a4, find the smallest element in left 
side of a4 and maximum element in right side of a4 which is smaller 
than a4( called second Maximum element), if secondMax > least element of left side return true. 
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<int> st;
        int secMax=INT_MIN;
        
        // start from last index
        for(int i=nums.size()-1; i>=0; i--)
        {
            // check if current element is smaller than secMax[because peak is at top of stack]
            if(nums[i] < secMax) return true;
            
            // check if current element is greater than peak of stack, compare stack top element
            // with secMax is top is greater than secMax sore that and than than delete the top
            while(!st.empty() && nums[i] > st.top()){
                secMax = max(secMax ,st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};


int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(2);

    Solution ob;
    cout<<ob.find132pattern(nums)<<endl;
    return 0;
}
/*
Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
*/