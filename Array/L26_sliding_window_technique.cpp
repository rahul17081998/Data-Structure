#include<iostream>
using namespace std;
// Naive approch: T(c) = O(n-k)*k = n^2= Quadratic
int slide_window_1(int arr[], int n, int k)
{
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        if (i+k <= n-1)
        {
            for (int j = i; j < i+k; j++)
            {
                sum = sum +arr[j];
            }

            res = max(res, sum);
            
        }
        
    }
    return res;
}

// Effective approch: T(n) = O(n)
int slide_window_2(int arr[], int n, int k)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum +=arr[i];
    }
    
    int res = sum;
    for (int i = k; i < n; i++)
    {
        sum +=arr[i]-arr[i-k];
        res = max(res, sum);
    }
    return res;
}

int main(){
    int arr[] = {1,8,30,-5,20,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"Enter K: ";
    cin>>k;
    cout<<slide_window_2(arr, n, k);
    return 0;
}