#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int dfs(vector<vector<int> > grid, int x, int y, int zero, int currentZero)
    {
        // check boundry cross or obstrace or visited
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==-1)
            return 0;
        // check if you found terminal and visited all zeros
        if(grid[x][y]==2)
        {
            if(zero==currentZero-1) // actuall you 
                return 1;
            else
                return 0;
        }
        // mark cell visited
        grid[x][y]=-1;
        
       // traverse in all 4 directions 
        int totalPath = dfs(grid, x, y+1, zero,currentZero+1)
                        + dfs(grid, x+1, y, zero,currentZero+1)
                        + dfs(grid, x, y-1, zero,currentZero+1)
                        + dfs(grid, x-1, y, zero,currentZero+1);
        // back tracking and mark unvisited so than others can use it
        grid[x][y]=0;
        
        return totalPath;
        
    }
    int uniquePathsIII(vector<vector<int> >& grid) {
        
        // first we need to find starting coordinate of robot and zero count;
        int x,y;
        int zero=0;
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j]==1)
                {
                    x=i;
                    y=j;
                }
                
                if(grid[i][j]==0) 
                    zero++;
            }
        }
        // now we will apply dfs
        return dfs(grid, x, y, zero, 0);
    }

    
};


int main(){
    vector<vector<int> > obstacleGrid;
    vector<int> level;
    level.push_back(1);
    level.push_back(0);
    level.push_back(0);
    level.push_back(0);
    obstacleGrid.push_back(level);
    level.clear();

    
    level.push_back(0);
    level.push_back(0);
    level.push_back(0);
    level.push_back(0);
    obstacleGrid.push_back(level);
    level.clear();

    level.push_back(0);
    level.push_back(0);
    level.push_back(2);
    level.push_back(-1);
    obstacleGrid.push_back(level);
    level.clear();

    Solution ob;
    cout<<ob.uniquePathsIII(obstacleGrid)<<endl;

    return 0;
}
/*
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
*/