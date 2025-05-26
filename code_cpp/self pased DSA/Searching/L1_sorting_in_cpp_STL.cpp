#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[]={10,20,4,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    // sorting in assending order
    sort(arr,arr+n);
    for(int x : arr)
    {
        cout<<x<<" ";
    }
    // sorting in decending order
    sort(arr, arr+n, greater<int>()); // greatest integer first
    cout<<endl;
    for(int x: arr)
        cout<<x<<" ";
    return 0;
}