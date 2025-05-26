/*
Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

 

Example 1:

Input: num = 14
Output: 6
Explanation: 
Step 1) 14 is even; divide by 2 and obtain 7. 
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3. 
Step 4) 3 is odd; subtract 1 and obtain 2. 
Step 5) 2 is even; divide by 2 and obtain 1. 
Step 6) 1 is odd; subtract 1 and obtain 0.
*/

class Solution {
public:
    // other method TC = O(1)
    int numberOfSteps(int num) {
    //    if num is 0 then return 0 else length of num*8 + (num of 1's)-(no of leading 0's)-1
    return num==0? 0: sizeof(num)*8 + __builtin_popcount(num)- __builtin_clz(num)-1;
    }


    /*
    // TC = O(logN)
    int numberOfSteps(int num) {
        int count=0;
        while(num){
            if(num%2==1) 
                num--;
            else 
                num = num/2;
            count++;
        }
        return count;
    }*/

};