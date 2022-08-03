#include<iostream>
using namespace std;
/*
void isSubsequence(string str1, string str2)
{
    int len1=str1.length();
    int len2=str2.length();
    int temp;
    int count=0;
    bool flag=false;
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            if(str2[i]==str1[j])
            {
                temp=count;
                count=j;
                if(count>=temp)
                {
                    flag = true;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
            
             
            
        }
        
    }
    
    cout<<flag<<endl;
}*/
// efficient temthod
// Iterative method
void sub(string str1, string str2)
{
    int len1=str1.length();
    int len2=str2.length();
    int i,j=0;
    int c=0;
    while (i<len1 and j<len2)
    {
        if(str1[i]==str2[j])
        {
            i++;
            j++;
            c++;
        }
        else
        {
            i++;
        }
    }
    if(c==len2)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    // cout<<endl<<"c="<<c<<endl;
    
}
//
bool isSub(string str1,string str2,int n,int m)
{
    int j=0;
    for (int i = 0; i<n && j<m; i++)
    {
        if(str1[i]==str2[j])
        {
            j++;
        }
    }
    return (j==m);
}
int main(){
    string str1 = "GEEKSFORGEEKS";
    string str2 = "GRGS";
    int n=str1.length();
    int m=str2.length();
    // isSubsequence(str1,str2);
    sub(str1,str2);
    cout<<isSub(str1,str2,n,m);
    return 0;
}