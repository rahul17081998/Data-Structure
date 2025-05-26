#include<bits/stdc++.h>
using namespace std;
void Reverse(string s1)
{
    vector<string> temp;
    string str="";
    for (int i = 0; i < s1.length(); i++)
    {
        if(s1[i]==' ')
        {
            temp.push_back(str);
            str="";
        }
        else
        {
            str=str+s1[i];
        }
    }
    temp.push_back(str);
    for (int i = temp.size()-1; i >=0; i--)
    {
        cout<<temp[i]<<" ";
    }
    // cout<<temp[0]<<endl;
    
    
}
// Effective Method 
void reverse(char str[],int low,int high)
{
    while (low<=high)
    {
        swap(str[low],str[high]);
        low++;
        high--;
    }
    
}
void reverseword(char str[],int n)
{
    int start=0;
    for(int end=0; end<n; end++)
    {
        if(str[end]==' ')
        {
            reverse(str,start,end-1);
            start=end+1;
        }
    }
    reverse(str,start,n-1);
    reverse(str,0,n-1);
}

int main(){
    string s1="i love the cofee";
    int n=s1.length();
    char str[n];
    strcpy(str,s1.c_str());
    cout<<"After reversing word\n";
    Reverse(s1);
    cout<<endl;
    reverseword(str,n);
    for (int i = 0; i < n; i++)
    {
        cout<<str[i];
    }
    
    return 0;
}