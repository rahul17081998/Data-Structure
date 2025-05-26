#include<iostream>
#include<set>
using namespace std;

void ceiling(int arr[],int n)
{
    set<int> s;
    s.insert(arr[0]);
    cout<<-1<<" ";
    for (int i = 1; i < n; i++)
    {
        s.insert(arr[i]);
        auto it=s.upper_bound(arr[i]);
        if(it==s.end())
            cout<<-1<<" ";
        else
            cout<<(*it)<<" ";
    }
    
}
int main(){
    int arr[]={2,8,30,15,25,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    ceiling(arr,n);
    return 0;
}