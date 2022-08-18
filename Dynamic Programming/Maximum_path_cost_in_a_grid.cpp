class Solution {
public:
    // Method 2: Dijkstra Algorithm or Multisource BFS
    int minPathSumCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost)
    {
        
        // create a minimum heap priority queue
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
       
        int m = grid.size();
        int n = grid[0].size();
        // create a cost vector 
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        // insert first row value and there coordinate into queue
        // pq< grid[x][y], x, y> where x =0
        for(int j=0; j<n; j++)
            pq.push({grid[0][j], 0, j});
        
        while(!pq.empty())
        {
            int costTillNow = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            // check if you reach the last row
            if(x==m-1)
                return costTillNow;
            
            for(int dy=0; x+1< m && dy<n; dy++)
            {
                int newCost = costTillNow + moveCost[grid[x][y]][dy] + grid[x+1][dy];
                
                if(newCost < cost[x+1][dy])
                {
                    cost[x+1][dy] = newCost;
                    pq.push({newCost, x+1, dy});
                }
               
            }
           
        }
        
        return -1;
        
    }
    
    
    
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        // Method 2: Dijkstra Algorithm or Multisource BFS
         return minPathSumCost(grid, moveCost);
        
        /*
        // Method 1: Dp
        // time = O(M*N*N)
        
        int m=grid.size(); // row
        int n=grid[0].size(); // col
        // create a cost vector
        int cost[m][n];
        // initially 0th row cost will be same as grid value
        // set cost for 0th row
        for(int i=0; i<n; i++)
            cost[0][i]=grid[0][i];
        
        // set cost for 1 to m-1th row
        for(int r=1; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                int CFPR = INT_MAX; // cost From Previous Row
                for(int j=0; j<n; j++)
                {
                    CFPR = min(CFPR, cost[r-1][j] + moveCost[grid[r-1][j]][c]);
                }
                
                cost[r][c] = grid[r][c] + CFPR;
            }
        }

        // return minimum cost value from last cost vector row
        int minSumPath=INT_MAX;
        for(int i=0; i<n; i++){
            minSumPath = min(minSumPath, cost[m-1][i]);
        }
        return minSumPath;
        */
    }
};
