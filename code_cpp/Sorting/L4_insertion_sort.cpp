#include<iostream>
using namespace std;
// Method 2
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
            
        }
        
    }
    // Print sorted array
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
// Method 1
void insertSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j=i-1;
        while (j>=0 and arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {4,62,1,43,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr, n);
    insertSort(arr, n);
    return 0;
}