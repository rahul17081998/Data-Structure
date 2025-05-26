/*
Given a non-negative number N and two values L and R. The problem is to toggle the bits in the 
range L to R in the binary representation of N, i.e, to toggle bits from the rightmost Lth bit 
to the rightmost Rth bit. A toggle operation flips a bit 0 to 1 and a bit 1 to 0. Print N after 
the bits are toggled.

 

Example 1:

Input:
N = 17 , L = 2 , R = 3
Output:
23
Explanation:
(17)10 = (10001)2.  After toggling all
the bits from 2nd to 3rd position we get
(10111)2 = (23)10
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // TC = O(log N) = O(Number of bits in N)
    int toggleBits(int N , int L , int R) {
        // code here
        int counter=0, power=0, mask=1;
        int value = 0;
        
        while(N>0){
            counter++;
            // check is the current bit is 0 or 1
            int currentBit = N&mask;
            // if you are laying in the given range then only add the value at 0 because we are toggleing
            if(counter>= L && counter<= R){
                if(currentBit==0)
                    value += pow(2,power);
            }
            // when you are not in the given range then all the value at bit values corrosponding to the position
            else{
                if(currentBit==1)
                    value += pow(2,power);
            }
            power++;
            N = N>>1; // right shift the N value
        }
        return value;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.toggleBits(N,L,R) << endl;
    }
    return 0;
}
// } Driver Code Ends