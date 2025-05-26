#include<iostream>
using namespace std;
/*
// Naive approch 
void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
            
        }

    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
*/


/*
// Optimized code 
void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
            
        }

    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
*/

// optimised code When an array is already sorted
void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {   bool swaped = false;
        for(int j=0; j<n-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swaped=true;
            }
            
        }
        if (swaped==true)
        {
            break;
        }
        

    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main(){
    int arr[] = {5,7,14,35,86};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    return 0;
}