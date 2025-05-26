// 4-cherry-pickup
class Solution {
public:
    const int inf=(int)(-1e7);
    int solve(vector<vector<int> >&grid,int i1,int j1,int i2,vector<vector<vector<
              int> > >&dp,int n)
    {
        int j2=i1+j1-i2;
        if(i1==n || i2==n || j1==n || j2==n || grid[i1][j1]==-1 ||grid[i2][j2]==-1)
            return inf;
        if(i1==n-1 && j1==n-1 && i2==n-1 && j2==n-1)
            return grid[i1][j1];
        if(dp[i1][j1][i2]!=-1)
            return dp[i1][j1][i2];
        int cnt=0;
        if(i1==i2 && j1==j2)
            cnt+=grid[i1][j1];
        else
            cnt+=grid[i1][j1]+grid[i2][j2];
        int opt1=solve(grid,i1+1,j1,i2+1,dp,n);// hh
        int opt2=solve(grid,i1+1,j1,i2,dp,n);// hv
        int opt3=solve(grid,i1,j1+1,i2+1,dp,n);// vh
        int opt4=solve(grid,i1,j1+1,i2,dp,n);// vv
        return dp[i1][j1][i2]=cnt+max(opt1,max(opt2,max(opt3,opt4)));
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int i1=0,j1=0,i2=0,j2=0;
        vector<vector<vector<int> > >dp(n,vector<vector<int> >(n,vector<int>(n,-1)));
        int p= solve(grid,i1,j1,i2,dp,n);
        if(p<0)
            return 0;
        else
            return p;
    }
};