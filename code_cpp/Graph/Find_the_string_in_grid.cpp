//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    
   
   const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
   const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
public:
    
    bool findWord(int i, int j, vector<vector<char>>grid, string &word, int n, int m)
    {
        // check if first char of word matching or not
        if(grid[i][j]!=word[0]) return false;
         
        // check all 8 directions
        for(int dir=0; dir<8; dir++)
        {
            int x=i + dx[dir];
            int y=j + dy[dir];
            
            int index;
            for(index=1; index<word.size(); index++)
            {
                // check boundry
                if(x<0 || x>=n || y<0 || y>=m || grid[x][y]!=word[index])
                    break;
                x = x + dx[dir];
                y = y + dy[dir];
            }
            if(index==word.size())
                return true;
        }
        return false;
        
    }
    /*
    // method 2: it is not giving correct ans but why is dont i looks good
    bool bfs(vector<vector<char>> grid, string word, int x, int y, int n, int m)
    {
        // check if 0th index matched
        if(grid[x][y]!=word[0]) return false;
        int index=1;
        queue<pair<int,int>> q;
        q.push({x,y});
        
        
        
        while(!q.empty())
        {
            // check all the character you have found or not
            if(index==word.size())
                return true;
                
            int size = q.size();
            bool flag=false; // if no element will added from one levele to next level
            
            while(size-- >0)
            {
                int x=q.front().first, y=q.front().second;
                q.pop();
                
                // traverse in all 8 directions
                for(int i=0; i<8; i++)
                {
                    int nx=x + dx[i], ny=y+dy[i];
                    // validate it's boundry
                    if(nx<0 || nx>=n || ny<0 || ny>=m)
                        continue;
                    // check current char is matching or not
                    if(word[index]==grid[nx][ny]){
                        flag=true;
                        q.push({nx, ny});
                    }
                }
            }
            // check wether any new char is added or not
            index++;
            if(flag==false)
                return false;
        }
        return false; // 
    }*/
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    // store ans
	    vector<vector<int>> ans;
	    
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            if(findWord(i, j, grid, word, n, m)) // method 1
	                ans.push_back({i, j});
	           // if(bfs(grid, word, i, j, n, m)) // method 2: it is not giving correct ans but why is dont i looks good
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}
// } Driver Code Ends
