/**
 * Date: 21/08/2022
 * Concept: DFS+ Memoization
 * 
 * Check if There Is a Valid Parentheses String Path:
 * 
 * A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

The path starts from the upper left cell (0, 0).
The path ends at the bottom-right cell (m - 1, n - 1).
The path only ever moves down or right. 
The resulting parentheses string formed by the path is valid.
Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.
 * 
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // /** Concept: DFS+ Memoization
    bool dfs(vector<vector<char> >& grid, int x, int y, int bal, int n, int m, vector<vector<vector<int> > > &t)
    {
        // check boundry and bal value if -ve
        // -ve value means you have ')' at starting of stack
        if(x<0 || x>=n || y<0 || y>=m || bal<0)
            return false;
        
        // memoization
        if(t[x][y][bal]!=-1)
            return t[x][y][bal];
        
        // update balance value
        // if you found '(' then add 1
        // or if you found ')' then sumbtract -1
        int updateBal;
        if( grid[x][y]=='(' )
            updateBal=bal + 1;
        else
            updateBal=bal - 1;
        
        // check if you reach at last bottom right cell and balance value should be zero there
        if(x==n-1 && y==m-1 && updateBal==0)
            return true;
        
        // do dfs in right and down direction whichever path can reach target cell return true
        bool ans = dfs(grid, x, y+1, updateBal, n, m, t)
                    || dfs(grid, x+1, y, updateBal, n, m, t);
        
        t[x][y][bal] = ans; // update in dp array
        return t[x][y][bal];
    }
    
    bool hasValidPath(vector<vector<char> >& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        // memoization dp array initialize with -1
        vector<vector<vector<int> > > t(n, vector<vector<int> >(m, vector<int>(m+n, -1)));
        
        
        bool bal=0;
        return dfs(grid, 0, 0, bal, n, m, t);
    }
    // */
    
    
};


int main(){
    // input
    vector<vector<char> > grid;

    /*
    I/P:
    grid = {{'(', '(', '('},
            {')', '(', ')'},
            {'(', '(', ')'},
            {'(', '(', ')'},};

    O/P: true
    */

    // fill the input
    vector<char> level;
    level.push_back('(');
    level.push_back('(');
    level.push_back('(');
    grid.push_back(level);
    level.clear();

    
    level.push_back(')');
    level.push_back('(');
    level.push_back(')');
    grid.push_back(level);
    level.clear();

    
    level.push_back('(');
    level.push_back('(');
    level.push_back(')');
    grid.push_back(level);
    level.clear();

    
    level.push_back('(');
    level.push_back('(');
    level.push_back(')');
    grid.push_back(level);
    level.clear();

    Solution ob;
    cout<<ob.hasValidPath(grid)<<endl;
    return 0;
}