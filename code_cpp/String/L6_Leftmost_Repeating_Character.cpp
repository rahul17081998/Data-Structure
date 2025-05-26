#include<bits/stdc++.h>
using namespace std;
// Naive
// Time=O(n^2)
int leftmostoc(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i+1; j < str.length(); j++)
        {
            if(str[i]==str[j])
                return i;
        }
        
    }
    return -1;
}
// Better Approch
// time=O(n+CHAR)
// Aux.sp=O(CHAR)
// Two traversal
const int CHAR=256;
int betterApproch(string &str)
{
    int count[CHAR]={0};
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if(count[str[i]]>1)
            return i;
    }

    return-1;
    
}
// Effective approch-1
// time=O(n+CHAR)
// Aux.space=O(CHAR)
// One traversal
int Effapp1(string &str)
{
    int fIndex[CHAR];
    fill(fIndex,fIndex+CHAR,-1);
    int res=INT_MAX;
    for (int i = 0; i < str.length(); i++)
    {
        int fi=fIndex[str[i]];
        if(fi==-1)
            fIndex[str[i]]=i;
        else
            res=min(res,fi);
    }
    return (res==INT_MAX)?-1:res;
    
}
int Effapp2(string &str)
{
    bool visited[CHAR];
    fill(visited,visited+CHAR,false);
    int res=-1;
    for (int i = str.length()-1; i >=0; i--)
    {
        if(visited[str[i]])
            res=i;
        else
            visited[str[i]]=true;
    }
    return res;
    
}
int main(){
    string str="abfs";
    cout<<leftmostoc(str)<<endl;
    cout<<betterApproch(str)<<endl;
    cout<<Effapp1(str)<<endl;
    cout<<Effapp2(str)<<endl;
    return 0;
}