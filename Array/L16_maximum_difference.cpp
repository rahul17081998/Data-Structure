#include<iostream>
using namespace std;

// Naive method
void maxdiff(int arr[], int n)
{
    int temp = arr[1]-arr[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]-arr[i]>temp)
            {
                temp=arr[j]-arr[i];
            }
            
        }
        
    }
 cout<<temp<<endl;   
}

int main(){
    int arr[]={30,10,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    maxdiff(arr, n);
    return 0;
}