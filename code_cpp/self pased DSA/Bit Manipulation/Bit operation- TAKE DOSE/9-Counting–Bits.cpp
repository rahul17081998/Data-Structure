/*
Given an integer n, return an array ans of length n + 1 such that 
for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 
*/





class Solution {
public:
    // TC = O(N), SC = O(N)
    vector<int> countBits(int n) {
        // use a map/array to store the previous values counting
        vector<int> memo;
        for(int x=0; x<=n; x++){
            // count the number of bits into x
            if(x==0){
                memo.push_back(0);
                continue;
            }
            // count if its lsb bit is 1 or not
            int countOne=0;
            if((x&1)==1){
                countOne++;
                
            }

            memo.push_back(countOne + memo[x/2]);
        }

        return memo;
    }
};