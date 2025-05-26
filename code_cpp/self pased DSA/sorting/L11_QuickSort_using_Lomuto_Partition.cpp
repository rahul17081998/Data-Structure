#include<iostream>
using namespace std;
int lomuto(int arr[], int low, int high)
{
    // By default h(last)is index of pivote
    int pivot=arr[high];
    int i=low-1;
    for (int j = low; j <= high; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;

}

void qSort(int arr[], int l, int h)
{
    if(l<h)
    {
        int p = lomuto(arr,l,h);;
        qSort(arr,l,p-1);
        qSort(arr,p+1,h);

    }
}

int main()
{
    int arr[]={8,4,7,9,3,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<lomuto(arr,0,n-1);
    qSort(arr,0,n-1);
    cout<<endl; 
    for(int x: arr)
    {
        cout<<x<<" ";
    }
    return 0;
}