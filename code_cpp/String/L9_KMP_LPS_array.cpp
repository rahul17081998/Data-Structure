/* Constructing longest proper prefix which is equal to suffix also
   part-1
*/
#include<bits/stdc++.h>
using namespace std;
// Method -1
// O(n^3)
int longPropresuff(string str,int n)
{
    for (int len = n-1; len >0; len--)
    {
        bool flag=true;
        for (int i = 0; i < len; i++)
            if(str[i]!=str[n-len+i])
                flag = false;
        
        if(flag==true)
            return len;
    }
    return 0;
    
}
void fillLPS(string str, int lps[],int n)
{
    for (int i = 0; i < str.length(); i++)
    {
        lps[i]=longPropresuff(str,i+1);
    }
    
}
// Effective solution
// method 2
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
int main()
{
    string str="abacabad";
    // int n=str.length();
    int n=str.length();
    int lps[n];

    cout<<"\nMethod 1 output -->time complexity T(n)=O(n^3)\n";
    fillLPS(str,lps,n);
    for (int i = 0; i < n; i++)
    {
        cout<<lps[i]<<" ";
    }

    cout<<"\nMethod 2 output -->time complexity T(n)=O(n)\n";
    FillLps(str,lps);
    for (int i = 0; i < n; i++)
    {
        cout<<lps[i]<<" ";
    }
    
    return 0;
}