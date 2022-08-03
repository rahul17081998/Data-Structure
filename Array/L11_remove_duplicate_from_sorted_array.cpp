#include<iostream>
using namespace std;

void deletedup(int arr[], int n)
{
    int x[8] ={};
    int c = 0;  // Defiend variable for new array size
    for(int i=0; i<n; i++)
    {
        if(arr[i] != arr[i-1])
        {
            x[c] =arr[i];
            c++;
        }
    }
    

    for (int i = 0; i < c; i++)
    {
        cout<<x[i]<<" ";
    }
    
}

 

int main(){
    int arr[] = {2,4,6,6,6,10,10,43};
    int n =sizeof(arr)/sizeof(arr[0]);
    deletedup(arr, n);
    return 0;
}