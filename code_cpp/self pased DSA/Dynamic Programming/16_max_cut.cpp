#include<iostream>
using namespace std;

// Methhod2: dp solution
int maxCut(int n, int a, int b, int c)
{
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++)
    {
        dp[i] = -1;
        if(i-a >= 0) dp[i] = max(dp[i], dp[i-a]);
        if(i-b >= 0) dp[i] = max(dp[i], dp[i-b]);
        if(i-c >= 0) dp[i] = max(dp[i], dp[i-c]);

        if(dp[i]!=-1)
            dp[i]++;
        
    }
    return dp[n];
}

// compare three values
int maximum(int x1,int x2,int x3)
{
    return max(max(x1,x2),max(x2,x3));
}
// Method1: recursive solution
int macCut_rec(int n, int a, int b, int c)
{
    if(n<0) return -1;
    if(n==0) return 0;
    int res = maximum(macCut_rec(n-a, a, b, c),
                      macCut_rec(n-b, a, b, c),
                      macCut_rec(n-c, a, b, c));
    if(res==-1){
        return res;
    }
    else{
        return res+1;
    }
}


int main(){
    int rodlen = 23;
    int a=3, b=11, c = 13;
    cout<<"\nDP solution: Maximum cut in rod is: "<<maxCut(rodlen, a, b, c)<<endl;
    cout<<"Recursive solution: Maximum cut in rod is: "<<macCut_rec(rodlen, a, b, c)<<endl<<endl;

    return 0;
}

/*
o/p: 5      // cuts in rod are 3,3,3,3,11 ---->cut count is 5

*/