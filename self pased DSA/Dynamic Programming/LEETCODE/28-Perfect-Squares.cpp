#include<bits/stdc++.h>
using namespace std;

//write your function here
/*
Algorithm:
This problem is similar to minimum coinChange problem, in which we have to form a sum value
using minimum coins , given we can use same coins as many times as we want

first we has to find the all square numbers from 1 to n
for example n=19;
all squares are 1, 4, 9, 16 --> coins
now we have to make sum =19 using above 4 coins 
i can use that coins as many times as i want 
19 = 16 + 1 + 1 +1 --> 4 coins required[this not our optimal answer]
19 = 9 + 9 + 1 --> 3 coins required[correct answer]

*/
class Solution {
public:
    int minCoinChange(vector<int> &coins, int sum)
    {

        vector<int> dp(sum+1, INT_MAX);
        dp[0]=0; //for sum = 0 we need 0 coins
        
        for(int i=1; i<sum+1; i++)
        {
            for(auto coin: coins){
                if(coin <= i && dp[i-coin]!=INT_MAX)
                    dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        
        if(dp[sum]==INT_MAX)
            return -1;
        return dp[sum];
    }
    // Generate all perfect square number  from 1 to n
    vector<int> perfectSquare(int n)
    {
        vector<int> square;
        for(int i=1; i*i<=n; i++){
            // cout<<i*i<<" ";
            square.push_back(i*i);
        }
        return square;
    }
    // main function
    int numSquares(int n) {
        // first we has to find the all square numbers from 1 to n
        vector<int> square = perfectSquare(n);
        // now we have to make sum(n) using above coins(square) 
        return minCoinChange(square, n);
        // return 0;
    }
};

int main(){
    // input
    // Input: n = 13
    // Output: 2
    // Explanation: 13 = 4 + 9.
    int n=13;
    Solution ob;
    cout<<ob.numSquares(n)<<endl;
    return 0;
}