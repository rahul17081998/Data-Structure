class Solution {
public:
    int countHousePlacements(int n) {
        /*
        Approach: 
        One side has no effect on other side
        The no of ways on one side is fibno sequence
        both side will  return fibo*fibo
        
        placing house in one side total no of ways = a (let's say)
        placing house in 2nd side total no of ways = b (let's say)
        totla ways = a*b
        
        assume we want to place houses at one side of rode only 
        base case if 
        n=0 means 1 ways to place house --> empty place
        n=1 means 2 ways to place house --> emply, place a house one side of road
        
        */
        long mod=1000000000+7;
        long dp[n+1];
        // base case
        dp[0]=1;
        dp[1]=2;
        
        for(int i=2; i<n+1; i++){
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        
        return (dp[n]*dp[n])%mod;
    }
};
