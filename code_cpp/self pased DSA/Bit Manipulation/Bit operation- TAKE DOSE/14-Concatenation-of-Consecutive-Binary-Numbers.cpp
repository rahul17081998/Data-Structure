/*
Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

Example 1:

Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
*/

class Solution {
public:
    /* newNo= P*2^D + x
    where,
        p = previous calculated value
        x = current number
        D = number of bits of x = log2(x)+1
    */
    // TC = O(N), SC = O(1)
    int mod = 1000000007;
    int concatenatedBinary(int n) {
        long long int val=0;
        int i=1;
        while(i<=n){
            int D = log2(i)+1;
            val = ((val<<D)%mod + i)%mod; // val<<D = val*pow(2,D)
            i++;
        }
        return val;
    }
};

