// Longest common subsequence length in two strings
#include<bits/stdc++.h>
using namespace std;
// recursive approch
int lcs(string s1, string s2, int m, int n)
{
    if(m==0 || n==0)    // base case
        return 0;
    if(s1[m-1] == s2[n-1]) // if last character of both string matches
        return 1+lcs(s1, s2, m-1, n-1);
    else // if last character not matches
        return max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
}
int main(){
    string s1,s2;
    s1 = "ABCDGH";
    int m = s1.length();
    s2 = "ACDGHR";
    int n = s2.length();
    /*
    o/p: AZ matches from s1 and s2 thats why its lcs is 2
    */
    cout<< "Least common Subsequence: "<<lcs(s1,s2,m,n)<<endl;
    return 0;
}