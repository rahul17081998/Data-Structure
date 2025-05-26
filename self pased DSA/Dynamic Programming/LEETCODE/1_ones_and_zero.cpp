#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    
    // Helper function to count zero's and one's in a string
    vector<int> frequencyCount(string str)
    {
        vector<int> freq(2, 0);
        // freq[0] ---> zero count store
        // freq[1] ---> one's count store
        for(char c: str)
        {
            if(c =='0')
                freq[0]++;
            else
                freq[1]++;
        }
        return freq;
    }
    
    // logic fun
    /*
    Method 1: TLE
    int helper(vector<vector<int>> frequency, int m, int n, int index, int strlen, vector<vector<vector<int>>> &dp)
    {
        if(index >= strlen || (m+n) <= 0)
            return 0;
        
        if(dp[m][n][index] > 0)
            return dp[m][n][index];
        
        int countElIfCurrInc=0;
        int countElIfCurrExc=0;
        
        int zeroFreq=frequency[index][0];
        int oneFreq=frequency[index][1];
        
        if(m>=zeroFreq && n>=oneFreq)
        {
            countElIfCurrInc =1+ helper(frequency, m-zeroFreq, n-oneFreq, index+1, strlen, dp);
        }
        countElIfCurrExc = helper(frequency, m, n, index+1, strlen, dp);
        
        dp[m][n][index]=max(countElIfCurrInc, countElIfCurrExc);
        return dp[m][n][index];
    }*/

    // Method 2:
    int solve(vector<string>& strs, int m, int n, vector<vector<int> > frequency)
    {
        // Method 2: working fine
        vector<vector<int> > t(m+1, vector<int>(n+1, 0));
        // int t[m+1][n+1];
        for(int i=0; i<strs.size(); i++)
        {
            int zeroFreq=frequency[i][0];
            int oneFreq=frequency[i][1];
            
            for(int k=m; k>=0; k--)
            {    
                for(int j=n; j>=0; j--)
                {
                    if(k>=zeroFreq && j>=oneFreq)
                        t[k][j] = max(t[k][j],// not sonsedring current element
                                      t[k-zeroFreq][j-oneFreq] + 1); // considering the current element
                }
            }
        }
        
        
        return t[m][n];
        
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        // create a 2d array which will store the count of zero and one for 
        // each element of strs
        
        
        int size = strs.size();
        // vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(size, 0)));
             
        
        vector<vector<int> > frequency(size, vector<int>(2, 0));
        
        int i=0;
        for(string str: strs)
        {
            frequency[i]=frequencyCount(str);
            i++;
        }

        return solve(strs, m, n, frequency);
        
        // // Method 2: working fine
        // vector<vector<int>> t(m+1, vector<int>(n+1, 0));
        // // int t[m+1][n+1];
        // for(int i=0; i<strs.size(); i++)
        // {
        //     int zeroFreq=frequency[i][0];
        //     int oneFreq=frequency[i][1];
            
        //     for(int k=m; k>=0; k--)
        //     {    
        //         for(int j=n; j>=0; j--)
        //         {
        //             if(k>=zeroFreq && j>=oneFreq)
        //                 t[k][j] = max(t[k][j],// not sonsedring current element
        //                               t[k-zeroFreq][j-oneFreq] + 1); // considering the current element
        //         }
        //     }
        // }
        
        
        // return t[m][n];
        
        
        
        // return helper(frequency, m, n, 0, size, dp);
        
    }
};


int main(){
    
    // input
    int m=5; // no of zeros
    int n=3; // no of ones
    vector<string> strs;
    strs.push_back("10");
    strs.push_back("0001");
    strs.push_back("111001");
    strs.push_back("1");
    strs.push_back("0");

    Solution ob;
    cout<<ob.findMaxForm(strs, m, n)<<endl;
    return 0;
}