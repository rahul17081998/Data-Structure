/*
Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of 
the only set bit. If there are 0 or more than 1 set bit the answer should be -1. Position of  
set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // TC = O(1)
    int findPosition(int N) {
        
        // Method2:
        if(N==0) return -1;
        if((N&(N-1))==0) return log2(N)+1;
        return -1;
        
        
        // Method1:
        /*
        int noOfBits = log2(N)+1; // find the no of bits into the number
        // if a number have only one set bits that will be a power of 2 number 
        // 1000-->4 bits---> 2^(bits-1)
        return pow(2,noOfBits-1)==N?noOfBits:-1;
        */
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends