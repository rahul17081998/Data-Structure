#include<iostream>
using namespace std;
// Recursive solution method: 1
int sol(int arr[], int s, int e, int sum)
{
    // s->start, e->end pointer
    // base case: if their are two element left in array then chose maximum of that
    if(e==s+1)
        return max(arr[s], arr[e]);
    // in other cases: if their are more than 2 elements
    // you make a choice, whatever your opponent will get maximum value 
    // you will subtract from the sum that is how you will get your value
    // and in if opponent chose from end corner you will get other max valur
    // now chose max of therse two 
    return max( sum-sol(arr, s+1, e, sum-arr[s]),
                sum-sol(arr, s, e-1, sum-arr[e]));
}


// Recursive solutin method: 2
// it does not requires sum parameter
int solve(int arr[], int s, int e)
{
    // base case
    // if their are only two element left in array, chose maximum of those
    if(s+1 == e)
        return max(arr[s],arr[e]);
    // when more than two element left

    // when you chese staring element(arr[s]) then:-
    // opponent can chose from (s+1)th or (e)th position element 
    // he will chose only one of them, but he will such that you will get minimum 
    // of rest of element:
    // if opponent chose arr[s+1] then you would have two choice wether you can chose
    // (s+2)th position element or (e)th position
    // if opponent chose arr[e] then you would have two choice wether you can chose
    // (s+1)th position element or (e-1)th position

    // similarly when you chose last element i.e. arr[e] then similar things happen:-.......

    // now you need to chose maximum of these two cases 
    return max( arr[s] + min(solve(arr, s+2, e), solve(arr, s+1, e-1)),
                arr[e] + min(solve(arr, s+1, e-1), solve(arr, s, e-2))
                );
}
// method 3
// dynamic programming solution[taken referrence from method 2]
int solve_dp(int arr[], int n)
{
    int dp[n][n];
    // base case
    for(int i=0; i<n-1; i++)
        dp[i][i+1] = max(arr[i], arr[i+1]);
    
    for(int gap=3; gap<n; gap=gap+2){
        for(int i=0; i<n-gap; i++){
            int j = i+gap;
            dp[i][j] = max( arr[i] + min(dp[i+2][j], dp[i+1][j-1]),
                            arr[j] + min(dp[i][j-2], dp[i+1][j-1]));
        }
    }
    return dp[0][n-1];
}


int main(){
    int arr[] = {20,5,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }

    cout<<"Maximum value you get(recursive method 1): "<<sol(arr, 0, n-1, sum)<<endl;
    cout<<"Maximum value you get(recursive method 2): "<<solve(arr, 0, n-1)<<endl;
    cout<<"Maximum value you get(dp method 3): "<<solve_dp(arr,n)<<endl;
    return 0;
}