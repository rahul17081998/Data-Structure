#include<iostream>
#include<algorithm>
using namespace std;
// kth smallest element finding program
int main(){
    int arr[]={34,2,6,53,6,221,78,2,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    int k=3;
    sort(arr,arr+n);
    // cout<<arr[k-1];
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if (i==0 or arr[i]!=arr[i-1])
        {
            count++;
            if (count==k)
            {
                cout<<arr[i];
                break;
            }
            
        }
        
    }
    
    return 0;
}