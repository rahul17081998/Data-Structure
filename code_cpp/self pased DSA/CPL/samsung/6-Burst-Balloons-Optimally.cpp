#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[100][100];

int solve(int *a, int n)
{
    for(int len = 1; len<=n; len++){
        // left will be itrate from 1 to [n-window+1]
        for(int left = 1; left <= n-len+1; left++){
            // finding right index = left + window -1
            int right = left+len-1;
            for(int k=left; k<=right; k++){
                 
                int temp = dp[left][k-1] + dp[k+1][right];
                
                
                if(left==1 && right == n) temp += a[k];
                else temp += a[left-1]*a[right+1];
                
                dp[left][right] = max(dp[left][right], temp);
            }
        }
    }
    return dp[1][n];
}


int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT   
    int n; cin>>n;
    // padding first and last value 1
    int a[n+2]; 
    a[0]=1;   a[n+1]=1;
    
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
  
    
    memset(dp, 0, sizeof(dp));
    cout<<solve(a,n)<<endl;
    
    return 0;
}
