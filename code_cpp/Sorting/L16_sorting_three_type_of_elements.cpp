#include<iostream>
using namespace std;
/*
void func(int arr[], int n){
    int temp[n];
    int c=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0)
        {
            temp[c]=arr[i];
            c++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==1)
        {
            temp[c]=arr[i];
            c++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==2)
        {
            temp[c]=arr[i];
            c++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=temp[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}
*/

// Effective soln 
void Sorts(int arr[], int n)
{
    int lo=0,hi=n-1,mid=0;
    while(mid<=hi)
    {
        if(arr[mid]==0)
        {
            swap(arr[lo],arr[mid]);
            lo++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[hi]);
            hi--;
        }
        
    }
    // print
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={0,1,2,2,1,2,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    // func(arr,n);
    Sorts(arr,n);
    return 0;
}