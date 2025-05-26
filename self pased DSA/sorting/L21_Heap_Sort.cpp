#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i)
{
    int largest=i,left=2*i+1,right=2*i+2;
    if(left<n && arr[left]>arr[largest]) 
        largest=left;
    if(right<n && arr[right]>arr[largest]) 
        largest=right;
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void BuildHeap(int arr[],int n)
{
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(arr,n,i);
    }
}
void heapSort(int arr[],int n)
{
    BuildHeap(arr,n);
    for(int i=n-1; i>=1; i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
    
}
void printArray(int arr[],int n)
{
    // print sorted array
    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={12, 11, 13, 5, 6, 7};  
    int n= sizeof(arr)/sizeof(arr[0]);
    heapSort(arr,n);
    printArray(arr,n);
    
    return 0;
}