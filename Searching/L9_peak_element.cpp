// An element is called a peak element if it is greater than its nighbour or equal
#include<iostream>
using namespace std;
// peak in a array finding 

int peakele(int arr[], int n)
{
    if(n==1)    return arr[0];
    if(arr[0] >= arr[1])    return arr[0];
    if(arr[n-1] >= arr[n-2])    return arr[n-1];
    for (int i = 1; i < n-1; i++)
    {
        if(arr[i] >= arr[i+1] and arr[i] >= arr[i-1])
            return arr[i];
    }
    return -1;
}
int main(){
    int arr[]={25,10,20,15,18,71};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<peakele(arr, n)<<endl;
    return 0;
}