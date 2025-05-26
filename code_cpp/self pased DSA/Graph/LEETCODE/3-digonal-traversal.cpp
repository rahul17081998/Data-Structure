class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int dirx[] = {0,1};
        int diry[] = {1,0};
        int n = mat.size();
        int m = mat[0].size();
        // apply BFS
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        vector<vector<int>> res;
        vector<int> ans;
        queue<vector<int>> q;
        q.push({0, 0});
        vis[0][0]=1;
        
        bool flag=false;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            while(size-->0)
            {
                auto v = q.front();
                q.pop();
                
                int x = v[0], y = v[1];
                level.push_back(mat[x][y]);
                
                for(int i=0; i<2; i++)
                {
                    int nx = x + dirx[i];
                    int ny = y + diry[i];
                    // check if it is a valid 
                    if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                    }
                        
                }
            }
            if(flag==true){
                res.push_back(level);
                flag=false;
            }
            else{
                reverse(level.begin(), level.end());
                res.push_back(level);
                flag = true;
            }
        }
        
        for(auto v: res)
        {
            for(auto x: v){
                ans.push_back(x);
            }
        }
        return ans;
    }
};