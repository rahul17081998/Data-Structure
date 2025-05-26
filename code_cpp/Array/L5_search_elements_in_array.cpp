// Problem: if you find an element in array then return its position otherwise return -1(not present)
#include<iostream>
using namespace std;

int search(int arr[], int x, int n)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}

int main(){
    int arr[]={4, 3,7,23,1};
    int x = 10;
    int n;
    n = sizeof(arr)/sizeof(arr[0]);  // To find size of an array
    cout<<search(arr, x, n)<<endl;
    return 0;
}