#include<bits/stdc++.h>
using namespace std;

// correct code
int CountWay(string str){
    // Code here
    int n = str.size();
    const int mod = 1e9 + 7;
    // check if first char is 0
    if(str[0]=='0')
        return 0;
    // check if string contain two consecutive zero.  i.e "00"
    for(int i=0; i<n-1; i++){
        if(str[i] =='0' && str[i+1] =='0')
            return 0;
    }
    
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for(int i=0; i<n; i++)
    {
        if(str[i] =='0')// check if first char is 0
            continue;
        dp[i+1] = (dp[i+1] + dp[i])%mod;
        // If second last digit is smaller than 2 and 
        // last digit is smaller than 7, then last two digits 
        // form a valid character
        if(i!= n-1 && str[i] =='1' || (str[i]=='2' && str[i+1] <'7'))
            dp[i+2] = (dp[i+2] + dp[i])%mod;
            
        
    }
    
    return dp[n];
}



//////////////////





// PepCoding video solution
// this code is not giving correct output word for all test case
// Total Decoding Messages 
/*
int CountWays(string str){
    // Code here
    // initialize the dp array
    // 𝚽 --> it represent non zero integer as char
    // 0  --> it represent zero integer as char
    int dp[str.length()];
    dp[0]=1;    // 1 ways for first char of string
    if(str[0]=='0') return 0;
    // start traveversing string from 2nd char
    for(int i=1; i<str.length(); i++)
    {
        // if last 2 char is "00"
        if(str[i-1]=='0' && str[i]=='0')
            dp[i] = 0;
        // if last 2 char is "0𝚽"
        if(str[i-1]=='0' && str[i]!='0')
            dp[i] = dp[i-1];
        // if last 2 char is "𝚽0"
        if(str[i-1]!='0' && str[i]=='0')
        {   // if second last char is 1 or 2 then ok
            // if it greater than 2 than it can make like 30, 40, 50, ... string which we can not
            // decode combined 2 char
            if(str[i-1]=='1' || str[i-1]=='2')
                dp[i] = (i>=2 ? dp[i-2]:1);  // if(i>1) is false means string have only 2 char or less than 2
            else{
                dp[i] = 0;
                return dp[i];
            }
        }
        // if last 2 char is "𝚽𝚽"
        else
        {   // if integer value of last char is less than or equal to 26 
            if(stoi(str.substr(i-1, 2)) <= 26)
                dp[i] = dp[i-1] + (i >= 2 ? dp[i-2]:1); //if(i>1) is false means string have only 2 char or less than 2
            else // if integer value of last char > 26 
                dp[i] = dp[i-1];
        }
        
    }
    return dp[str.length()-1];
    
}
*/


// main function
int main(){
    string str = "32142";
    cout<<CountWay(str)<<endl;// correct code
    // cout<<CountWays(str)<<endl;
    return 0;
}