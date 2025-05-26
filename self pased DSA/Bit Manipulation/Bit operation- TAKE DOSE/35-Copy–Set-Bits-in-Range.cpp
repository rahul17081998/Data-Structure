/*Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. Find the set bits of y in range [l, r] and set these bits in x also.

Example 1:

Input: 
X = 44, Y = 3 
L = 1,  R = 5
Output: 47
Explaination: presenation of 44 and 3 are 
101100 and 11. So in the range 1 to 5 there 
are two set bits. If those are set in 44 
it will become 101111 = 47.
*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    // TC  = O(r-l), SC = O(1)
    int setSetBit(int x, int y, int l, int r){
        // code here
        for(int i=l; i<=r; i++){
            int mask = 1<<(i-1); // only set the ith bit
            // check if ith bit is set into y then add the mask value to x
            if(mask&y){
                x = x | mask;
            }
        }
        return x;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends