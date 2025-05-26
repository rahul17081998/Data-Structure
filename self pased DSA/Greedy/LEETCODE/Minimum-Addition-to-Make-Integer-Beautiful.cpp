/*You are given two positive integers n and target.

An integer is considered beautiful if the sum of its digits is less than or equal to target.

Return the minimum non-negative integer x such that n + x is beautiful. The input will be generated such that it is always possible to make n beautiful.

Example 1:

Input: n = 16, target = 6
Output: 4
Explanation: Initially n is 16 and its digit sum is 1 + 6 = 7. After adding 4, n becomes 20 and digit sum becomes 2 + 0 = 2. It can be shown that we can not make n beautiful with adding non-negative integer less than 4.*/

class Solution {
public:
    int digitSum(long long n){
        int sum=0;
        while(n){
            sum += n%10;
            n = n/10;
        }
        return sum;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long temp = n; 
        long long int base=1; 
        while(digitSum(n)>target){
            n = n/10+1;
            base *=10;
        }

        return n*base-temp;
    }
};

