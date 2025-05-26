#include<bits/stdc++.h>
using namespace std;
// Longest increasing subsequence using binary search
int LIS(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len=1;
    for(int i=1; i<n; i++)
    {
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            auto ind = lower_bound(temp.begin(), temp.end(), arr[i]);
            temp[*ind] = arr[i];
        }
    }
    return len;
}
int main(){
    int arr[] = {5, 8, 7, 1, 9};
    int n = sizeof(arr)/ sizeof(arr[0]);
    
    cout<<"longest increasing subsequence length is: "<<LIS(arr, n)<<endl;
    
    return 0;
}