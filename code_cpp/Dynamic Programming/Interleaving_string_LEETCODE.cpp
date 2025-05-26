class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        if(l1+l2!=l3) return false;
        // create a dp array
        bool dp[l1+1][l2+1];
        // base case
        // if both s1 and s2 is currently empty, s3 is also empty and it is considered as interleaving
        dp[0][0]=true;
        // fill first row
        // if only s1 is empty, then if previous s2 position is interleaving and current
        // s2 position character is equal to s3 current position character, then it is 
        // considered as interleaving
        for(int j=1; j<l2+1; j++){
            dp[0][j]=dp[0][j-1] && (s2[j-1]==s3[j-1]);
        }
        // fill first column
        // similar idea apply when s2 is empty
        for(int i=1; i<l1+1; i++){
            dp[i][0]=dp[i-1][0] && (s1[i-1]==s3[i-1]);
        }
        
        // when both s1 and s2 is not empty
        for(int i=1; i<l1+1; i++)
        {
            for(int j=1; j<l2+1; j++)
            {
                // if we arrive i, j from i-1, j then if i-1, j is already interleaving 
                // and i and current s3 position is equal--> it is interleaving 
                // OR 
                // if we arrive i,j from i,j-1 then if i,j-1 is already interleaving && 
                // j and current s3 position equals--> it is interleaving
                dp[i][j] = dp[i-1][j]&&(s1[i-1] == s3[i+j-1]) 
                            || dp[i][j-1]&&(s2[j-1]==s3[i+j-1]);
            }
        }
        return dp[l1][l2];
    }
};
