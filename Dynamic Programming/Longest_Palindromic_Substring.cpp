class Solution {
public:
    string longestPalindrome(string s) {
        
        // Method 2; apply dynamic programming
        int n=s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        // initialize with base case
        // single letters are always palindromes
        for(int i=0; i<n; i++)
            dp[i][i]=1;
        
        int start=0;
        int end=1;
        
        // check two consecutive letter are palindrome
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                start=i;
                end=2;
            }
                
        }
            
        // for more than 2 length string
        for(int j=2; j<n; j++)
        {
            for(int i=0; i<n-j; i++)
            {
                int left=i; // starting point
                int right=i+j; // endong point
                // check if first and last position are same and inside 
                // is palindrome --> means this string is also a palindrome
                if(dp[left+1][right-1]==1 && s[left]==s[right]){
                    dp[left][right]=1;
                    start=i, end=j+1;
                }
            }
        }
        return s.substr(start, end);
        /*
        // Method 1: time = O(N^2), space=O(1)
        // iterative version
        int n=s.length();
        string ans="";
        ans[0]=s[0];
        
        for(int i=0; i<n; i++){
            string temp1="", temp2="";
            for(int j=i; j<n; j++){
                temp1 = temp1 + s[j];
                temp2 = s[j]+temp2;
                if(temp1==temp2 && temp1.length() > ans.length())
                    ans = temp1;
            }
        }
        return ans;
        */
    }
};
