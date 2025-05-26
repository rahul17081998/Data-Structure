#include<bits/stdc++.h>
using namespace std;


int fib(int n, vector<int> &memo)
{
    if(memo[n]==-1)
    {
        int res;
        if(n==0 || n==1)
            res=n;
        else
            res=fib(n-1, memo) +fib(n-2, memo);
        memo[n] = res;
    }
    return memo[n];
}
int main(){
    int n=10;
    vector<int> memo(n+1, -1);
    // memset(memo, -1, sizeof(memo));
    cout<<fib(n, memo)<<endl;
    cout<<"print fab number :\n";
    for(int i=0; i<n+1; i++){
        cout<<memo[i]<<endl;
    }
    return 0;
}