#include<bits/stdc++.h>
using namespace std;
// How many subsets sum have given sum value 
// count them
/*
int countSubsetSum(int arr[], int n, int sum)
{
    int t[n+1][sum+1];

    // base case
    t[0][0] = 1;
    for(int i=1; i<n+1; i++)  t[i][0] = 1;
    for(int j = 1; j<sum+1; j++)  t[0][j] = 0;
    
    // main formula
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<sum+1; j++)
        {
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}
int countSubsetDiff(int arr[], int n, int diff)
{
    // find sum of array
    int sum_arr = 0;
    for(int i=0; i<n; i++){
        sum_arr += arr[i];
    } 

    int s1 = (diff + sum_arr)/2;
    return countSubsetSum(arr, n, s1);

}
*/

// int subsetSum(int a[], int n, int sum)
// {
//     // Initializing the matrix
//     int dp[n + 1][sum + 1];
//   // Initializing the first value of matrix
//     dp[0][0] = 1;
//     for (int i = 1; i <= sum; i++)
//         dp[0][i] = 0;
//     // for (int i = 1; i <= n; i++)
//     //     dp[i][0] = 1;
 
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= sum; j++)
//         {
//           // if the value is greater than the sum
//             if (a[i - 1] <= j)
//                 dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]]; 
//             else
//                 dp[i][j] = dp[i - 1][j];
//         }
//     }

//     return dp[n][sum];
// }

int countWithGivenDiff(vector<int> nums, int target)
{   
    int sum = 0;
    for(int x : nums)
        sum += x;
    
    if(((sum + target) % 2 == 1) || (target > sum))
        return 0;
    
    int n = nums.size();
    int s2 = (sum + target)/2;
    int t[n + 1][s2 + 1];
    t[0][0] = 1;
    for (int j = 1; j < s2+1; j++)
    {
        /* code */
        t[0][j] = 0;
    }
    
    
    for(int i = 1; i < n + 1; i++){
        for(int j = 0; j < s2 + 1; j++){
            if(nums[i - 1] <= j)
                t[i][j] = t[i-1][j] + t[i - 1][j - nums[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    
    
    return t[n][s2];    
}


int main(){
    // int arr[] = {1, 6, 5, 11};
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(30);
    arr.push_back(11);
    arr.push_back(1);
    
    int diff = 18;
    // cout<<countSubsetDiff(arr, n, diff);
    // cout<"Number of subsets with given difference is "<<countSubsetDiff(arr, n, diff)<<endl;
    cout<<countWithGivenDiff(arr, diff);
    return 0;
}