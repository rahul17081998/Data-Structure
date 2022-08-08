/*
GFG question Link:https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1?page=1&status[]=unsolved&category[]=Graph&category[]=DFS&category[]=BFS&sortBy=submissions
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    const int dirx[4]={1, 0, 0, -1};
    const int diry[4]={0, 1, -1, 0};
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0)
            return -1;
       
        // BFS
        vector<vector<int>> vis(N, vector<int>(M,0));
        
        queue<vector<int>> q;
        q.push({0, 0});
        int level=0;
        
        
        while(!q.empty())
        {
            int size = q.size();
            while(size-- >0)
            {
                int x=q.front()[0];
                int y=q.front()[1];
                q.pop();
                
                if(x==X && y==Y)
                    return level;
                
                if(vis[x][y])
                    continue;
                // traverse in all 4 direction
                for(int i=0; i<4; i++)
                {
                    int nx=x+dirx[i];
                    int ny=y+diry[i];
                    
                    // verify the boundry and path
                    if(nx>=0 && nx<N && ny>=0 && ny<M && A[nx][ny]==1)
                    {
                        q.push({nx, ny});
                    }
                }
                vis[x][y]=1; // mark visited
            }
            level++;
            
        }
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends

