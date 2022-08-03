#include<bits/stdc++.h>
using namespace std;
// Naive Pattern searching algorithm
// Time = O((n-m+1)*m)
// Aux.space = O(1)
void Pattern(string &txt, string &pat)
{
    int n=txt.length();
    int m=pat.length();
    for (int i = 0; i <= n-m; i++)
    {
        int j;
        for(j=0; j<m; j++)
        {
            if(txt[i+j]!=pat[j])
                break;
        }
        if(j==m)
        {
            cout<<i<<" ";
        }
    
    }
    
}
// Improved Naive Pattern Searching for Distinct
// for this pattern input should distinct
// Example- 
// txt="ABCABCD"
// pat="ABCD"
void PatSearch(string &txt, string &pat)
{
    int n=txt.length();
    int m=pat.length();
    for (int i = 0; i <= n-m;)
    {
        int j;
        for(j=0; j<m; j++)
        {
            if(txt[i+j]!=pat[j])
                break;
        }
        if(j==m)
            cout<<i<<" ";
        if(j==0)
            i++;
        else
            i=i+j;
    }
    
}

int main(){
    string txt="ABCABCD";
    string pat="ABCD";
    cout<<"All index numbers where pattern found:"<<endl;
    Pattern(txt,pat);
    cout<<endl;
    PatSearch(txt,pat); //for this pattern input should diatinct
    return 0;
}