#include<bits/stdc++.h>
using namespace std;

// Recursive method for 0-1 knapsack problem
int knapSack(int W, int wt[], int val[], int n)
{
    //base case
    if(n==0 || W==0) return 0;


    // ignore an item if weight of an item is exceding with capacity of knapSack
    if(wt[n-1] > W){
        return knapSack(W, wt, val, n-1);
    }
    // Either take an item or not take an item 
    else{
        return max(knapSack(W, wt, val, n-1), val[n-1]+knapSack(W-wt[n-1], wt, val, n-1));

    }
}
// dynamic programming method for 0-1 knapsack problem
int knapSack_dp(int W, int wt[], int val[], int n)
{
    //base case
    int dp[n+1][W+1];
    // base cases:
    // if you have 0 item you will always get 0 value irrespective of whatever your knapsack have capacity
    for(int i=0; i<=W; i++) {dp[0][i] = 0;}
    // similarly if you have 0 knapsack capacity you will always get 0 value irrespective of whatever you have items
    for(int i=0; i<=n; i++) {dp[i][0] = 0;}

    // to fill rest of boxes
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(wt[i-1] > j)
            // ignore an item if weight of an item is exceding with capacity of knapSack
                dp[i][j] = dp[i-1][j];
            else
            // Either take an item or not take an item 
                dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);
        }
    }
    return dp[n][W];
}
int main(){
    int v[] = {10, 40, 30, 50};
    int w[] = {5, 4, 6, 3};
    int weight = 10;
    int n = sizeof(v)/sizeof(v[0]);
    cout<<"maximum values collected in knapsack: "<<knapSack(weight, w, v, n)<<endl;
    cout<<"maximum values collected in knapsack: "<<knapSack_dp(weight, w, v, n);
    return 0;
}