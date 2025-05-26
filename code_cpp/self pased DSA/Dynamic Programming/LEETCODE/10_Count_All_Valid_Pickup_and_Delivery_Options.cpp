/**
 * Date: 22/08/2022
 * Count All Valid Pickup and Delivery Options
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOrders(int n) {
        
        int mod = 1000000007;
        // base case for 
        // N=1 --> only one combination 

        // N=2 -->  od no =2*2-1=3, only combination 1 * (3*4/2)=6
        // Odd no: 2*i-1
        // F[n] = F[n-1] * [ON*(ON+1)/2]


        // EXAMPLE n=3
        /*
        odd no = 2*3-1=5
        F[n] = F[n-1] * [ON*(ON+1)/2]
        F[3] = F[2] * (5*6/2) = F[2] * 15 = 6*15 = 90
        
        */
        long dp[n+1];
        dp[1]=1;
        for(int i=2; i<=n; i++)
        {
            int ON = 2*i-1;
            int permutation = ON*(ON+1)/2;
            dp[i] = (dp[i-1]*permutation)%mod;
        }
        
        return (int)dp[n];
    }
};

int main(){
    // input
    int n = 3;
    Solution ob;
    cout<<ob.countOrders(n)<<endl;
    return 0;
}