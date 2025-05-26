/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

 

Example 1:

Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
*/

class Solution {
public:
    // /*
    int totalHammingDistance(vector<int>& nums) {
        
    // Initialize a mask to the most significant bit position
    uint32_t mask = pow(2,31);
    
    // Initialize a variable to store the total Hamming distance
    int ans = 0;

    // Iterate over all 32 bit positions
    while(mask>0){
        // Initialize variables to count the number of ones and zeros
        int ones=0, zeros=0;
        // Iterate over all elements in the vector nums
        for(int val:nums){
            // Check if the current bit is 1 for the current element
            if(mask&val){
                ones++;
            }
            // Otherwise, the current bit is 0 for the current element
            else{
                zeros++;
            }
        }
        // Calculate the contribution of the current bit position to the total Hamming distance
        ans += ones*zeros;
        // Shift the mask right by 1 bit to move to the next bit position
        mask = mask>>1;
    }
    // Return the total Hamming distance
    return ans;
}

    // */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<32; i++){
            int count1=0, count0=0;
            for(int val:nums){
                if((1<<i)&val){
                    count1++;
                }
                else count0++;
            }
            ans += count1*count0;
        }
        return ans;
    }
};

};