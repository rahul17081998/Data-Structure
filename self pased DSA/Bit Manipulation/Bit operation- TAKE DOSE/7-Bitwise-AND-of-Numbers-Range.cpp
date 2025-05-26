/*Given two integers left and right that represent the range [left, right], 
return the bitwise AND of all numbers in this range, inclusive.

 

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
*/

#include<bits/stdc++.h>
using namespace std;

//write your function here

// TC = O(logN)
// SC = O(1)
int rangeBitwiseAnd(int left, int right) 
{
    int count=0; // keep count of right shift
    while(left!=right)
    {
        left >>=1; // right shift[removing from lsb]
        right>>=1; // right shift
        count++;
    }
    return left<<=count; // left shift -->adding zeros
}


int main(){
  
    cout<<rangeBitwiseAnd(5, 7)<<endl;
    return 0;
}