#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 3:
    // Mathematically
    // return [(n+4)! / (4! * n!)]
    
    int solve2(int n){
        return (n+1)*(n+2)*(n+3)*(n+4) / 24;
    }

    // Method 2: 
    // Dp solution
    int solve(int n)
    {
         // Method2: DP
        vector<int> dp(5, 1);
        int ans=0;
        // from N=2 to N
        for(int i=2; i<=n; i++)
        {
            // start from last
            for(int j=4; j>=0; j--)
            {
                if(j==4) dp[j]; // last will remain same, you can skip this line for j=4 
                // you can start from j=3 loop by skiping above line
                else{
                    dp[j] = dp[j] + dp[j+1];
                }
            }
        }
        
        // sum all the val of dp;
        for(int val: dp){
            ans += val;
        }
        return ans;
    }

    // Method 1:
    // Backtracking Solution
    int backTracking(int n, string &currStr ,vector<char> vowel, int index)
    {
        // base case
        if(index >= vowel.size() || currStr.length()>n)
            return 0;
        if(currStr.size()==n)
        {
             return 1;
        }
        
        int count=0;
        for(int i=index; i<vowel.size(); i++)
        {
           
            if(currStr.size()>=0 && currStr.back()-'a' > vowel[i]-'a')  continue;
            currStr.push_back(vowel[i]);
            count += backTracking(n, currStr, vowel, index);
            
            currStr.pop_back();
        }
        return count;
    }
    int countVowelStrings(int n) {
        /*
        // Method1: BackTracking
        // vector<char> vowel{'a', 'e', 'i', 'o', 'u'};
        vector<char> vowel;
        vowel.push_back('a');
        vowel.push_back('e');
        vowel.push_back('i');
        vowel.push_back('o');
        vowel.push_back('u');

        string currStr="";
        // return backTracking(n, currStr, vowel, 0); // 0--> starting index
        */


        // Method 2: DP
        // return solve(n);

        // Method 3: Methematically
        return solve2(n);
    }
};


int main(){
    // input
    int n=33;
    Solution obj;
    cout<<obj.countVowelStrings(n)<<endl;

    return 0;
}