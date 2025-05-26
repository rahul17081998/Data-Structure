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
int main(){
    int arr[]={10,80,30,90,40,50,70};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<lomuto(arr,0,n-1);
    cout<<endl; 
    for(int x: arr)
    {
        cout<<x<<" ";
    }
    return 0;
}