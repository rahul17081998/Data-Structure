// Implementing heap sort  
// using heap data structure and selection sort logic
#include<bits/stdc++.h>
using namespace std;
// max Heapify(root will be max)
void maxHeapify(int arr[],int n,int i)
{
    int largest,left,right;
    largest=i;
    left=2*i+1;
    right=2*i+2;
    if(left<n && arr[left]>arr[largest])
        largest=left;
    if(right<n && arr[right]>arr[largest])
        largest=right;
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        maxHeapify(arr,n,largest);
    }
}
// build heap
void buildHeap(int arr[],int n)
{
    for (int i = (n-2)/2; i >= 0; i--)
    {
        maxHeapify(arr,n,i);
    }
    
}
// heap sort 
void heapSort(int arr[],int n)
{
    buildHeap(arr,n);
    for (int i = n-1; i >= 1; i--)
    {
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0);
    }
    
}
// print array
void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 
int main(){
    int arr[]={10,3,54,7,23,4,21};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapSort(arr,n);
    printArray(arr,n);
    
    
    return 0;
}