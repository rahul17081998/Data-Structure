#include<bits/stdc++.h>
using namespace std;
// revision
// longest prefix subarray
vector<int> lpsArray(string pat)
{
    int n = pat.size();
    vector<int> lps(n, 0);

    int len=0;
    int i=1;
    while(i<n)
    {
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len==0){
                lps[i]=0;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }
    for(int i=0; i<n; i++) cout<<lps[i]<<" ";
    cout<<endl;
    return lps;
}

int KMPpattrenSearch(string str, string pat)
{
    vector<int> lps = lpsArray(pat);
    int i=0;
    int j=0;

    while(i<str.size()){
        if(str[i]==pat[j]){
            i++;
            j++;
        }

        if(j==pat.size())
            return i-pat.size();
        else if(i<str.size() && pat[j]!=str[i]){
            if(j==0)
                i++;
            else
                j = lps[j-1];
        }
    }
    return -1;
}













void FillLps(string &str,int lps[])
{
    int n=str.length();
    int len=0;
    lps[0]=0;

    int i=1;
    while (i<n)
    {
        // check if current char is same which is at len char
        // then increase len and store lps of i = len
        if(str[i]==str[len])
        {
            len++; lps[i]=len; i++;
        }
        // if current char is not same which is at len char
        else{
            if(len==0) // if len at begining
            {
                lps[i]=0;
                i++;
            }
            else // if len is not at 0 then find the same previous char index which is currenetally at len index
            {
                len = lps[len-1];
            }
        }
    }
    for(int i=0; i<n; i++) cout<<lps[i]<<" ";
    cout<<endl;
}
// Time complexity=O(n)
// Aux space=O(m)
void KMP(string &txt,string &pat)
{
    int N=txt.length();
    int M=pat.length();
    int lps[M];
    FillLps(pat,lps);
    int i=0; // pointing string 
    int j=0; // pointing lps array
    while(i<N)
    {
        // if matrching go forword both pointer
        if(pat[j]== txt[i]) {i++;j++;}
        // termination condition
        if(j==M) {cout<<"Startin index: "<<(i-M)<<" "; j=lps[j-1]; break;}
        else if((i<N && pat[j]!=txt[i]))
        {
            if(j==0) 
                i++;
            
            else
                j=lps[j-1]; // find last index of same lps char 
        }
    }
}
int main(){
    string txt="ababcaababaad";
    string pat="ababa";
    // KMP(txt,pat);
    cout<<KMPpattrenSearch(txt,pat)<<endl;
    return 0;
}