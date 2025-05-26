#include<iostream>
using namespace std;

void stock_market(int arr, int n)
{
    int sum = 0;
    int temp= arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i]<arr[i-1])
        {
            sum = sum+arr[i-1]-temp;
            temp = arr[i];
        }
        
    }
    cout<<sum;

}

int main(){
    int arr[]={1,5,3,1,2,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    stock_market(arr,n);
    return 0;
}