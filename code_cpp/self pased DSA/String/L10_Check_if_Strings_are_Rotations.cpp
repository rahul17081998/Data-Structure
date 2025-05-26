#include<bits/stdc++.h>
using namespace std;
// Naive solution O(n^2)
void checkRotation(string &s1,string &s2)
{
    int i=0;
    int N=s1.length();
    if(s1.length()!=s2.length()) 
        cout<<"NO";
    while(i<N)
    {
        int temp=s1[0];
        for (int i = 0; i < N-1; i++)
        {
            s1[i]=s1[i+1];
        }
        s1[N-1]=temp;
        if(s1==s2)
        {
            cout<<"YES";
            break;
        }
        i++;
    }
    if(i==N)
    {cout<<"NO";}
}
// Effective solution O(n)
bool areRotation(string &s1,string &s2)
{
    if(s1.length()!=s2.length()) return false;
    return((s1+s1).find(s2)!=string::npos);
    // return (s1+s2).find(s1)!=string::npos;
    // string::npos --> it is actually means untill end of string 
}
int main(){
    string s1="ABAAA";
    string s2="BAAAA";
    checkRotation(s1,s2);
    cout<<endl;
    cout<<areRotation(s1,s2);
    return 0;
}