class Solution {

public:
    
   
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int dirx[]={1, 0, -1, 0};
        int diry[]={0, 1, 0, -1};
        
        int n=grid.size();
        int m=grid[0].size();
        
        // Application dijkstra algorithm gives TLE but we resolve here 
       
        
        // use 1--> obstracle, 0--> free space as graph weight
        
        // initialize distance array with infinite
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        // create a dqueue
        deque<vector<int>>dq;
        dist[0][0]=0;
        dq.push_front({dist[0][0], 0, 0});
        
        while(!dq.empty())
        {
            auto v=dq.front();
            dq.pop_front();
            
            int x=v[1], y=v[2], currCost=v[0];
            
            // This line will remove the TLE
            // VVI: This is invalid path because we have achived better which already might be running in the queue
            if(currCost > dist[x][y])
                continue;
            
            // check in all 4 direction
            for(int i=0; i<4; i++)
            {
                int nx=x+dirx[i];
                int ny=y+diry[i];
                
                // check boundry 
                if(nx>=0 && nx<n && ny>=0 && ny<m)
                {
                    // check if 
                    if(dist[nx][ny] > grid[x][y] + currCost)
                    {
                        dist[nx][ny] = grid[x][y] + currCost;
                        if(grid[nx][ny]==1)
                            dq.push_back({dist[nx][ny], nx, ny});
                        else
                            dq.push_front({dist[nx][ny], nx, ny});
                    }
                }
            }
        }
        return dist[n-1][m-1];
        
    }
};
