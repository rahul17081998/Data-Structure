#include<iostream>
using namespace std;

void left_rotate(int arr[], int n)
{
    int x[n];
    for (int i = 0; i < n-1; i++)
    {
        x[i]=arr[i+1];
    }
    x[n-1]=arr[0];
    

       // new array
    for (int i = 0; i < n; i++)
    {
        cout<<x[i]<<" ";
    }
}

int main(){
    int arr[]={2,3,243,5,5,0};
    int n =sizeof(arr)/sizeof(arr[0]);
    // movetoend(arr, n);
    left_rotate(arr, n);

    
    return 0;
}