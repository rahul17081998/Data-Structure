/*
Given an array A[ ] of N integers and an integer X. In one operation, you can change the ith element 
of the array to any integer value where 1 ≤ i ≤ N. Calculate minimum number of such operations required 
such that the bitwise AND of all the elements of the array is strictly greater than X.

Example 1:

Input:
N = 4, X = 2
A[] = {3, 1, 2, 7}
Output: 
2
Explanation: 
After performing two operations:
Modified array: {3, 3, 11, 7} 
Now, Bitwise AND of all the elements
is 3 & 3 & 11 & 7 = 3 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        // Initialize the answer to the maximum number of elements in the array
        int ans=N;

        // Initialize a bitset to store the bits that are set in X
        int bitSetinX=0;
        
        // Loop through all the bits from the 31st to the 0th
        for(int i=30; i>=0; i--){
            // If the current bit is set in X, add it to the bitset
            if(((1<<i) & X)>0){
                bitSetinX = bitSetinX | (1<<i);
            }
            else{
                // If the current bit is not set in X, try to set it in some elements of the array
                // Create a temporary number with the current bit set to 1
                int temp = bitSetinX | (1<<i);
                
                // Count the number of elements of the array that do not need to be modified to make their bitwise AND with `temp` greater than X.
                int donotModified=0;
                for(int val: A){
                    if((temp&val)==temp)
                        donotModified++;
                }

                // Update the answer to the minimum of the previous answer and the number of elements that need to be modified for the current `temp`
                ans = min(ans, N-donotModified);
            }
        }

        // Return the final answer
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}
