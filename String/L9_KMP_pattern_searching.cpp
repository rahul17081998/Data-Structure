#include<bits/stdc++.h>
using namespace std;
void FillLps(string &str,int lps[])
{
    int n=str.length();
    int len=0;
    lps[0]=0;
    int i=1;
    while (i<n)
    {
        if(str[i]==str[len])
        {
            len++; lps[i]=len; i++;
        }
        else{
            if(len==0)
            {
                lps[i]=0;i++;
            }
            else
            {
                len = lps[len-1];
            }
        }
    }
    
}
// Time complexity=O(n)
// Aux space=O(m)
void KMP(string &txt,string &pat)
{
    int N=txt.length();
    int M=pat.length();
    int lps[M];
    FillLps(pat,lps);
    int i=0,j=0;
    while(i<N)
    {
        if(pat[j]== txt[i]) {i++;j++;}
        if(j==M) {cout<<(i-j)<<" "; j=lps[j-1];}
        else if((i<N && pat[j]!=txt[i]))
        {
            if(j==0) {i++;}
            else {j=lps[j-1];}
        }
    }
}
int main(){
    string txt="ababcaababaad";
    string pat="ababa";
    KMP(txt,pat);
    return 0;
}