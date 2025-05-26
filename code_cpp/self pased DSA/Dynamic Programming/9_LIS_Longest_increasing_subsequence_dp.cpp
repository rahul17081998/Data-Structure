// longest increasing subsequence
// Approch: dynamic programming
// Time = theta(N^2), Space = theta(N)
#include<bits/stdc++.h>
using namespace std;

/*
int LIS(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for(int i=1; i<n; i++){
        lis[i] = 1;
        // cheak if it's left side have smaller value
        // if yes, than "maximum of lis vlue + 1" will be current ith lis value
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }
    // return maximum of lis array
    int res=lis[0];
    for(int i=0; i<n; i++){
        res = max(res, lis[i]);
    }
    return res;
}
*/

int LIS(int arr[], int n)
{
    cout<<n<<endl;
    vector<int> lis(n, 1); // initially 1
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }
    for(int i=0; i<n; i++) cout<<lis[i]<<" ";
    cout<<endl;
}


int main(){
    int arr[] = {3, 4, 2, 8, 10};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Longest common subsequence length: "<<LIS(arr, n)<<endl;
    return 0;



}