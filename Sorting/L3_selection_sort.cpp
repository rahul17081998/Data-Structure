#include<iostream>
// #include<limits>
// #define INF (unsigned)!((int)0)
using namespace std;
/*
void selectionSort(int arr[], int n)
{
    int temp[n]; 
    for (int i = 0; i < n; i++)
    {
        int min_ind=0;
        for (int j = 1; j < n; j++)
        {
            if(arr[j]<arr[min_ind])
            {
                min_ind = j;

            }
        }
        temp[i] = arr[min_ind];
        arr[min_ind]=INT_MAX;
        
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<temp[i]<<" ";
    }
    
}
*/

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_ind=i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[min_ind])
                min_ind=j;
        }
        swap(arr[i],arr[min_ind]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {5,7,14,35,86};
    int n = sizeof(arr)/sizeof(arr[0]);
    // selectionSort(arr, n);
    selection_sort(arr, n);
    return 0;
}