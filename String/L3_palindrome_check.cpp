/*
I/p : str = "ABCDCBA"
O/P : YES
I/p : str = "ABBA"
O/P : YES
I/p : str = "geeks"
O/P : NO
*/
#include<bits/stdc++.h>
using namespace std;
// Naive Approch
bool palindrome(string &str)
{
    string rev=str;
    reverse(rev.begin(),rev.end());
    return(rev==str);
}
//method 2
void pld(string &str)
{
    int len=str.length();
    // cout<<len;
    int l=0;
    int h= len-1;
    bool flag=false;
    while(l<h)
    {
        if(str[l]==str[h])
        {
            flag= true;
            l++;
            h--;
        }
        else
        {
            flag =false;
            break;
        }
    }
    if(flag==true)
    {
            cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    cout<<endl;
}
int main(){
    string str="abggba";
    pld(str);
    cout<<palindrome(str);
    return 0;
}