/*
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit i
nteger range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

#include<bits/stdc++.h>
using namespace std;

//write your function here

int reverse(int x) 
{
    long long revNo=0;
    while(x)
    {
        int val = x%10;
        x = x/10;
        revNo = revNo*10 + val;
    }
    return (revNo<INT_MIN || revNo>INT_MAX) ? 0 : revNo; // write it to overcome with overflow
}
// main
int main(){
    int n=-132;
    cout<<reverse(n)<<endl;
    return 0;
}
/**
 * Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
*/