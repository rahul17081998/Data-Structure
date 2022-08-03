#include<iostream>
using namespace std;

void CountingSort(int arr[], int n, int exp)
{
    int count[10]={0};
    int output[n];
    // for(int i=0; i<10; i++) 
    //     count[i]=0;
    for(int i=0; i<n; i++) 
        count[(arr[i]/exp)%10]++;
    for(int i=1; i<10; i++) 
        count[i]=count[i]+count[i-1];
    for(int i=n-1; i>=0; i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0; i<n; i++) 
        arr[i]=output[i];
}

void radixSort(int arr[],int n)
{
    // largest elements in array
    int mx=arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>mx)
        {
            mx=arr[i];
        }
        
    }
    // counting sorts for different digits 
    for (int exp = 1; mx/exp>0; exp=exp*10)
    {
        CountingSort(arr,n,exp);
    }
}

// void printArray(int arr[],int n)
// {
//     // print sorted array
//     for (int i = 0; i < n; ++i)
//     {
//         cout<<arr[i]<<" ";
//     }
// }
int main(){
    int arr[]={319,212,6,8,100,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    // printArray(arr,n);
    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}