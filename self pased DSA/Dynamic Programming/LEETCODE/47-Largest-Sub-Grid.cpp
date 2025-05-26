#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution{
public:

    int solve(vector<vector<int> > &grid, int maxSum)
    {
        // solve here
        int n = grid.size();
        int m = grid[0].size();

        int sum[n+1][m+1];
        // prefix sum
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0||j==0){
                    sum[i][j]=0;
                    continue;
                }
                sum[i][j] = grid[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }

        int ans= 0;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(i + ans-1 > n || j + ans-1>m) break;

                int mid, lo;
                lo = ans;
                int hi = min(n-i+1, m-j+1);

                // binary search
                while(lo<hi){
                    mid = (hi + lo +1)/2; // middle index
                    if(sum[i+mid-1][j+mid-1] 
                        + sum[i-1][j-1]
                        - sum[i+mid-1][j-1]
                        - sum[i-1][j+mid-1] <= maxSum)
                    {
                        lo = mid;  
                    }
                    else{
                        hi = mid-1;
                    }

                }
                ans = max(ans,lo);
                
            }
        }
        return ans;
    }

};

int main(){

    int n, m, maxSum;
    cin>>n >> m >> maxSum; // row and columns
    vector<vector<int> > grid(n, vector<int> (m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout<<"ans is : "<<endl;
    cout<<obj.solve(grid, maxSum)<<endl;


    return 0;
}

/*
Sample input


3 7 4
1 1 3 2 4 3 2 
1 1 3 2 4 3 2
1 1 3 2 4 3 2

arr = { { 1, 1, 3, 2, 4, 3, 2 },
            { 1, 1, 3, 2, 4, 3, 2 },
            { 1, 1, 3, 2, 4, 3, 2 } };
 
    // Given target sum
    int K = 4;
Ans = 2

*/