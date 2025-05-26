//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    const int dx[4] = {0, 1, -1, 0};
    const int dy[4] = {1, 0, 0, -1};
public:
    // Mthod 1: DFS perfectally work
    bool DFS(vector<vector<char> > &board, string word, int x, int y, int index)
    {
        // check if you check all the alphabets of the word
        if(word.length()==index)
            return true;
        // check boundry not math or character not match
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]!=word[index])
            return false;
            
        // mark {x,y} cell visited
        board[x][y]='0';
        
        // check in next alphabet in all 4 directions
        bool status = DFS(board, word, x+1, y, index+1) 
                || DFS(board, word, x, y+1, index+1)
                || DFS(board, word, x-1, y, index+1)
                || DFS(board, word, x, y-1, index+1);
                
        // change the character back for other search
        board[x][y]=word[index];
        return status;
    }

    // method 2: it will give TLE
    bool bfs(vector<vector<char> > grid, string word, int x, int y, int n, int m)
    {
        // check if 0th index matched
        if(grid[x][y]!=word[0]) return false;
        // create a visited array
        vector<vector<int> > vis(n, vector<int>(m, 0));
        
        int index=1;
        queue<pair<int,int> > q;
        q.push(make_pair(x,y));
        // mark current cell is visted
        vis[x][y]=1;
        
        
        
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
                for(int i=0; i<4; i++)
                {
                    int nx=x + dx[i], ny=y+dy[i];
                    // validate it's boundry
                    if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny]==1)
                        continue;
                    // check current char is matching or not
                    if(word[index]==grid[nx][ny]){
                        flag=true;
                        q.push(make_pair(nx, ny));
                        vis[nx][ny]=1;
                    }
                }
            }
            // check wether any new char is added or not
            index++;
            if(flag==false)
                return false;
        }
        return false; // 
    }
    //
 
    
    bool isWordExist(vector<vector<char> >& board, string word) {
        // Code here
        
        int n=board.size();
	    int m=board[0].size();
	    
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	           
	           if(board[i][j]==word[0] && DFS(board, word, i, j, 0))
	                return true;
	                
	        }
	    }
	    // if you dont get a single time that word
	    return false;
    }
};

//{ Driver Code Starts.
int main(){
	
    int n, m;
    cin >> n >> m;
    vector<vector<char> >board(n, vector<char>(m, '*'));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    string word;
    cin >> word;
    Solution obj;
    bool ans = obj.isWordExist(board, word);
    if(ans)
        cout << "1\n";
    else cout << "0\n";

	return 0;
}
// } Driver Code Ends

/*
Example1: 
sample input
i/p:                    o/p: 0
    3 4 
    a b c e
    s f c s
    a d e e
    sabfs

Example 2:
i/p:                    o.p: 1
    3 4 
    a g b c 
    q e e l 
    g b k s 
    geeks
*/