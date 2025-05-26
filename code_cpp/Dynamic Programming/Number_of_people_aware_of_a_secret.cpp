// Date: 14/aug/2022
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long NoOfPeopleSharingTheSecret=0;
        long dp[n+1];
        long mod=(long)1e9+7;
        dp[0]=0;
        // day1: only one person know the secret
        dp[1]=1;
        
        for(int i=2; i<=n; i++)
        {
            long newPeopleSharingSecret=dp[max(i-delay, 0)];
            long peopleForgetingSecret=dp[max(i-forget, 0)];
            // Adding mod to avoid overflow situation
            NoOfPeopleSharingTheSecret += (newPeopleSharingSecret - peopleForgetingSecret + mod )%mod;
            dp[i] = NoOfPeopleSharingTheSecret;
        }
        
        long ans=0;
        for(int i=n-forget+1; i<=n; i++){
            ans =(ans+ dp[i])%mod;
        }
            
        return ans;
    }
};
