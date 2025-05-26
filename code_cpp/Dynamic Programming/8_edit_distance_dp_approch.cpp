// Edit distance problem : recursive approch
/*
you have given 2 stringd you have to make string 1 as string 2 by doing insert, delete and replacement operation
using each operation edit distance will be considered as 1.
Note: you can only modifie string 1 you can not do anything with string 2
*/


#include<bits/stdc++.h>
using namespace std;

// minimum of three number
int minimum(int d1, int d2, int d3)
{
        int mini1 = min(d1, d2);
        int mini2 = min(d2, d3);
        return min(mini1, mini2);
}

// Dynamic programming approch to find edit distnce problem
// Time  = theta(m*n)
// Space  = theta(m*n)
int editD(string s1, string s2, int m, int n)
{
    // base cases: 
    int dp[m+1][n+1];

    // if first string is empty the 
    // only option left is that insert all characters of 2nd string 
    for(int i=0; i<=m; i++){
        dp[i][0] = i;
    }
    // if 2nd string is empty 
    // only option is that remove all characters of first string
    for(int j=0; j<=n; j++){
        dp[0][j] = j;
    }

    // filling rest of boxes
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            // if last characters are same than 
            // ignore last character and recur for the rest of string
            if(s1[m-1] == s2[n-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            // if last character do not matches than consider all possiblity and find minimum 
            // insert, remove, replace
            else{ 
                dp[i][j] = 1 + minimum(dp[i][j-1], // insert 
                                       dp[i-1][j], // remove
                                       dp[i-1][j-1]// replace
                                       );
            }
        }
    }
    return dp[m][n];
}


int main(){
    string s1,s2;
    s1 = "SATURDAY";
    int m = s1.length();
    s2 = "SANDAY";
    int n = s2.length();
    /*
    o/p: AZ matches from s1 and s2 thats why its lcs is 2
    */
    cout<< "Edit distance is: "<<editD(s1,s2,m,n)<<endl;
    return 0;
}