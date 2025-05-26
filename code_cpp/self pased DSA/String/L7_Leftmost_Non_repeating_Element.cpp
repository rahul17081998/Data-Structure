#include<bits/stdc++.h>
using namespace std;
int nonrep(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        int flag=false;
        for (int j = 0; j < str.length(); j++)
        {
            if(i!=j and str[i]==str[j])
            {
                flag = true;
                break;
            }
                
        }
        if(flag==false)
        
    }
    return-1;
}

const int CHAR=256;
int nonRep(string &str)
{
    int count[CHAR]={0};
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if(count[str[i]]==1)
            return i;
    }
    return -1;
}

int NonRep(string &str)
{
    int fI[CHAR];
    fill(fI,fI+CHAR,-1);
    for(int i=0; i<str.length(); i++)
    {
        if(fI[str[i]]==-1)
            fI[str[i]]=i;
        else    
            fI[str[i]]=-2;
    }
    int res=INT_MAX;
    for (int i = 0; i < CHAR; i++)
    {
        if(fI[i]>=0)
            res=min(res,fI[i]);
    }
    return (res==INT_MAX)?-1:res;
}

int main()
{
    string s1="abcbca";
    cout<<nonrep(s1)<<endl;
    cout<<nonRep(s1)<<endl;
    cout<<NonRep(s1)<<endl;
    return 0;
}