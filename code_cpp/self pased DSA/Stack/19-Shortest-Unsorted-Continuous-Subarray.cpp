#include<bits/stdc++.h>
using namespace std;

/*
Problem:
Given an integer array nums, you need to find one continuous subarray that if you only sort 
this subarray in ascending order, then the whole array will be sorted in ascending order.
Return the shortest such subarray and output its length.





Approach: 
we have to find left and right index from where array will sorted if we sort the 
contiguous subarray from left and right index, so will do it using stack

for find left index inalitalize the left index equal to n-1, we will push the element if current nums[i] is 
grater then or equal to the top of stack 
while we found the stack top element is greate then current nums[i] thn if top elements index is lower 
then the left index previously stored we will 
keep store it then we will pop it. 
then push the current element index.

similarly we will do to find right index but there we will check while top is less then current 
index value we will keep store maximim index and pop it. 
we started for leep here from right side.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        stack<int> st;
        
        int l=n-1; // left index
        for(int i=0; i<n; i++)
        {
            // check if top of stack is greater then current elelent
            // store the index of top element if it is smaller and pop it
            while(!st.empty() && nums[st.top()] > nums[i]){
                l = min(l, st.top());
                st.pop();
            }
            st.push(i); // push the current index
        }
        while(!st.empty()) st.pop();
        
        
        int r=0; // right index
        for(int i=n-1; i>=0; i--)
        {
            // check if top of stack is smaller then current elelent
            // store the index of top element if it is greater and pop it
            while(!st.empty() && nums[st.top()] < nums[i]){
                r = max(r, st.top());
                st.pop();
            }
            st.push(i); // push the current index
        }
        
        if(l>=r) return 0;
        return r-l+1; // return the length to sort the subarray
    }
};


int main(){
    // input
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(10);
    nums.push_back(9);
    nums.push_back(15);
    Solution ob;
    cout<<ob.findUnsortedSubarray(nums)<<endl;
    return 0;
}
/*
Input: nums = [2,6,4,8,10,9,15]
Output: 5

Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole 
array sorted in ascending order.
*/