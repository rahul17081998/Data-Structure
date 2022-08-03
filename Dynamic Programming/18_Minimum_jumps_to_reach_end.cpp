#include<bits/stdc++.h>
using namespace std;
// start from end and we will consider all those ends from which we can reach the last cell
// recursive sol
int MinJump(int arr[], int n)
{
    // base case 
    if(n==1) return 0;
    int res = INT_MAX;

    for (int i = 0; i <= n-2; i++)
    {
        if(i + arr[i] >= n-1)
        {
            int sub_res = MinJump(arr, i+1);
            if(sub_res!=INT_MAX){
                res = min(res, sub_res+1);
            }
        }
    }
    return res;
    
}
// dp
int MinJump_dp(int arr[], int n)
{
    int dp[n];
    // initiallize first cell 0
    dp[0] = 0;
    // initiallize rest of cells Infinite
    for(int i=1; i<n; i++){
        dp[i] = INT_MAX;
    }
    // find how many existing paths are possible to reach directally ith cell element 
    // using 0 to i-1 cells, take minimum of those path
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            // check if path is possible to reach
            if(arr[j] + j >= i){
                if(dp[j]!=INT_MAX)
                    dp[i] = min(dp[i], dp[j]+1);
            }
        }
    }
    return dp[n-1];
}

int main(){
    int arr[] = {1, 0, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Min jumps required--> recursive: "<<MinJump(arr, n)<<endl;
    cout<<"Min jumps required--> dp: "<<MinJump_dp(arr, n);
    return 0;
}