/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], 
where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127


*/

class Solution {
public:
    /*APPROACH:
    I think this question looks like the most difficult question until you get to the right 
    track. The idea is you try to find an answer based on possible candidates. I will try to 
    briefly explain it using 8 bits instead of 32 bits.

    Assume that we have 8 bit ints. Our max result could be 11111111. To achieve this there must 
    be two numbers when XORed their MSB should give 1.

    So our first mask is 1000000. (1 shifted all the way to the left). Since we are only checking 
    the first digit we AND the nums with this mask and add to a hash table. Then for each number 
    in our input we test if there's a corresponding number that would give this. If there's then 
    our next candidate is 11000000, if not then our next candidate is 0100000.

    The trick is that while we are using the hash table we search for " candidate ^ *it " if this 
    exists then it means there is a " nums[x] ^ *it " that gives the candidate based on the XOR 
    property A = B ^ C => A ^ C = B

    So we iterate through all the possible candidates. The outer loop can start from 30 or 31.
    */
    // TC = O(32*N) = O(N)
    int findMaximumXOR(vector<int>& nums) {
        int mask=0, result=0;
        int n = nums.size();

        for(int i=30; i>=0; i--){
            mask = mask | (1<<i);

            unordered_set<int> st;
            for(int k=0; k<n; k++)
                st.insert(mask & nums[k]);

            int candidate = result | (1<<i);
            for(auto it:st){
                if(st.find(it^candidate)!=st.end()){
                    result = candidate;
                    break;
                }
            }

        }
        return result;
    }
};
