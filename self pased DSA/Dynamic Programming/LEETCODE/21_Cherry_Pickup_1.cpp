
/*
Approach #2: 
Now, we know that we want collectively maximum cherries.
So, we have to do the traversal of both paths at the same time and select maximum global answer. 
The potential problem of this approach is double counting (if we collect same cherry in 2 paths), but this can be easily avoided in code.
If both are at the same cell we count cherry only once.
Following code is backtracking brute force so it is TLE.
Time Complexity is : 4^N*N. As we are calling cherryPickup 4 times recursively with problem size N*N.




*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    // Method 2: recursive + memoization
    // time complexity to N^4.
    int cp(int r1, int c1, int r2, int c2, vector<vector<int> > &grid, vector<vector<vector<vector<int> > > > &dp)
    {
        int n = grid.size();
       
        // since we're only going down and to the right, no need to check for < 0
        // if we went out of the grid or hit a thorn, discourage this path by returning Integer.MIN_VALUE
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
            
         // if person 1 reached the bottom right, return what's in there (could be 1 or 0)
        if(r1==grid.size()-1 && c1==grid[0].size()-1)
        {
            return grid[r1][c1];
        }
        
         // if person 2 reached the bottom right, return what's in there (could be 1 or 0)
        if(r2==grid.size()-1 && c2==grid[0].size()-1)
        {
            return grid[r2][c2];
        }
            
        if(dp[r1][c1][r2][c2]!=0)
            return dp[r1][c1][r2][c2];
        
        int cherry=0;
        // collect cerry
        // if both persons standing on the same cell, don't double count and return what's in this cell (could be 1 or 0)
        if(r1==r2 && c1==c2)
            cherry += grid[r1][c1];
        else
        // otherwise, number of cherries collected by both of them equals the sum of what's on their cells
            cherry += grid[r1][c1] + grid[r2][c2];
        
         // since each person of the 2 person can move only to the bottom or to the right, then the total number of cherries
        // equals the max of the following possibilities:
        //    P1     |      P2
        //   DOWN    |     DOWN
        //   DOWN    |     RIGHT
        //   RIGHT   |     DOWN
        //   RIGHT   |     RIGHT
        int f1=cp(r1, c1+1, r2, c2+1, grid, dp); // h, h
        int f2=cp(r1+1, c1, r2, c2+1, grid, dp); // v, h
        int f3=cp(r1+1, c1, r2+1, c2, grid, dp); // v, v
        int f4=cp(r1, c1+1, r2+1, c2, grid, dp); // h, v
        
        // cherry += max({f1, f2, f3, f4});
        cherry += max(max(f1, f2), max(f3, f4));
        dp[r1][c1][r2][c2] = cherry;
        return cherry;
    }
    
    

    // method 1
    // Backtracking solution
    // time complecity = O(2^nn) * O(2^nn) = O(4^nn)

    int maxcc=0; // maximum cherry collection
    void helper(int row, int col, vector<vector<int> > &grid, int ccsf)
    {
        // boundry check and wall
        if(row<0 || row>=grid.size() || col<0 || col >= grid[0].size() || grid[row][col]==-1)
            return;
        
        if(row==0 && col==0){
            maxcc = max(maxcc, ccsf);
            return;
        }
            
        
        int cherries = grid[row][col];
        grid[row][col] = 0; // collect charray, remove cherry 
        helper(row, col-1, grid, ccsf + cherries); // left move
        helper(row-1, col, grid, ccsf + cherries); // up move
        grid[row][col] = cherries; // back tracking
    }
    
    void cp1(int row, int col, vector<vector<int> > &grid, int ccsf)
    {
        // boundry check and wall
        if(row<0 || row>=grid.size() || col<0 || col >= grid[0].size() || grid[row][col]==-1)
            return;
        
        // check if you reach at right most bottom 
        if(row == grid.size()-1 && col == grid[0].size()-1)
            helper(row, col, grid, ccsf); // go back to home(0, 0);
        
        int cherries = grid[row][col];
        grid[row][col]=0; // collect charray, remove cherry 
        cp1(row, col+1, grid, ccsf + cherries); // right move
        cp1(row+1, col, grid, ccsf + cherries); // down move
        grid[row][col] = cherries; // back tracking
    }
    int cherryPickup(vector<vector<int> >& grid) {

        // method 2:
        int n = grid.size();
        vector<vector<vector<vector<int> > > > dp(n+1, vector<vector<vector<int> > >(n+1, vector<vector<int> >(n+1, vector<int>(n+1, 0))));
        int ans = cp(0, 0, 0, 0, grid, dp);
        return max(0, ans);



        // ccsf --> cherry collected so far
        /*
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1) 
            return max(grid[n-1][m-1], 0);
        
        cp1(0, 0, grid, 0);
        return maxcc;
        */
    }
};

int main(){
    vector<vector<int> > grid;
    // input generation
    vector<int> level;
    // Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
    // Output: 5

    level.push_back(0);
    level.push_back(1);
    level.push_back(-1);
    grid.push_back(level);
    level.clear();
    
    level.push_back(1);
    level.push_back(0);
    level.push_back(-1);
    grid.push_back(level);
    level.clear();
    
    level.push_back(1);
    level.push_back(1);
    level.push_back(1);
    grid.push_back(level);
    level.clear();
    
    Solution ob;
    cout<<ob.cherryPickup(grid)<<endl;


    return 0;
}