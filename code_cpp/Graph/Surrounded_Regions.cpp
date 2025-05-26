/*
Given an m x n matrix board containing 'X' and 'O', capture all regions 
that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

*/

class Solution {
    const int dirx[4] = {1, 0, -1, 0};
    const int diry[4] = {0, -1, 0, 1};
public:
    void bfs(int i, int j, vector<vector<char>>& board)
    {
        int n=board.size();
        int m = board[0].size();
        
        // bfs
        board[i][j]='A';
        queue<vector<int>> q;
        q.push({i, j});
        
        while(!q.empty())
        {
            int x=q.front()[0];
            int y=q.front()[1];
            q.pop();
            
            // traverse in all 4 direction and find cell with 'O'
            for(int ind = 0; ind<4; ind++)
            {
                int nx = x + dirx[ind];
                int ny = y + diry[ind];
                // check boundry and cell value
                if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]=='O')
                {
                    q.push({nx, ny});
                    board[nx][ny]='A'; // mark as visited
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // if cell is zero 
                if(board[i][j]=='O')
                {
                    // if cell 'O' is connected with wall
                    if(i==0 || j==0 || i==n-1 || j==m-1) 
                    {
                        bfs(i, j, board);
                    }
                }
                    
            }
        }
       
        // convert all the 'O' into 'X' and all 'A' into 'O'
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                if(board[i][j]=='A')
                {
                    board[i][j]='O';
                }
            }
        }
        
        
        // end;
    }
};
