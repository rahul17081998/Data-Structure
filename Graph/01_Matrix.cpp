/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
*/

class Solution {
    
    const int dirx[4]={1, 0, -1, 0};
    const int diry[4]={0, -1, 0, 1};
    
public:
    void bfs(vector<vector<int>> &mat, queue<pair<int,int>> &q)
    {
        // make a visited array
       
       
        int level=0;
        while(!q.empty())
        {
            int size = q.size();
            level++;
            while(size-->0)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
               
                // traverse in all 4 direction and search 
                for(int dir=0; dir<4; dir++)
                {
                    int nx = x + dirx[dir];
                    int ny = y + diry[dir];
                    // validate boundry
                    if(nx<0 || nx>=mat.size() || ny<0 || ny>=mat[0].size() || mat[nx][ny]!=-1)
                        continue;
                    
                    mat[nx][ny]=level;
                    q.push({nx,ny});
                    
                }
            }   
        }
        // end
    }
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // find cell with non zero
                if(mat[i][j]==0)
                    q.push({i,j});
                else
                    mat[i][j]=-1;
            }
        }
        
       bfs(mat, q);
        return mat;
           
    }
};
