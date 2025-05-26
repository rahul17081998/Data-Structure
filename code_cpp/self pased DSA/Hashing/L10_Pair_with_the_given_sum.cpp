#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
// time = O(n)
// aux.sp=O(n)
bool isPair(int arr[],int n,int sum)
{
    unordered_set<int> h;
    int x;
    for (int i = 0; i < n; i++)
    {
        x=sum-arr[i];
        // search x in hash table h 
        // we can use count() function also 
        // we can also use if(h.count(x)>0) to search 
        if(h.find(x)!=h.end())
            return true;
        else
            h.insert(arr[i]);
    }
    return false;
}
int main(){
    int arr[]={3,2,8,15,-8};
    int sum=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<isPair(arr,n,sum)<<endl;
    return 0;
}