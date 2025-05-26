#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>temp={-1,2,3};
    int n=temp.size();
    vector<int>left(n);
    vector<int>right(n);

    left[0]=temp[0];
    for(int i=1;i<n;i++)
    {
        left[i]=left[i-1]+temp[i];
        
    }
    right[n-1]=temp[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i]=right[i+1]+temp[i];
        
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<max(right[i],left[i])<<" ";
    }
    cout<<endl;

}