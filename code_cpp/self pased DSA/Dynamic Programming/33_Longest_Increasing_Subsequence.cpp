#include<bits/stdc++.h>
using namespace std;
// Longest increasing subsequence
int LIS(int arr[], int n, vector<int> &lis)
{
    int ans=1;  // it stores maximum lis value
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && lis[i]<=lis[j]){
                lis[i] = 1 + lis[j];
                ans = max(ans, lis[i]);
            }
        }
    }
    return ans;
}
int main(){
    int arr[] = {5, 8, 7, 1, 9};
    int n = sizeof(arr)/ sizeof(arr[0]);
    vector<int> lis(n, 1); // initializ the lis vector with 1
    cout<<"longest increasing subsequence length is: "<<LIS(arr, n, lis)<<endl;
    cout<<"Print Lis: \n";
    int lis_val = LIS(arr, n, lis);
    int ind;
    for(int i=n-1; i>=0; i--)
    {
        if(lis[i]==lis_val)
        {
            ind = i;
            break;
        }
    }

    cout<<"printed in decreasing order\n";
    for(int i=n-1; i>=0; i--)
    {
        if(lis[i]==ind){
            cout<<arr[i]<<" ";
            ind--;
            
        }
    }

    return 0;
}