/*
Given an integer N. The task is to return the position of first set bit found from the right 
side in the binary representation of the number.
Note: If there is no set bit in the integer N, then return 0 from the function.  

Example 1:

Input: N = 18
Output: 2
Explanation: Binary representation of 
18 is 010010,the first set bit from the 
right side is at position 2.
Example 2:

Input: N = 12 
Output: 3 
Explanation: Binary representation 
of  12 is 1100, the first set bit 
from the right side is at position 3.

*/

//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    // TC = O(logN), SC = O(1)
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int mask = 1; 
        int count=0;
        if(n==0) return 0;
        while(n>0){
            count++;
            if((mask&n)==1){
                break;
            }
            // right shift n with 1 bit, like if n=100, then after n = n>>1, n=10
            n = n>>1; 
        }
        return count; // if number(n) is zero
    }
   
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends