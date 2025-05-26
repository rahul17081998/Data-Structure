class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        // this vector stores number of obstracle than can still remove
        vector<vector<int>> vis(n, vector<int>(m,-1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            
            int x=t[0], y=t[1];
            // check boundry 
            if(x<0 || x>=n || y<0 || y>=m)
                continue;
            
            // check if you reach at end, great , return the length
            if(x==n-1 && y==m-1)
                return t[2];
            
            //check if we hit the obstracle and we don't have remaining k, continue
            // if we still have k's to spend , spend 1
            if(grid[x][y]==1)
            {
                if(t[3]>0)
                    t[3]--;
                else
                    continue;
            }
            
            // if this cell is already visite with a k value lesser than this one we would 
            // want to save k's for future use, so will continue
            // v[x][y] tells how many obstacles we can still remove. So, if v[x][y]>=t[3], it means some other path can remove more obstacles when it visited this cell as compare to the current path. The possibilities of previous path is more to reach destination there we continue from here in the code.
            if(vis[x][y]!=-1 && vis[x][y] >= t[3])
                continue;
            vis[x][y]=t[3];
            
            // push the adjacent node into queue
            q.push({x+1, y, t[2]+1, t[3]});
            q.push({x, y+1, t[2]+1, t[3]});
            q.push({x-1, y, t[2]+1, t[3]});
            q.push({x, y-1, t[2]+1, t[3]});
        }
        return -1;
    }
};
