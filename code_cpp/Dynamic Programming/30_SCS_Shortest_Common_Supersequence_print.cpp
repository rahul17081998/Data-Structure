/*
// shortest common supersequence

Given two strings str1 and str2, return the shortest string 
that has both str1 and str2 as subsequences. 
If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting 
some number of characters from t (possibly 0) results in the string s
*/
#include<iostream>
using namespace std;


string shortestCommonSupersequence(string str1, string str2) 
{
    
    int n = str1.length();
    int m = str2.length();


    // part1 --->LCS table creation
    // first create lcs table
    int t[n+1][m+1];
    
    // initialize t matrix
    // with base case of lcs
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i==0 || j==0)
                    t[i][j] = 0;
        }
    }
    // main code of lcs
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            // if last char matches
            if(str1[i-1] == str2[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    //**********//
    
    // part2 --->shortest super sequence
    int i = n;
    int j = m;
    string s = "";

    // traverse into t[n+1][m+1] matrix
    // from last column t[n][m].
    while(i>0 && j>0)
    {
        if(str1[i-1] == str2[j-1])
        {
            s.push_back(str1[i-1]);
            i--;
            j--;
        }
        else
        {   // we will print all the character while we are traversing
            if(t[i][j-1] > t[i-1][j]){
                s.push_back(str2[j-1]);
                j--;
            }
            else{
                s.push_back(str1[i-1]);
                i--;
            }
            
        }
    }
    // if i is not zero
    while(i>0)
    {
        s.push_back(str1[i-1]);
        i--;
    }
    // if j is not zero
    while(j>0)
    {
        s.push_back(str2[j-1]);
        j--;
    }
    reverse(s.begin(), s.end()); // reverse the string
    return s;   // ans
    
}



int main(){
    string str1 = "abac";
    string str2 = "cab";

    cout<<"Shortest Common Supersequence: "<<shortestCommonSupersequence(str1, str2)<<endl;

    return 0;
}

/*
output: "cabac"
*/