/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
*/


/*
2^0 = 1-1
2^1 = 2-10
2^2 = 4-100
2^3 = 8-1000
2^4 = 16-10000
2^5 = 32-100000
    we can observe from above pattern that power of two numbers have 
    only one bit as set(1) bit, it is very obviou that will be last bit.
*/
/*

// method 1
class Solution {
public:
    // TC = O(log N)
    bool isPowerOfTwo(int n) {
        int count=0;
       
        while(n>0){
            if((n&1)==1){
                count++;
            }
            n = n>>1; // right shift
        }
        // count of set bit is 1
        if(count==1) return true;
        return false;
    }
};
*/

// method2: if a number is square then its celling of log base 2 value and floor will be same

class Solution {
public:
    // TC = O(1)
    bool isPowerOfTwo(int n) {
        
        if(n==0) return false; // corner case , log can not handle 0 values 
        return floor(log2(n))==ceil(log2(n))?true:false;
    }
};


