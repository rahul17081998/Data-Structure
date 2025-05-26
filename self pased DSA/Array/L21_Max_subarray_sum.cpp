// Kadane's Algorithm

#include<iostream>
using namespace std;

int max_subarray_sum(int arr[], int n){
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr = curr+arr[j];
            res = max(res, curr);
        }
        
    }
    return res;
}

int main(){
    int arr[]={2,3,-8,7,-1,2,3};
    int n =sizeof(arr)/sizeof(arr[0]);
    cout<<max_subarray_sum(arr, n)<<endl;
    return 0;
}